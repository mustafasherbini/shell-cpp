#include <iostream>
#include <string>
#include "CommandHandler.cpp"

class Prompet {

public:
    static void run() {

        while (true) {

            std::cout << "$ ";
            std :: string command;

            getline(std :: cin, command);

            auto response= CommandHandler::Processing(command);

            if (response==Exit)
                break;

        }

    }

};
