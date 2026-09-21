#include "CommandFactory.h"
#include "EchoCommand.h"
#include "TypeCommand.h"
#include "CustomCommand.h"
#include <cstdlib>

#include "PwdCommand.h"

std::unique_ptr<CommandBase> CommandFactory::GetCommand(const std::string& command) {
    std::string commandName = CommandBase::GetCommandName(command);

    if (commandName == "echo") {
        return std::make_unique<EchoCommand>(command);
    }

    if (commandName == "type") {
        return std::make_unique<TypeCommand>(command);
    }
    if (commandName == "pwd") {
        return std::make_unique<PwdCommand>();
    }

    std::string fileDir;
    if (CommandBase::IsAnExecutable(getenv("PATH"), commandName, fileDir)) {
        return std::make_unique<CustomCommand>(command);
    }

    return nullptr;
}
