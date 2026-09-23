#include "CatCommand.h"
#include <fstream>
#include <iostream>

void CatCommand::Processing(const std::vector<std::string> &args) {
    for (int i=1 ; i<args.size() ; i++) {
        auto path = args[i];
        fs::path filePath(path);
        std::ifstream file(filePath);
        if (file.is_open())
            std::cout << file.rdbuf();
    }
        std::cout << std::endl;
}
