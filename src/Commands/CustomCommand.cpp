#include "CustomCommand.h"
#include <iostream>
#include <stdio.h>


void CustomCommand::Processing(const std::vector<std::string> &args) {
     // not best approch , will be refactored
     std::system(args[0].c_str());

}

