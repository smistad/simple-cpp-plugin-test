#pragma once
#include <memory>
#include <unordered_map>
#include "Plugin.hpp"

class PluginManager {
    public:
        void loadAll();
        std::shared_ptr<Plugin> getPlugin(std::string name);
    private:
        std::unordered_map<std::string, std::shared_ptr<Plugin>> m_plugins;

};