#pragma once

#include "CommandBase.h"

class TypeCommand : public CommandBase {
public:
    TypeCommand(const std::string& command);
    void Processing() override;
};