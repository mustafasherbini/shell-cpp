
#include "PromptHelpers.h"

std::vector<std::string> PromptHelpers::InputParsing(std::string input) {
    std::vector<std::string> args;
    bool haveSingleQuote = false;
    std::string newArg;

    for (int i = 0; i < input.size(); ++i) {
        if (input[i] == '\'')
            haveSingleQuote = !haveSingleQuote;

        else if (input[i] == ' ' && !haveSingleQuote) {
            if (!newArg.empty()) {
                args.push_back(newArg);
                newArg.clear();
            }
        }
        else
            newArg.push_back(input[i]);
    }

    if (!newArg.empty())
        args.push_back(newArg);

    return args;
}

