#include "CustomCommand.h"
#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

void CustomCommand::Processing(const std::vector<std::string> &args) {
     // not best approch , will be refactored
     std ::string fileDir, command;
     std::vector<char*> argv;

    for (auto& arg : args) {
    argv.push_back(const_cast<char*>(arg.c_str()));
    }

    argv.push_back(nullptr);

     if (CommandBase::IsAnExecutable(getenv("PATH"), args[0], fileDir)) {
         pid_t pid = fork();

         if (pid == 0) {
             execv(fileDir.c_str(), argv.data());

             perror("execv");
             exit(1);
         }
         else {
             waitpid(pid, nullptr, 0);
         }
     }
      else std::cout << command << ": command not found" << std::endl;


}

