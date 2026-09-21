#include "CustomCommand.h"
#include <iostream>
#include <stdio.h>



CustomCommand::CustomCommand(const std::string &command){
_command=command;
}

void CustomCommand::Processing() {
     // not best approch , will be refactored
     std::system(_command.c_str());

}

