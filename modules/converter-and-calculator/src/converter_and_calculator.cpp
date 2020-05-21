// Copyright 2020 Zakharov Mikhail

#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include "include/calculator.h"
#include "include/converter.h"
#include "include/converter_and_calculator.h"

Converter_and_Calculator::Converter_and_Calculator() : message_("") {}

void Converter_and_Calculator::help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
          "This is a converter and calculator application.\n\n" +
          "Please provide arguments in the following format:\n\n"+

          "  $ " + appname + " <a> <system_a> " +
          "<b> <system_b> <operation>\n\n" +

          "Where all arguments are int numbers, " +
          "and <operation> is one of '+', '-', '*', '/'.\n";
}

bool Converter_and_Calculator::validateNumberOfArguments
(int argc, const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else if (argc != 6) {
        help(argv[0], "ERROR: Should be 5 arguments.\n\n");
        return false;
    }
    return true;
}

double parseInt(const char* arg) {
    char* end;
    int value = strtol(arg, &end, 0);
    if (end[0]) {
        throw std::string("Wrong number format!");
    }
    return value;
}

char parseOperation(const char* arg) {
    char op;
    if (strcmp(arg, "+") == 0) {
        op = '+';
    } else if (strcmp(arg, "-") == 0) {
        op = '-';
    } else if (strcmp(arg, "*") == 0) {
        op = '*';
    } else if (strcmp(arg, "/") == 0) {
        op = '/';
    } else {
        throw std::string("Wrong operation format!");
    }
    return op;
}

std::string Converter_and_Calculator::operator()(int argc, const char** argv) {
    Arguments args;

    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }
    try {
        args.a            = parseInt(argv[1]);
        args.system1      = parseInt(argv[2]);
        args.b            = parseInt(argv[3]);
        args.system2      = parseInt(argv[4]);
        args.operation    = parseOperation(argv[5]);
    }
    catch(std::string& str) {
        return str;
    }

    calculator calc;

    int c;
    std::ostringstream stream;
    switch (args.operation) {
     case '+':
        c = calc.sum(args.a, args.system1, args.b, args.system2);
        break;
     case '-':
        c = calc.diff(args.a, args.system1, args.b, args.system2);
        break;
     case '*':
        c = calc.mult(args.a, args.system1, args.b, args.system2);
        break;
     case '/':
        c = calc.div(static_cast<double>(args.a), args.system1,
         static_cast<double>(args.b), args.system2);
    }

    stream << "a = " << args.a << " "
        << "b = " << args.b << " "
        << "c = " << c;

    message_ = stream.str();

    return message_;
}
