
#pragma once
#include "CommandBase.h"
#include <iostream>

class CustomCommand : public CommandBase {

public:
    CustomCommand(const std::string &command);
    void Processing() override;
};
