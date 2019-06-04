#include <vector>
#ifdef WIN32
#include <windows.h>
#else
#include <dlfcn.h>
#endif
#include "PluginManager.hpp"

void PluginManager::loadAll() {
    std::vector<std::string> plugins = {"pluginA", "pluginB", "pluginC"};

    for(auto&& name : plugins) {
        std::cout << "Loading plugin " << name << std::endl;
#ifdef WIN32
        auto handle = LoadLibrary((name + ".dll").c_str());
        if(!handle) {
            std::cout << "Failed to load plugin: " << std::endl;
            continue;
        }
        auto load = (Plugin* (*)())GetProcAddress(handle, "load");
        if(!load) {
            FreeLibrary(handle);
            std::cout << "Failed to get adress to load function: " << std::endl;
            continue;
        }
#else
        auto handle = dlopen(("lib" + name + ".so").c_str(), RTLD_LAZY);
        if(!handle) {
            std::cout << "Failed to load plugin: " << dlerror() << std::endl;
            continue;
        }
        auto load = (Plugin* (*)())dlsym(handle, "load");
        if(!load) {
            dlclose(handle);
            std::cout << "Failed to get address of load function: " << dlerror() << std::endl;
            continue;
        }
#endif
        auto object = load();
        m_plugins[object->getName()] = std::shared_ptr<Plugin>(object);
        //_get_name = (char* (*)())dlsym(handle, "name");
        //_get_version = (char* (*)())dlsym(handle, "version");
    }
}

std::shared_ptr<Plugin> PluginManager::getPlugin(std::string name) {
    return m_plugins.at(name);
}
