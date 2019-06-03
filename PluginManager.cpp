#include <vector>
#ifdef WIN32
#include <windows.h>
#else
#include <dlfcn.h>
#endif
#include "PluginManager.hpp"

void PluginManager::loadAll() {
    std::vector<std::string> plugins = {"libpluginA.so", "libpluginB.so", "libpluginC.so"};

    for(auto&& name : plugins) {
        std::cout << "Loading plugin " << name << std::endl;
#ifdef WIN32
        auto handle = LoadLibrary(name.c_str());
        if(!handle) {
            std::cout << "Failed to load plugin: " << std::endl;
            continue;
        }
        auto load = (std::shared_ptr<Plugin> (*)())GetProcAddress(handle, "load");
#else
        auto handle = dlopen(name.c_str(), RTLD_LAZY);
        if(!handle) {
            std::cout << "Failed to load plugin: " << dlerror() << std::endl;
            continue;
        }
        auto load = (std::shared_ptr<Plugin> (*)())dlsym(handle, "load");
        if(!load) {
            std::cout << "Failed to load plugin: " << dlerror() << std::endl;
            continue;
        }
#endif
        auto object = load();
        m_plugins[object->getName()] = object;
        //_get_name = (char* (*)())dlsym(handle, "name");
        //_get_version = (char* (*)())dlsym(handle, "version");
    }
}

std::shared_ptr<Plugin> PluginManager::getPlugin(std::string name) {
    return m_plugins.at(name);
}
