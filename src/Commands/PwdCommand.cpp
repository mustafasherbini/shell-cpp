#include "PwdCommand.h"
#include <filesystem>

namespace fs = std::filesystem;

void PwdCommand::Processing() {
    fs::path currentPath = fs::current_path();
    _msg=currentPath.string();
}
