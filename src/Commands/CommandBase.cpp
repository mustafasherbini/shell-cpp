#include "CommandBase.h"
#include <iostream>
#include <memory>
#include <filesystem>
#include <sstream>

namespace fs = std::filesystem;

std::string CommandBase::GetLoggedMessage() {
    return _msg;
}

bool CommandBase::HasLoggedMessage() {
    return !_msg.empty();
}

bool CommandBase::IsSupportedCommand(const std::string& commandName) {
    return commandName == "echo" || commandName == "type" ||
           commandName == "exit" || commandName == "pwd";
}

bool CommandBase::IsAnExecutable(const std::string& pathString,
                                 const std::string& fileName,
                                 std::string& fileDir) {
    std::istringstream iss(pathString);
    std::string dir;

    while (std::getline(iss, dir, ':')) {
        if (dir.empty()) continue;

        auto filePath = dir + '/' + fileName;

        if (fs::exists(filePath) && fs::is_regular_file(filePath)) {
            auto perms = fs::status(filePath).permissions();

            if ((perms & fs::perms::owner_exec) != fs::perms::none) {
                fileDir = filePath;
                return true;
            }
        }
    }

    return false;
}

std::string CommandBase::GetCommandName(const std::string& command) {
    size_t spacePos = command.find_first_of(' ');

    if (spacePos == std::string::npos)
        return command;

    return command.substr(0, spacePos);
}

std::vector<std::string> CommandBase::GetCommandArgs(const std::string& command) {
    std::istringstream iss(command);

    std::string program;
    std::vector<std::string> args;

    iss >> program;

    std::string arg;
    while (iss >> arg) {
        args.push_back(arg);
    }

    return args;
}