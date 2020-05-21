// Copyright 2020 Antipin Alexander

#ifndef MODULES_RADIX_SORT_INCLUDE_RADIX_SORT_APP_H_
#define MODULES_RADIX_SORT_INCLUDE_RADIX_SORT_APP_H_

#include <string>
#include <sstream>
#include "../include/radix_sort.h"

class SortVectorApp {
 public:
    SortVectorApp() = default;
    std::string operator()(int argc, const char** argv);
 private:
    std::string help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);
    SortArray _array;
    std::stringstream _sstream;
};

#endif  // MODULES_RADIX_SORT_INCLUDE_RADIX_SORT_APP_H_
