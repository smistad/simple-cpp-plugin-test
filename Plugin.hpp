#pragma once
#include <string>
#include <iostream>
#include <memory>
#include "Export.hpp"

class COMMON_EXPORT Plugin {
    public:
        virtual std::string getName() = 0;
        virtual int doSomething(int a, int b) = 0;
        virtual void doSomethingElse(std::string input) = 0;
        virtual void doSomethingCommon();
};

// Need C linkage here (extern "C" to avoid mangled names of the load function on windows, see https://stackoverflow.com/questions/19422550/why-getprocaddress-is-not-working
// Export statement is needed for Windows
#define DEFINE_PLUGIN(classType, exportStatement, pluginName, pluginVersion)        \
extern "C" exportStatement                                                          \
    Plugin* load()                                                                  \
    {                                                                               \
      return new classType();                                                       \
    }                                                                               \
