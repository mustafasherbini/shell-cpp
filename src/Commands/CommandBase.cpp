#include "CommandBase.h"
#include <iostream>
#include <memory>
#include <filesystem>
#include <sstream>

namespace fs = std::filesystem;

bool CommandBase::IsSupportedCommand(const std::string& commandName) {
    return commandName == "echo" || commandName == "type" ||
           commandName == "exit" || commandName == "pwd" || commandName=="cd";
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
 std::string CommandBase::GetCurrentWorkingDirectory() {

    return std::filesystem::current_path().string();
}
