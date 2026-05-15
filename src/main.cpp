#include <chrono>
#include <exception>
#include <filesystem>
#include <iostream>
#include <thread>

#include "json_writer.h"
#include "scanner_config.h"

int main(int argc, char* argv[]) {
    try {
        ScannerConfig config(argc, argv);
        MediaScanner scanner;
        JsonWriter writer;
        const std::filesystem::path output_path = config.root / ".media_files";

        std::cout << "Сканируемая директория: " << config.root << '\n';
        std::cout << "Интервал: " << config.interval << " сек\n";

        while (true) {
            MediaFiles files = scanner.Scan(config.root);
            writer.Write(files, output_path);

            std::cout << "Обновлено: " << " audio: " << files.audio.size()
                      << ", video: " << files.video.size() << ", images: " << files.images.size()
                      << '\n';

            std::this_thread::sleep_for(std::chrono::seconds(config.interval));
        }
    } catch (const std::exception& error) {
        std::cerr << "Ошибка: " << error.what() << '\n';
        return 1;
    }

    return 0;
}