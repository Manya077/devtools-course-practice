// Copyright 2020 Dobrohotov Vitaly

#ifndef MODULES_PRIME_NUMBERS_INCLUDE_PRIME_NUMS_FOR_APP_H_
#define MODULES_PRIME_NUMBERS_INCLUDE_PRIME_NUMS_FOR_APP_H_

#include <string>
#include <iostream>
#include "include/TPrime_Nums.h"

class PrimeNums {
 public:
    PrimeNums();
    std::string operator()(int argc, const char** argv);
 private:
    std::string message_;
    void help(const char* appname, const char* error_message);
    bool checkArgs(int _argc, const char** _argv);
};
#endif  // MODULES_PRIME_NUMBERS_INCLUDE_PRIME_NUMS_FOR_APP_H_
