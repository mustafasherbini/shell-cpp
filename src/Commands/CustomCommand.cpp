#include "CustomCommand.h"
#include <iostream>
#include <stdio.h>


void CustomCommand::Processing(const std::vector<std::string> &args) {
     // not best approch , will be refactored
     std ::string fileDir, command;
     std::vector<char*> argv;

    for (auto& arg : args) {
    argv.push_back(const_cast<char*>(arg.c_str()));
    }

    argv.push_back(nullptr);

     if (CommandBase::IsAnExecutable(getenv("PATH"), args[0], fileDir))
        execv(fileDir.c_str(), argv.data());
      else std::cout << command << ": command not found" << std::endl;


}

