#pragma once
#include <string>
#include "CommandBase.h"
#include <filesystem>
namespace fs = std::filesystem;

class CatCommand : public CommandBase{
public:
    void Processing(const std::vector<std::string> &args) override;
};

