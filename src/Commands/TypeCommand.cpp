#include "TypeCommand.h"
#include <cstdlib>

TypeCommand::TypeCommand(const std::string& command) {
    _command = command.substr(5);
}

void TypeCommand::Processing() {
    _msg = _command;

    if (IsSupportedCommand(GetCommandName(_command)))
        _msg += " is a shell builtin";
    else {
        std::string fileDir;

        if (IsAnExecutable(getenv("PATH"), GetCommandName(_command), fileDir))
            _msg += " is " + fileDir;
        else
            _msg += ": not found";
    }
}