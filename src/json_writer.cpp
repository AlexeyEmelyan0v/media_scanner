#include "json_writer.h"

#include <stdexcept>

void JsonWriter::WriteVector(std::ofstream& output, const std::string& name,
                             const std::vector<std::string>& values) {
    output << "    \"" << name << "\": [";

    for (size_t i = 0; i < values.size(); ++i) {
        if (i > 0) {
            output << ", ";
        }

        output << "\"" << values[i] << "\"";
    }

    output << "]";
}

void JsonWriter::Write(const MediaFiles& files, const std::filesystem::path& path) const {
    std::ofstream output(path);

    if (!output.is_open()) {
        throw std::runtime_error("Не удалось открыть файл");
    }

    output << "{\n";
    WriteVector(output, "audio", files.audio);
    output << ",\n";
    WriteVector(output, "video", files.video);
    output << ",\n";
    WriteVector(output, "image", files.images);
    output << "\n}\n";
}
