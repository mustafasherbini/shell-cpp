#pragma once

#include "CommandBase.h"

class TypeCommand : public CommandBase {
public:
    void Processing(const std::vector<std::string> &args) override;
};