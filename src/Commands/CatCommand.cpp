#include "CatCommand.h"
#include <fstream>
#include <iostream>

void CatCommand::Processing(const std::vector<std::string> &args) {
    for (auto path:args) {
        fs::path filePath(path);
        std::ifstream file(filePath);
        if (file.is_open())
            std::cout << file.rdbuf();
    }
        std::cout << std::endl;
}
