// Copyright 2020 Yasakova Anastasia

#ifndef MODULES_QUEUE_INCLUDE_QUEUE_APPLICATION_H_
#define MODULES_QUEUE_INCLUDE_QUEUE_APPLICATION_H_

#include <string>
#include <sstream>
#include "include/queue.h"

class QueueApp {
 public:
    QueueApp() = default;
    std::string operator()(int argc, const char** argv);
 private:
    std::string help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);
    int ParseValue(const std::string& data);
    Queue queue;
    std::stringstream _sstream;
};

#endif  // MODULES_QUEUE_INCLUDE_QUEUE_APPLICATION_H_
