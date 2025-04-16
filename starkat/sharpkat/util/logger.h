#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <format> // or use <fmt/core.h> if using the fmtlib directly

namespace cs {
    enum class LogLevel {
        INFO,
        WARN,
        ERR
    };

    class Logger {
    public:
        static void Init();

        static void Log(LogLevel level, const std::string &message);

        static void Info(const std::string &message);
        static void Warn(const std::string &message);
        static void Error(const std::string &message);

        template<typename... Args>
        static void Info(std::format_string<Args...> fmt, Args&&... args) {
            Info(std::format(fmt, std::forward<Args>(args)...));
        }

        template<typename... Args>
        static void Warn(std::format_string<Args...> fmt, Args&&... args) {
            Warn(std::format(fmt, std::forward<Args>(args)...));
        }

        template<typename... Args>
        static void Error(std::format_string<Args...> fmt, Args&&... args) {
            Error(std::format(fmt, std::forward<Args>(args)...));
        }

    private:
        static bool use_colors;
        static bool IsRunningUnderWine();
    };
} // cs

#endif // LOGGER_H
