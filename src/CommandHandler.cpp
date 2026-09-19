#include <string>
#include <iostream>

enum status {
    Exit,
    Done,
    NotFound
};
class CommandHandler {

public:
    static status Processing(const std::string& command) {

        if (command=="exit")
            return Exit;

         if (command.starts_with("echo"))
             return EchoProcessing(command);

        std::cout << command << ": command not found" << std::endl;
        return NotFound;
    }

    static status EchoProcessing(const std::string& command) {
     std::cout << command.substr(5);
        return Done;
    }


};