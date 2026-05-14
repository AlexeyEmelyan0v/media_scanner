#include <iostream>

#include "scanner_config.h"

int main(int argc, char* argv[]) {
    try {
        ScannerConfig config(argc, argv);
        std::cout << "Корневой каталог: " << config.root << '\n';
        std::cout << "Интервал: " << config.interval << " сек.\n";
    } catch (const std::exception& error) {
        std::cerr << "Ошибка: " << error.what() << '\n';
        return 1;
    }

    return 0;
}