// Copyright 2020 Zakharov Mikhail

#ifndef MODULES_CONVERTER_AND_CALCULATOR_INCLUDE_CONVERTER_AND_CALCULATOR_H_
#define MODULES_CONVERTER_AND_CALCULATOR_INCLUDE_CONVERTER_AND_CALCULATOR_H_

#include <string>

class Converter_and_Calculator {
 public:
    Converter_and_Calculator();
    std::string operator()(int argc, const char** argv);

 private:
    void help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);
    std::string message_;
    typedef struct {
        double a;
        double system1;
        double b;
        double system2;
        char operation;
    } Arguments;
};

#endif  // MODULES_CONVERTER_AND_CALCULATOR_INCLUDE_CONVERTER_AND_CALCULATOR_H_
