
#pragma once
#include "CommandBase.h"
#include <iostream>

class CustomCommand : public CommandBase {
private:

public:
    CustomCommand(std::string command);
    void Processing() override;
};
