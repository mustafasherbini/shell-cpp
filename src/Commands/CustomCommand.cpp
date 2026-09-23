#include "CustomCommand.h"
#include <iostream>
#include <stdio.h>


void CustomCommand::Processing(const std::vector<std::string> &args) {
     // not best approch , will be refactored
     std ::string fileDir;
     if (CommandBase::IsAnExecutable(getenv("PATH"), args[0], fileDir)) {
     std::system(args[0].c_str());
     } else std::cout << args[0] << ": command not found" << std::endl;


}

