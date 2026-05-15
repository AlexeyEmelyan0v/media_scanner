cmake_minimum_required(VERSION 3.16)
project(media_scanner)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(media_scanner
    src/main.cpp
    src/scanner_config.cpp
    src/media_scanner.cpp
    src/json_writer.cpp
)
