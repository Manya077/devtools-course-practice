// Copyright 2020 Nazarov Vladislav

#include <cstring>
#include <stdexcept>
#include <string>
#include <sstream>
#include <cctype>
#include "include/hashmap_application.h"

hashmapApp::hashmapApp() : _hashmap(10) {}

std::string hashmapApp::operator()(int argc, const char** argv) {
    if (!validateNumberOfArguments(argc, argv)) {
        return _sstream.str();
    }
    try {
        for (int i = 1; i < argc;) {
            int offset = parseOperation(argv+i);
            i += offset;
        }
        return _sstream.str();
    } catch(std::exception& exc) {
        return exc.what();
    }
}

std::string hashmapApp::help(const char* appname, const char* message) {
    return std::string(message) + "This is a Hashmap application.\n\n"+
        "Please provide arguments in the following format:\n\n"+
        "  $ " + appname + " <actions> \n\n" +
        "Where <actions> are: \n\n" +
        "insert <key value> - insert node into tree\n" +
        "remove <key>       - remove element from tree\n" +
        "get <key>          - get element by key from hashmap\n";
}

bool hashmapApp::validateNumberOfArguments(int argc, const char** argv) {
    if (argc == 1) {
        _sstream << help(argv[0]);
        return false;
    }
    return true;
}

int hashmapApp::parseToValue(const char* strval) {
    auto n = static_cast<int>(std::strlen(strval));

    if ((strval[0] != '-' && !std::isdigit(strval[0])) ||
        (strval[0] == '-' && n == 1))
        throw std::invalid_argument("Invalid value: " + std::string(strval));

    for (int i = 1; i < n; i++) {
        if (!std::isdigit(strval[i]))
            throw
                std::invalid_argument("Invalid value: " + std::string(strval));
    }
    int res = 0;
    try {
        res = std::stoi(strval);
    } catch (std::exception& exc) {
            _sstream << "(Out of range)";
    }
    return res;
}

int hashmapApp::parseOperation(const char** ops) {
    if (std::strcmp(ops[0], "insert") == 0) {
        _hashmap.insert(parseToValue(ops[1]), parseToValue(ops[2]));
        return 3;
    }
    if (std::strcmp(ops[0], "remove") == 0) {
        try {
            _hashmap.remove(parseToValue(ops[1]));
        } catch (std::exception& exc) {
            _sstream << "(" << exc.what() << ")";
        }
        return 2;
    }
    if (std::strcmp(ops[0], "get") == 0) {
        auto key = parseToValue(ops[1]);
        try {
            auto value = _hashmap[key];
            _sstream << "(value = " << value << " with key = " << key << ") ";
        } catch (std::exception& exc) {
            _sstream << "(" << exc.what() << ")";
        }
        return 2;
    }
    throw std::invalid_argument("Bad arguments!");
    return 0;
}
