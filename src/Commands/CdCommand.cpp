#include "CdCommand.h"
#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

void CdCommand::Processing(const std::vector<std::string> &args) {
    auto argument=args[1];

    if (argument =="~")
        fs::current_path(getenv("HOME"));
    else if (fs::exists(argument) && fs::is_directory(argument))
        fs::current_path(argument);
    else
        std::cout<<argument+": No such file or directory";
}
