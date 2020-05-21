// Copyright 2020 Sokova Anastasia

#ifndef MODULES_MONEY_CONVERTER_INCLUDE_MONEY_CONVERTER_APP_H_
#define MODULES_MONEY_CONVERTER_INCLUDE_MONEY_CONVERTER_APP_H_

#include <string>
#include "include/Money_Converter.h"

class MoneyCalculator {
 public:
    MoneyCalculator() = default;
    std::string operator()(int argc, const char** argv);
 private:
    void Help(const char* appname, const char* message = "");
    bool ValidateNumberOfArgs(int argc, const char** argv);
    std::string message_;
    using Arguments = struct { double value; std::string operation; int side; };
};

#endif  // MODULES_MONEY_CONVERTER_INCLUDE_MONEY_CONVERTER_APP_H_
