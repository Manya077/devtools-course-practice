// Copyright 2020 Egorov Danil

#ifndef MODULES_CONVERTER_INCLUDE_CONVERTER_APP_H_
#define MODULES_CONVERTER_INCLUDE_CONVERTER_APP_H_

#include <string>

class Converter_impl {
 public:
    Converter_impl();
    std::string operator()(int argc, const char** argv);

 private:
    void help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);
    std::string message_;
    typedef struct {
        double celsius;
        char format;
    } Arguments;
};

#endif  // MODULES_CONVERTER_INCLUDE_CONVERTER_APP_H_
