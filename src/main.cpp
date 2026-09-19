#include <iostream>
#include <string>
enum Commands {
    ExitCommand=0
};
enum status {
    Exit,
    Erorr
};
class CommandHandler {

public:
    status Processing(std::string command) {

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
        if (command.starts_with("exit"))
            break;
        std :: cout<<command <<": command not found\r\n";

    }

}
