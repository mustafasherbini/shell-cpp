#include "CustomCommand.h"
#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <tchar.h>



CustomCommand::CustomCommand(std::string command){
_command=command;
}

void CustomCommand::Processing() {
     // not best approch , will be refactored
     std::system(_command.c_str());

}

