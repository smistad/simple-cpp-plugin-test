#include "PluginA.hpp"

std::string PluginA::getName() {
    return "PluginA";
}

int PluginA::doSomething(int a, int b) {
    return a*b;
}

void PluginA::doSomethingElse(std::string input) {
    std::cout << input << std::endl;
}
