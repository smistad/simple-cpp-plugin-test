#pragma once
#include <Plugin.hpp>

class PluginB : public Plugin {
    public:
        std::string getName() override;
        int doSomething(int a, int b) override;
        void doSomethingElse(std::string input) override;
};

DEFINE_PLUGIN(PluginB, "PluginB", "1.2.0");
