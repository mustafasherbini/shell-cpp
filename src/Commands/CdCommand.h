#pragma once

#include "CommandBase.h"

class CdCommand : public CommandBase{
public:
    CdCommand(const std::string& command);
    void Processing() override;
};


