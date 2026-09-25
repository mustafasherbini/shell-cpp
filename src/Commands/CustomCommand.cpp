#include "CustomCommand.h"
#include <iostream>
#include <stdio.h>


void CustomCommand::Processing(const std::vector<std::string> &args) {
     // not best approch , will be refactored
     std ::string fileDir, command;

     for (int i = 0; i < args.size(); ++i) {
          command+=args[i];
          if (i+1!=args.size())
               command+='/';
     }
     if (CommandBase::IsAnExecutable(getenv("PATH"), command, fileDir)) {
     std::system(command.c_str());
     } else std::cout << command << ": command not found" << std::endl;


}

