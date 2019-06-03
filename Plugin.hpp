#pragma once
#include <string>
#include <iostream>
#include <memory>

class Plugin {
    public:
        virtual std::string getName() = 0;
        virtual int doSomething(int a, int b) = 0;
        virtual void doSomethingElse(std::string input) = 0;
        virtual void doSomethingCommon() {
            std::cout << "Hello world!" << std::endl;
        };
};

#define DEFINE_PLUGIN(classType, pluginName, pluginVersion)     \
  extern "C" {                                                  \
    std::shared_ptr<Plugin> load()                              \
    {                                                           \
      return std::make_shared<classType>();                     \
    }                                                           \
   }                                                            \

