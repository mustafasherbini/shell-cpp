#include "CommandBase.h"
#pragma once


class PwdCommand : public CommandBase{
public:
    void Processing(const std::vector<std::string> &args) override;
};

