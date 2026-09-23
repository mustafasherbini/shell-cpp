
#pragma once

#include <filesystem>
#include <string>
#include <vector>

class CommandBase {
public:
    virtual ~CommandBase() = default;
    virtual void Processing(const std::vector<std::string> &args) = 0;
    static bool IsSupportedCommand(const std::string& commandName);
    static bool IsAnExecutable(const std::string& pathString,
                               const std::string& fileName,
                               std::string& fileDir);
    static std::vector<std::string> GetCommandArgs(const std::string& command);
    static std::string GetCurrentWorkingDirectory();
};