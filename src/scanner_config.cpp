#include "scanner_config.h"

#include <cstdlib>
#include <stdexcept>
#include <string>

std::filesystem::path ScannerConfig::GetHome() {
    const char* home = std::getenv("HOME");

    if (home == nullptr || std::string(home).empty()) {
        throw std::runtime_error("HOME не задан");
    }

    return std::filesystem::path(home);
}

int ScannerConfig::ParseInterval(const char* value) {
    int interval = std::stoi(value);

    if (interval <= 0) {
        throw std::runtime_error("Интервал должен быть положительным");
    }

    return interval;
}

ScannerConfig::ScannerConfig(int argc, char* argv[]) : root(GetHome()), interval(10) {
    if (argc > 3) {
        throw std::runtime_error("Слишком много аргументов");
    }

    if (argc >= 2) {
        root = argv[1];
    }

    if (argc >= 3) {
        interval = ParseInterval(argv[2]);
    }

    if (!std::filesystem::exists(root)) {
        throw std::runtime_error("Не существует такой директории");
    }

    if (!std::filesystem::is_directory(root)) {
        throw std::runtime_error("Указанный путь не является директорией");
    }
}
