#include <vector>
#include <dlfcn.h>
#include "PluginManager.hpp"

void PluginManager::loadAll() {
    std::vector<std::string> plugins = {"libpluginA.so", "libpluginB.so"};

    for(auto&& name : plugins) {
        std::cout << "Loading plugin " << name << std::endl;
        auto handle = dlopen(name.c_str(), RTLD_LAZY);
        if(!handle) {
            std::cout << "Failed to load plugin" << std::endl;
            continue;
        }
        auto load = (std::shared_ptr<Plugin> (*)())dlsym(handle, "load");
        auto object = load();
        m_plugins[object->getName()] = object;
        //_get_name = (char* (*)())dlsym(handle, "name");
        //_get_version = (char* (*)())dlsym(handle, "version");
    }
}

std::shared_ptr<Plugin> PluginManager::getPlugin(std::string name) {
    return m_plugins.at(name);
}
