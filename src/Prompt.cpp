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

            if (input == "exit")
                break;

            auto args=PromptHelpers::InputParsing(input);

            auto commandObject=
                CommandFactory::GetCommand(args);
                commandObject->Processing(args);
        }

    }

};
