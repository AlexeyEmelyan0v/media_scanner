#include <filesystem>
#include <string>
#include <vector>

struct MediaFiles {
    std::vector<std::string> audio;
    std::vector<std::string> video;
    std::vector<std::string> images;
};

class MediaScanner {
    MediaFiles Scan(const std::filesystem::path& root) const;

   private:
    static bool IsAudio(const std::filesystem::path& path);
    static bool IsVideo(const std::filesystem::path& path);
    static bool IsImage(const std::filesystem::path& path);
    static bool HasExtension(const std::filesystem::path& path,
                             const std::vector<std::string>& extensions);
};
