// Copyright 2020 Kuzhelev Anton

#include "include/complex_number_calculator.h"

#include <string>
#include <sstream>
#include <stdexcept>

ComplexCalculator::ComplexCalculator() : message_("") {}

void ComplexCalculator::help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
          "This is a complex number calculator application.\n\n" +
          "Please provide arguments in the following format:\n\n"+

          "  $ " + appname + " <z1_real> <z1_imaginary> " +
          "<z2_real> <z2_imaginary> <operation>\n\n" +

          "Where all arguments are double-precision numbers, " +
          "and <operation> is one of '+', '-', '*', '/'.\n";
}

bool ComplexCalculator::validateNumberOfArguments(int argc, const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else if (argc != 6) {
        help(argv[0], "ERROR: Should be 5 arguments.\n\n");
        return false;
    }
    return true;
}

char parseOperation(const char* arg) {
    char op;
    switch (*arg) {
        case '+':
            op = '+';
            break;
        case '-':
            op = '-';
            break;
        case '*':
            op = '*';
            break;
        case '/':
            op = '/';
            break;
        default:
            throw std::string("Wrong operation format!");
    }
    return op;
}

std::string ComplexCalculator::operator()(int argc, const char** argv) {
    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }

    try {
        n1.setRe(std::stod(argv[1]));
        n1.setIm(std::stod(argv[2]));
        n2.setRe(std::stod(argv[3]));
        n2.setIm(std::stod(argv[4]));
        operation = parseOperation(argv[5]);
    }
    catch(std::string &str) {
        return str;
    }
    catch(std::invalid_argument) {
        return std::string("Wrong number format!");
    }

    switch (operation) {
    case '+':
        res = n1 + n2;
        break;
    case '-':
        res = n1 - n2;
        break;
    case '*':
        res = n1 * n2;
        break;
     case '/':
        try {
            res = n1 / n2;
            break;
        }
        catch(std::string& str) {
            return str;
        }
    }
    std::ostringstream stream;
    stream << "Real = " << res.getRe() << " "
               << "Imaginary = " << res.getIm();
    message_ = stream.str();

    return message_;
}
