// Copyright 2020 Antipin Alexander

#include <vector>
#include <string>
#include <stdexcept>
#include <cstring>
#include <cctype>
#include "../include/radix_sort_app.h"

int parseNumbers(const char* number) {
    size_t size = strlen(number);

    if ((number[0] == '-' && size == 1) ||
        (!std::isdigit(number[0]) && number[0] != '-'))
        throw std::invalid_argument("Wrong character in numbers");
    for (size_t i = 1; i < size; ++i)
        if (!std::isdigit(number[i]))
            throw std::invalid_argument("Wrong character in numbers");

    return std::atoi(number);
}

std::string SortVectorApp::operator()(int argc, const char** argv) {
    if (!validateNumberOfArguments(argc, argv)) return _sstream.str();

    std::vector<int32_t> unsort(argc - 1);
    try {
        for (int i = 0; i < argc - 1; ++i)
            unsort[i] = parseNumbers(argv[i + 1]);
    }
    catch (std::exception& error) {
        return error.what();
    }

    _array(&unsort);

    std::string result;
    for (int i = 0; i < argc - 1; ++i)
        result += std::to_string(unsort[i]) + ' ';
    return result;
}

std::string SortVectorApp::help(const char* appname, const char* message) {
    return std::string(message) +
        "This is a integer array sorting application.\n\n" +
        "Please provide arguments in the following format:\n\n" +
        "  $ " + appname + " <integer numbers> \n\n" +
        "Where <integer numbers> is a set of some integer numbers\n";
}

bool SortVectorApp::validateNumberOfArguments(int argc, const char** argv) {
    if (argc == 1) {
        _sstream << help(argv[0]);
        return false;
    }
    return true;
}
