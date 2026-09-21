
#pragma once

#include <filesystem>
#include <string>
#include <vector>

class CommandBase {
public:
    virtual ~CommandBase() = default;
    virtual void Processing() = 0;

    std::string GetLoggedMessage();
    bool HasLoggedMessage();

    static bool IsSupportedCommand(const std::string& commandName);
    static bool IsAnExecutable(const std::string& pathString,
                               const std::string& fileName,
                               std::string& fileDir);
    static std::string GetCommandName(const std::string& command);
    static std::vector<std::string> GetCommandArgs(const std::string& command);
    static std::string GetCurrentWorkingDirectory();

protected:
    std::string _command, _msg;
    static std::string _currentWorkingDirectory ;
};