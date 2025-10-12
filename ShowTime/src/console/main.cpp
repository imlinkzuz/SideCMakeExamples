#include <spdlog/spdlog.h>
#include <sample/libtime/my_time.h>
#include <ShowTime/config.hpp>
int main(int argc, char *argv[])
{
    for (int i = 1; i < argc; ++i)
    {
        if (strcmp(argv[i],"--version")==0 || strcmp(argv[i],"-v")==0) {
            spdlog::info("{}", ShowTime::PROJECT_VERSION);
            return 0;
        }
        if (strcmp(argv[i],"--help")==0 || strcmp(argv[i],"-h")==0) {
            spdlog::info("Usage: ShowTime [options]");
            spdlog::info("Options:");
            spdlog::info("  -h, --help       Show this help message and exit");
            spdlog::info("  -v, --version    Show version information and exit");
            return 0;
        }
    }
    sample::MyTime myTime;
    spdlog::info("Project Name: {}", ShowTime::PROJECT_NAME);
    spdlog::info("Project Version: {}", ShowTime::PROJECT_VERSION);
    spdlog::info("Current Time is : {}", myTime.now());
    return 0;
}