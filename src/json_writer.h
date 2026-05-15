#include <filesystem>
#include <fstream>
#include <string>
#include <vector>

#include "media_scanner.h"

class JsonWriter {
   public:
    void Write(const MediaFiles& files, const std::filesystem::path& path) const;

   private:
    static void WriteVector(std::ofstream& output, const std::string& name,
                            const std::vector<std::string>& values);
};