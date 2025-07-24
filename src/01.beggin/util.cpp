// util.cpp
#include <iostream>
#include "util.h"

namespace util {
    void greet(const std::string& name) {
        std::cout << "Hi, " << name << "! (from util)" << std::endl;
    }
}
