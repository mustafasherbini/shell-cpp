#include <string>
#include <iostream>
#include <memory>

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
public:

    TypeCommand(const std::string& command) {
        _command=command.substr(5);
    }
     void Processing () override {
        _msg=_command;
        if (_command == "echo" || _command == "type")
            _msg+=" is a shell builtin";
        else
            _msg += ": not found";
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

