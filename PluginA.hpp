#pragma once
#include <Plugin.hpp>
#include <PluginAExport.hpp>

class PLUGINA_EXPORT PluginA : public Plugin {
    public:
        std::string getName() override;
        int doSomething(int a, int b) override;
        void doSomethingElse(std::string input) override;
};

DEFINE_PLUGIN(PluginA, PLUGINA_EXPORT, "PluginA", "1.0.0");