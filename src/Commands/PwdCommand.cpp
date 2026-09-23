#include "PwdCommand.h"
#include <iostream>

void PwdCommand::Processing(const std::vector<std::string> &args) {
   std:: cout<< GetCurrentWorkingDirectory()<<"\n";
}
