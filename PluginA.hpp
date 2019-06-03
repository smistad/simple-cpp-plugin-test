#pragma once
#include <Plugin.hpp>

class PluginA : public Plugin {
    public:
        std::string getName() override;
        int doSomething(int a, int b) override;
        void doSomethingElse(std::string input) override;
};

DEFINE_PLUGIN(PluginA, "PluginA", "1.0.0");