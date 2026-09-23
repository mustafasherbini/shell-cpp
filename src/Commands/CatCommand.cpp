#include "CatCommand.h"
#include <fstream>
#include <iostream>

void CatCommand::Processing(const std::vector<std::string> &args) {
    for (auto path:args) {
        fs::path filePath(path);
        std::ifstream file(filePath);
    if (file)
        std::cout << file.rdbuf()<<" ";
    }
}
