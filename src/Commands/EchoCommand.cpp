#include "EchoCommand.h"
#include <iostream>


void EchoCommand::Processing(const std::vector<std::string> &args) {
    for (int i=1; i<args.size() ; i++) {
        std :: cout<<args[i]<<" ";
    }
    std ::cout<<"\n";

}
