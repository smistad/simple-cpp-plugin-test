#include "PluginB.hpp"

std::string PluginB::getName() {
    return "PluginB";
}

int PluginB::doSomething(int a, int b) {
    return a-b;
}

void PluginB::doSomethingElse(std::string input) {
    std::cout << "From plugin B: " << input << std::endl;
}
