#include "media_scanner.h"

#include <algorithm>

bool MediaScanner::HasExtension(const std::filesystem::path& path,
                                const std::vector<std::string>& extensions) {
    const std::string extension = path.extension().string();
    return (std::find(extensions.begin(), extensions.end(), extension) != extensions.end());
}

bool MediaScanner::IsAudio(const std::filesystem::path& path) {
    static const std::vector<std::string> extensions = {".mp3", ".wav", ".flac",
                                                        ".ogg", ".aac", ".m4a"};
    return HasExtension(path, extensions);
}

bool MediaScanner::IsVideo(const std::filesystem::path& path) {
    static const std::vector<std::string> extensions = {".mp4", ".avi",  ".mkv", ".mov",
                                                        ".mpg", ".mpeg", ".webm"};
    return HasExtension(path, extensions);
}

bool MediaScanner::IsImage(const std::filesystem::path& path) {
    static const std::vector<std::string> extensions = {".jpg", ".jpeg", ".png", ".gif",
                                                        ".bmp", ".webp", ".tiff"};
    return HasExtension(path, extensions);
}

MediaFiles MediaScanner::Scan(const std::filesystem::path& root) const {
    MediaFiles files;
    const auto options = std::filesystem::directory_options::skip_permission_denied;

    for (const auto& entry : std::filesystem::recursive_directory_iterator(root, options)) {
        if (!entry.is_regular_file()) {
            continue;
        }

        const std::filesystem::path path = entry.path();
        const std::string file_name = path.filename().string();

        if (IsAudio(path)) {
            files.audio.push_back(file_name);
        } else if (IsVideo(path)) {
            files.video.push_back(file_name);
        } else if (IsImage(path)) {
            files.images.push_back(file_name);
        }
    }

    return files;
}
