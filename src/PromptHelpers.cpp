
#include "PromptHelpers.h"

std::vector<std::string> PromptHelpers::InputParsing(std::string input) {
    std::vector<std::string> args;
    bool haveSingleQuote = false, haveDoubleQuote=false;
    std::string newArg;

    for (int i = 0; i < input.size(); ++i) {
        if (i+1< input.size() and input[i]=='"' and input[i+1]=='"' ) {
            i++;
            continue;
        }
        if (input[i]=='\\' and !haveSingleQuote) {
                if (i+1<input.size())
                    newArg.push_back(input[++i]);
        }
        else if (input[i] == '"' and !haveSingleQuote)
            haveDoubleQuote=!haveDoubleQuote;
        else if (!haveDoubleQuote and input[i] == '\'')
            haveSingleQuote = !haveSingleQuote;

        else if (input[i] == ' ' && !haveSingleQuote && ! haveDoubleQuote) {
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

