// Copyright 2020 Zinkov Artem

#include <string>
#include <sstream>
#include <algorithm>
#include <vector>

#include "include/odd_even_batcher_merge.h"
#include "include/merge_batcher_app.h"

Merge_Batcher_App::Merge_Batcher_App() : message_("") {}

void Merge_Batcher_App::help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
        "This is a merge batcher application.\n\n" +
        "Please provide arguments in the following format:\n\n" +
        "  $ " + appname + " <v1> " + "<v2>\n\n" +
        "Where all the arguments are a sequence of integers.\n";
}

bool Merge_Batcher_App::validateNumberOfArguments(int argc, const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else {
        if (argc != 3) {
            help(argv[0], "ERROR: Should be 2 arguments.\n\n");
            return false;
        }
    }
    return true;
}

std::vector<int> parseVector(const char* arg) {
    std::vector<int> vec;
    std::string str = arg;
    std::istringstream in(str);

    for (auto& s : str) {
        if (!(isdigit(s) || s == ',' || s == '.' || s == ' ' || s == '-'))
            throw std::string("ERROR: Wrong format!");
    }

    for (int n; in >> n; vec.push_back(n), in.get()) {}
    std::sort(vec.begin(), vec.end());

    return vec;
}


std::string Merge_Batcher_App::operator()(int argc, const char** argv) {
    Arguments args;

    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }

    try {
        args.v1 = parseVector(argv[1]);
        args.v2 = parseVector(argv[2]);
    }
    catch (std::string & str) {
        return str;
    }

    std::vector<int> res = merge_batcher(args.v1, args.v2);

    std::ostringstream stream;
    stream << "result vector =";
    for (auto& r : res)
        stream << " " << r;

    message_ = stream.str();

    return message_;
}
