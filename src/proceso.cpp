#include "proceso.hpp"

#include <fcntl.h>
#include <sys/resource.h>
#include <sys/wait.h>
#include <unistd.h>

#include <cerrno>
#include <chrono>

std::vector<std::string> expandir(
    const std::vector<std::string>& plantilla,
    const std::map<std::string, std::string>& valores) {
    std::vector<std::string> argv;
    for (const auto& arg : plantilla) {
        const bool es_marcador =
            arg.size() > 2 && arg.compare(0, 1, "{") == 0 &&
            arg.compare(arg.size() - 1, 1, "}") == 0 &&
            arg.substr(1, arg.size() - 2).find_first_not_of(
                "ABCDEFGHIJKLMNOPQRSTUVWXYZ_") == std::string::npos;
        if (!es_marcador) {
            argv.push_back(arg);
            continue;
        }
        const auto it = valores.find(arg);
        if (it == valores.end()) return {};
        argv.push_back(it->second);
    }
    return argv;
}

bool comandoListo(
    const std::vector<std::string>& plantilla,
    std::string& pendiente) {
    for (const auto& arg : plantilla) {
        if (!arg.empty() && arg.find('<') != std::string::npos) {
            pendiente = arg;
            return false;
        }
    }
    return !plantilla.empty();
}

ResultadoProceso ejecutar(
    const std::vector<std::string>& args,
    const std::string& archivo_diagnostico,
    bool capturar_stdout) {
    ResultadoProceso r;
    if (args.empty()) return r;

    int tubo[2] = {-1, -1};
    if (capturar_stdout && pipe(tubo) != 0) return r;

    const auto inicio = std::chrono::steady_clock::now();
    const pid_t pid = fork();

    if (pid < 0) {
        if (capturar_stdout) {
            close(tubo[0]);
            close(tubo[1]);
        }
        return r;
    }

    if (pid == 0) {
        const int nulo = open("/dev/null", O_RDONLY);
        if (nulo >= 0) {
            dup2(nulo, STDIN_FILENO);
            close(nulo);
        }

        if (!archivo_diagnostico.empty()) {
            const int diag = open(
                archivo_diagnostico.c_str(),
                O_WRONLY | O_CREAT | O_TRUNC, 0600);
            if (diag >= 0) {
                dup2(diag, STDERR_FILENO);
                if (!capturar_stdout) dup2(diag, STDOUT_FILENO);
                close(diag);
            }
        }

        if (capturar_stdout) {
            dup2(tubo[1], STDOUT_FILENO);
            close(tubo[0]);
            close(tubo[1]);
        }

        std::vector<char*> c;
        for (const auto& a : args)
            c.push_back(const_cast<char*>(a.c_str()));
        c.push_back(nullptr);

        execvp(c[0], c.data());
        _exit(127);
    }

    r.lanzado = true;

    if (capturar_stdout) {
        close(tubo[1]);
        char buf[4096];
        while (true) {
            const ssize_t n = read(tubo[0], buf, sizeof buf);
            if (n > 0) {
                r.salida.append(buf, static_cast<std::size_t>(n));
                continue;
            }
            if (n < 0 && errno == EINTR) continue;
            break;
        }
        close(tubo[0]);
    }

    int estado = 0;
    struct rusage uso {};
    while (wait4(pid, &estado, 0, &uso) < 0 && errno == EINTR) {}

    r.duracion_ms =
        std::chrono::duration_cast<std::chrono::milliseconds>(
            std::chrono::steady_clock::now() - inicio).count();
    r.memoria_pico_kb = uso.ru_maxrss;

    if (WIFEXITED(estado))
        r.codigo_salida = WEXITSTATUS(estado);
    else if (WIFSIGNALED(estado))
        r.codigo_salida = 128 + WTERMSIG(estado);

    return r;
}
