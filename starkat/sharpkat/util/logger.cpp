#include "logger.h"
#include <iostream>
#include <math.h>
#include <valarray>
#include <windows.h>

namespace cs {
    bool Logger::use_colors = false;

    void Logger::Init() {
        use_colors = !IsRunningUnderWine();

        AllocConsole();

        freopen("CONOUT$", "w", stdout);
        freopen("CONOUT$", "w", stderr);
        freopen("CONIN$", "r", stdin);

        HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleMode(out, ENABLE_VIRTUAL_TERMINAL_PROCESSING | ENABLE_PROCESSED_OUTPUT | ENABLE_WRAP_AT_EOL_OUTPUT);
    }

    bool Logger::IsRunningUnderWine() {
        HKEY hKey;
        if (RegOpenKeyExA(HKEY_CURRENT_USER, "Software\\Wine", 0, KEY_READ, &hKey) == ERROR_SUCCESS) {
            RegCloseKey(hKey);
            return true;
        }

        return false;
    }

    void Logger::Log(LogLevel level, const std::string &message) {
        if (use_colors) {
            switch (level) {
                case LogLevel::INFO:
                    std::cout << "\033[32m[INFO]\033[0m " << message << std::endl;
                    break;
                case LogLevel::WARN:
                    std::cout << "\033[33m[WARN]\033[0m " << message << std::endl;
                    break;
                case LogLevel::ERR:
                    std::cout << "\033[31m[ERROR]\033[0m " << message << std::endl;
                    break;
            }
        } else {
            switch (level) {
                case LogLevel::INFO:
                    std::cout << "[INFO] " << message << std::endl;
                    break;
                case LogLevel::WARN:
                    std::cout << "[WARN] " << message << std::endl;
                    break;
                case LogLevel::ERR:
                    std::cout << "[ERROR] " << message << std::endl;
                    break;
            }
        }
    }

    void Logger::Info(const std::string &message) {
        Log(LogLevel::INFO, message);
    }

    void Logger::Warn(const std::string &message) {
        Log(LogLevel::WARN, message);
    }

    void Logger::Error(const std::string &message) {
        Log(LogLevel::ERR, message);
    }

} // cs
