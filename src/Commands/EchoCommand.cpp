#include "EchoCommand.h"
#include <iostream>

EchoCommand::EchoCommand(const std::string& command) {
    _command = command.substr(5);
}

void EchoCommand::Processing() {
    std::cout << _command << std::endl;
}