#pragma once

#include "CommandBase.h"

class EchoCommand : public CommandBase {
public:
    EchoCommand(const std::string& command);
    void Processing() override;
};