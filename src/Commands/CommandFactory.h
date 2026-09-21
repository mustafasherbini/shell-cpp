#pragma once

#include "CommandBase.h"
#include <memory>
#include <string>

class CommandFactory {
public:
    static std::unique_ptr<CommandBase> GetCommand(const std::string& command);
};