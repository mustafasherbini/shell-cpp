#include "CommandFactory.h"
#include "EchoCommand.h"
#include "TypeCommand.h"
#include "CustomCommand.h"
#include "CdCommand.h"
#include "PwdCommand.h"
#include <cstdlib>


std::unique_ptr<CommandBase> CommandFactory::GetCommand(const std::vector<std::string> &args) {
    std::string firstArgument = args[0];

    if (firstArgument == "echo")
        return std::make_unique<EchoCommand>();
    if (firstArgument == "type")
        return std::make_unique<TypeCommand>();
    if (firstArgument == "pwd")
        return std::make_unique<PwdCommand>();
    if (firstArgument == "cd")
        return std::make_unique<CdCommand>();

    std::string fileDir;
    if (CommandBase::IsAnExecutable(getenv("PATH"), firstArgument, fileDir)) {
        return std::make_unique<CustomCommand>();
    }

    return nullptr;
}
