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
    status Processing(const std::string& command) {

        if (command.starts_with("exit"))
            return Exit;

        return NotFound;
    }
};
int main() {
  std::cout << std::unitbuf;
  std::cerr << std::unitbuf;

  CommandHandler _commandHandler;

    while (true) {

        std::cout << "$ ";
        std :: string command;

        getline(std :: cin, command);

       auto response= _commandHandler.Processing(command);

        if (response==Exit)
            break;

         if (response==NotFound)
            std::cout << command << ": command not found" << std::endl;

    }

}
