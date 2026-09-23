#include "TypeCommand.h"
#include <cstdlib>
#include <iostream>


void TypeCommand::Processing(const std::vector<std::string> &args) {
       std::string output = args[1];

    if (IsSupportedCommand(args[1]))
        output += " is a shell builtin";
    else {
        std::string fileDir;

        if (IsAnExecutable(getenv("PATH"), args[1], fileDir))
            output += " is " + fileDir;
        else
            output += ": not found";
    }
    std::cout<<output<<"\n";
}