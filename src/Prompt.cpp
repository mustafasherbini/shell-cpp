#include <iostream>
#include <string>

#include "PromptHelpers.h"
#include "Commands/CommandFactory.h"

class Prompt {

public:
     static void run() {

        while (true) {

            std::cout << "$ ";
            std :: string input;

            getline(std :: cin, input);

            auto args=PromptHelpers::InputParsing(input);

            if (input == "exit")
                break;

            auto commandObject=
                CommandFactory::GetCommand(args);

            if (commandObject!=nullptr)
                commandObject->Processing(args);
            else std::cout << input << ": command not found" << std::endl;



        }

    }

};
