#pragma once
#include <Plugin.hpp>
#include <PluginBExport.hpp>

class PLUGINB_EXPORT PluginB : public Plugin {
    public:
        std::string getName() override;
        int doSomething(int a, int b) override;
        void doSomethingElse(std::string input) override;
};

DEFINE_PLUGIN(PluginB, PLUGINB_EXPORT, "PluginB", "1.2.0");