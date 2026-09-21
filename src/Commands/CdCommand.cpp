#include "CdCommand.h"
#include <filesystem>
namespace fs = std::filesystem;

CdCommand::CdCommand(const std::string& command) {
    _command=command.substr(3);
}

void CdCommand::Processing() {
    _msg+=_command;

    if (fs::exists(_command) && fs::is_directory(_command)) {
        fs::current_path(_command);
    }else
        _msg+=": No such file or directory";
}
