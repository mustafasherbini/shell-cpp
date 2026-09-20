#include <iostream>
#include "Prompt.cpp"

int main() {
  std::cout << std::unitbuf;
  std::cerr << std::unitbuf;
    Prompt::run();
}
