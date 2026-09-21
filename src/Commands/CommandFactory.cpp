#include "CommandFactory.h"
#include "EchoCommand.h"
#include "TypeCommand.h"
#include "CustomCommand.h"
#include <cstdlib>

std::unique_ptr<CommandBase> CommandFactory::GetCommand(const std::string& command) {
    std::string commandName = CommandBase::GetCommandName(command);

    if (commandName == "echo") {
        return std::make_unique<EchoCommand>(command);
    }

    if (commandName == "type") {
        return std::make_unique<TypeCommand>(command);
    }

    std::string fileDir;
    if (CommandBase::IsAnExecutable(getenv("PATH"), commandName, fileDir)) {
        return std::make_unique<CustomCommand>(command);
    }

    return nullptr;
}