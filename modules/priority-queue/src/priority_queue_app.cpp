// Copyright 2020 Andreev Sergey

#include "include/priority_queue.h"
#include "include/priority_queue_app.h"

#include <string>
#include <sstream>

pq_app::pq_app() : message_("") {}

void pq_app::help(const char* appname, std::string message) {
    message_ =
        std::string(message) +
        "This is a priority queue application.\n\n" +
        "Please provide arguments in the following format:\n\n" +

        "  $ " + appname + " <number>" + " <key> <data> <operation> \n\n" +

        "Where <number> is count of pairs <key>-<value>, "+
        "<key> is priority of <data> value " +
        "and they are expected to be of integer type, " +
        "<operation> is one of 'extractMax', 'extractMin'.\n";
}

bool pq_app::validateNumberOfArguments(int argc, const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else if (argc != (std::stoi(argv[1])*2+2+1)) {
        std::string str = std::to_string(std::stoi(argv[1]) * 2 + 2);
        help(argv[0], "ERROR: Should be "+ str +" arguments.\n\n");
        return false;
    }
    return true;
}

std::string parseOperation(const char* arg) {
    std:: string operation(arg);
    if (operation != "extractMin" && operation != "extractMax") {
        throw std::string("Wrong format!");
    }
    return operation;
}

std::string pq_app::operator()(int argc, const char** argv) {
    Arguments args;

    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }

    for (int i = 0, j = 2; i < std::stoi(argv[1]); i++, j=j+2) {
        try {
            args.key_value.push_back(std::make_pair(std::stoi(argv[j]),
                std::stoi(argv[j + 1])));
        }
        catch (std::exception & error) {
            return std::string("Wrong number format!");
        }
    }

    try {
        args.operation = parseOperation(argv[std::stoi(argv[1]) * 2 + 2]);
    }
    catch (std::string & str) {
        return str;
    }

    priority_queue pq;

    for (const auto& i : args.key_value) {
        node n(i.first, i.second);
        pq.insert(n);
    }

    int output = 0;

    std::ostringstream stream;
    if (args.operation == "extractMin") {
        output = *(pq.extract_minimum());
        stream << "Min value = " << output;
    } else  if (args.operation == "extractMax") {
        output = *(pq.extract_maximum());
        stream << "Max value = " << output;
    }

    message_ = stream.str();

    return message_;
}
