// Copyright 2020 Suchkov Makar

#ifndef MODULES_BITFIELD_INCLUDE_BITFIELD_APP_H_
#define MODULES_BITFIELD_INCLUDE_BITFIELD_APP_H_

#include <string>
#include <vector>

class Bitfieldapp {
 public:
    Bitfieldapp();
    std::string operator()(int argc, const char** argv);

 private:
    void help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);
    std::string message_;
    using Arguments = struct {
        unsigned int bitfield_size;
        int type;
        unsigned int position;
        std::vector<unsigned int> arr;
    };
};

#endif  // MODULES_BITFIELD_INCLUDE_BITFIELD_APP_H_
