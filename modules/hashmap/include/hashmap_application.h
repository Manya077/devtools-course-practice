// Copyright 2020 Nazarov Vladislav

#ifndef MODULES_HASHMAP_INCLUDE_HASHMAP_APPLICATION_H_
#define MODULES_HASHMAP_INCLUDE_HASHMAP_APPLICATION_H_

#include <string>
#include <sstream>
#include "include/hashmap.h"

class hashmapApp {
 public:
    hashmapApp();
    std::string operator()(int argc, const char** argv);
 private:
    std::string help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);
    int parseOperation(const char** ops);
    int parseToValue(const char* strval);
 private:
    hashmap<int, int> _hashmap;
    std::stringstream _sstream;
};

#endif  // MODULES_HASHMAP_INCLUDE_HASHMAP_APPLICATION_H_
