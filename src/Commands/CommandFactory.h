#pragma once

#include "CommandBase.h"
#include <memory>
#include <string>

#include "EchoCommand.h"

class CommandFactory {
public:
    static std::unique_ptr<CommandBase> GetCommand(const std::vector<std::string> &args);
};
