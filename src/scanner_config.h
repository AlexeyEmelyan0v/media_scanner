#include <filesystem>

class ScannerConfig {
   public:
    std::filesystem::path root;
    int interval;  // в секундах

    ScannerConfig(int argc, char* argv[]);

   private:
    static std::filesystem::path GetHome();
    static int ParseInterval(const char* value);
};