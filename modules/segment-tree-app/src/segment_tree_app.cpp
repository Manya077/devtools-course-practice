// Copyright 2020 Boganov Sergei

#include "include/segment_tree.h"
#include "include/segment_tree_app.h"

#include <string>
#include <sstream>

void SegmentTreeApp::help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
        "This is a segment tree application.\n\n" +
        "Please provide arguments in the following format:\n\n" +

        appname + " <count of elements> <first element> <second element> " +
        "... <last element> <count of queries> <first left border> " +
        "<first right border> ... <last left border> <last right border> " +
        "<operation>\n\n" +

        "Where count of elements, count of queries are natural numbers, " +
        "elements are integer, interval borders are non-negative integer, " +
        "operation is one of '+', 'max', 'min', 'gcd'.\n" +
        "Interval indexing starts from zero.\n";
}

int parseInt(const char* arg) {
    int value;
    try {
        value = std::stoi(arg);
    }
    catch(...) {
        throw std::string("Wrong number format!");
    }

    return value;
}

std::string parseOperation(const char* arg) {
    std::string op(arg);
    if (op == "+") {
        op = "+";
    } else if (op == "max") {
        op = "max";
    } else if (op == "min") {
        op = "min";
    } else if (op == "gcd") {
        op = "gcd";
    } else {
        throw std::string("Wrong operation format!");
    }
    return op;
}

bool SegmentTreeApp::validateNumberOfArguments(int argc, const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    }
    int count_of_elements = parseInt(argv[1]);
    if (argc > count_of_elements + 2) {
        int count_of_queries = parseInt(argv[count_of_elements + 2]);
        if (argc != count_of_elements + 2 * count_of_queries + 4) {
            help(argv[0],
            "Oops, incorrect number of parameters. Please try again.\n\n");
            return false;
        }
        return true;
    }
    help(argv[0],
    "Oops, incorrect number of parameters. Please try again.\n\n");
    return false;
}

std::string SegmentTreeApp::operator()(int argc, const char** argv) {
    Arguments args;

    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }
    try {
        args.count_of_elements = parseInt(argv[1]);
        args.elements.resize(args.count_of_elements);
        for (int i = 0; i < args.count_of_elements; i++) {
            args.elements[i] = parseInt(argv[i + 2]);
        }
        args.count_of_queries = parseInt(argv[args.count_of_elements + 2]);
        args.left_borders.resize(args.count_of_queries);
        args.right_borders.resize(args.count_of_queries);
        int k = args.count_of_elements + 3;
        for (int i = 0; i < args.count_of_queries; i++) {
            args.left_borders[i] = parseInt(argv[k++]);
            args.right_borders[i] = parseInt(argv[k++]);
        }
        args.operation = parseOperation(argv[args.count_of_elements
            + 2 * args.count_of_queries + 3]);
    }
    catch(std::string& str) {
        return str;
    }

    std::ostringstream stream;

    try {
        SegmentTree tree(args.elements, args.operation);
        stream << "Answers on queries: ";
        for (int i = 0; i < args.count_of_queries; i++) {
            int res;
            res = tree.query(args.left_borders[i], args.right_borders[i]);
            stream << res << ((i == args.count_of_queries - 1) ? "" : ", ");
        }
    }
    catch(std::string& str) {
        return str;
    }

    message_ = stream.str();

    return message_;
}
