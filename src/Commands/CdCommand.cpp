#include "CdCommand.h"
#include <filesystem>
namespace fs = std::filesystem;

CdCommand::CdCommand(const std::string& command) {
    _command=command.substr(3);
}

void CdCommand::Processing() {

    if (_command =="'~'")
        fs::current_path(getenv("HOME"));
    else if (fs::exists(_command) && fs::is_directory(_command))
        fs::current_path(_command);
    else
        _msg=_command+": No such file or directory";
}
