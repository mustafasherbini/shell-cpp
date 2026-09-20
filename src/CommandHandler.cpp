#include <string>
#include <iostream>
#include <memory>
#include <filesystem>
namespace fs = std::filesystem;

class Command {
public:
    virtual ~Command() = default;
    virtual void Processing()=0;
    std :: string GetLoggedMessage() {
        return _msg;
    }
    bool HasLoggedMEssage() {
        return !_msg.empty();
    }
protected:
    std::string _command,_msg;
};

class EchoCommand : public Command {
public:
    EchoCommand(const std::string& command) {
        _command=command.substr(5);
    }
     void Processing() override {
        std::cout << _command<<std::endl;
    }

};

class TypeCommand : public Command {
    void SearchForCommand( std:: string pathString) {
        std::istringstream iss(pathString);
        std::string dir;

        while (std::getline(iss, dir, ':')) {
            if (dir.empty()) continue;
            auto filePath=dir+'/'+_command;
            if (fs::exists(filePath) && fs::is_regular_file(filePath)) {

                auto perms = fs::status(filePath).permissions();

                if ((perms & fs::perms::owner_exec)  != fs::perms::none) {
                    _msg += " is" + filePath;
                    return;
                }

            }
        }
        _msg+= ": not found";

    }


public:

    TypeCommand(const std::string& command) {
        _command=command.substr(5);
    }
     void Processing () override {
        _msg=_command;
        if (_command == "echo" || _command == "type" || _command=="exit")
            _msg+=" is a shell builtin";
        else
            SearchForCommand(getenv("PATH"));
    }

};

class CommandFactory {
public:
  static std::unique_ptr<Command> GetCommand(const std::string& command) {

        if (command.starts_with("echo "))
            return std::make_unique<EchoCommand>(command);

        if (command.starts_with("type "))
            return std::make_unique<TypeCommand>(command);

        return nullptr;
    }
};

