#include <iostream>
#include <string>
#include "CommandHandler.cpp"

int main() {
  std::cout << std::unitbuf;
  std::cerr << std::unitbuf;


    while (true) {

        std::cout << "$ ";
        std :: string command;

        getline(std :: cin, command);

       auto response= CommandHandler::Processing(command);

        if (response==NotFound)
            std::cout << command << ": command not found" << std::endl;

        if (response==Exit)
            break;


    }

}
