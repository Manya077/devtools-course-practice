// Copyright 2020 Yasakova Anastasia

#include <vector>
#include <string>
#include <sstream>
#include "include/queue_application.h"

std::string QueueApp::operator()(int argc, const char** argv) {
    if (!validateNumberOfArguments(argc, argv)) {
        return _sstream.str();
    }
    try {
        int i = 1;
        while (i < argc) {
            int check = 0;
            std::string op = *(argv + i);
            if (op == "getElement") {
                check = 1;
                _sstream << "GetElem = " << queue.Get() << ", ";
            } else if (op == "topElement") {
                check = 2;
                _sstream << "TopElem = " << queue.TopElem() << ", ";
            } else if (op == "putElement") {
                check = 3;
                queue.Put(ParseValue(*(argv + i + 1)));
            } else if (op == "getCount") {
                check = 4;
                _sstream << "Number of Elements = " << queue.GetCount();
            }
            if (check == 0)
                throw std::string("Bad arguments!");
            else if (check == 3)
                ++i;
            ++i;
        }
        return _sstream.str();
    } catch(std::string& str) {
        return str;
    }
}

std::string QueueApp::help(const char* appname, const char* message) {
    std::cout << message << std::endl;
    return std::string(message) + "This is a Queue application.\n\n"+
        "Please provide arguments in the following format:\n\n"+
        "  $ " + appname + " <actions> \n\n" +
        "Where <actions> are: \n\n" +
        "getElement - get front element from queue\n" +
        "topElement - access to front element from queue\n" +
        "putElement <data> - insert element into queue\n" +
        "getCount - get number of elements in queue\n ";
}

bool QueueApp::validateNumberOfArguments(int argc, const char** argv) {
    if (argc == 1) {
        _sstream << help(argv[0]);
        return false;
    }
    return true;
}

int QueueApp::ParseValue(const std::string& data) {
    int number = 0;
    try {
        number = std::stoi(data);
    } catch (const std::exception & e) {
        throw std::string("Invalid value: " + std::string(data));
    }
    return number;
}
