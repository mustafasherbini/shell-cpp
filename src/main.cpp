#include <iostream>
#include <string>
enum Commands {
    ExitCommand
};
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

        return NotFound;
    }

};
int main() {
  std::cout << std::unitbuf;
  std::cerr << std::unitbuf;


    while (true) {

        std::cout << "$ ";
        std :: string command;

        getline(std :: cin, command);

       auto response= CommandHandler::Processing(command);

        if (response==Exit)
            break;

         if (response==NotFound)
            std::cout << command << ": command not found" << std::endl;

    }

}
