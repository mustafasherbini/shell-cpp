#include "Cat.h"
#include <fstream>
#include <iostream>

void Cat::Processing(const std::vector<std::string> &args) {
    for (auto path:args) {
        fs::path filePath(path);
        std::ifstream file(filePath);
    if (file)
        std::cout << file.rdbuf()<<"\n";
    }
}
