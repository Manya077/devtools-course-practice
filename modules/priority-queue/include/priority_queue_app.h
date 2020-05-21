// Copyright 2020 Andreev Sergey

#ifndef MODULES_PRIORITY_QUEUE_INCLUDE_PRIORITY_QUEUE_APP_H_
#define MODULES_PRIORITY_QUEUE_INCLUDE_PRIORITY_QUEUE_APP_H_

#include <string>
#include <vector>
#include <utility>

class pq_app {
 public:
    pq_app();
    std::string operator()(int argc, const char** argv);

 private:
    void help(const char* appname, std::string message = "");
    bool validateNumberOfArguments(int argc, const char** argv);
    std::string message_;
    using Arguments = struct {
        std::vector<std::pair<int, int>> key_value;
        std::string operation;
    };
};

#endif  // MODULES_PRIORITY_QUEUE_INCLUDE_PRIORITY_QUEUE_APP_H_
