#include "PluginManager.hpp"

int main() {
    PluginManager manager;
    manager.loadAll();
    auto pluginA = manager.getPlugin("PluginA");
    std::cout << pluginA->doSomething(2, 4) << std::endl;
    pluginA->doSomethingElse("woho!");
}