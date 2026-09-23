
#pragma once
#include "CommandBase.h"
#include <iostream>

class CustomCommand : public CommandBase {

public:
    void Processing(const std::vector<std::string> &args) override;
};
