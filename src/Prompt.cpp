#include <iostream>
#include <string>
#include "Commands/CommandFactory.h"

class Prompt {

public:
     static void run() {

        while (true) {

            std::cout << "$ ";
            std :: string command;

            getline(std :: cin, command);

            if (command == "exit")
                break;

            auto commandObject=
                CommandFactory::GetCommand(command);

            if (commandObject!=nullptr) {
                commandObject->Processing();
                if (commandObject->HasLoggedMessage())
                    std:: cout<<commandObject->GetLoggedMessage() << std::endl;
            }
            else std::cout << command << ": command not found" << std::endl;



        }

    }

};
