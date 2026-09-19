#include <iostream>
#include <string>

int main() {
  std::cout << std::unitbuf;
  std::cerr << std::unitbuf;

    while (true) {

        std::cout << "$ ";
        std :: string command;
        getline(std :: cin, command);
        if (command.starts_with("exit"))
            break;
        std :: cout<<command <<": command not found\r\n";

    }

}
