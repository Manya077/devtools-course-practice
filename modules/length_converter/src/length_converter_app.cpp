// Copyright 2020 Brazhnikov Eugene

#include "include/length_converter.h"
#include "include/length_converter_app.h"

#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <sstream>

void LengthCalculator::Help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
        "**************************\n"
        "This is a length calculator application.\n\n" +
        "Please provide arguments in the following format:\n" +

        "  $ " + appname + " <value> <operation> <side>\n\n" +

        "<value> have to be a double-precision number\n\n" +
        "<operation> is one of the following\n\n" +
        "and <side> is which way to translate \n\n" +
        "For example:" + "  $ " + appname + " 50.0 inch 1 \n\n" +
        "'kilometer' - kilometer-meter,\n" +
        "'santimeter' - santimeter-meter,\n" +
        "'mile'- mile-meter,\n" +
        "'yard' - yard-meter,\n" +
        "'ft' - ft-meter\n" +
        "'inch'- inch-meter\n\n" +
        "Where 1 is the forward path and 0 is the reverse\n\n" +
        "**************************\n";
}

bool LengthCalculator::ValidateNumberOfArgs(int argc, const char** argv) {
    if (argc == 1) {
        Help(argv[0]);
        return false;
    } else if (argc != 4) {
        Help(argv[0], "ERROR: Should be 3 arguments.\n");
        return false;
    }
    return true;
}

double parseDouble(const char* arg) {
    char* end;
    double value = strtod(arg, &end);

    if (end[0]) {
        throw std::string("Wrong number format!");
    }

    return value;
}

double parseSide(const char* arg) {
    char* end;
    double value = strtod(arg, &end);

    if (end[0]) {
        throw std::string("Wrong number format!");
    }

    int value1 = static_cast<bool>(value);

    return value1;
}

std::string parseOperation(const char* arg) {
    std::string op;
    if (strcmp(arg, "kilometer") == 0) {
        op = "kilometer";
    } else if (strcmp(arg, "santimeter") == 0) {
        op = "santimeter";
    } else if (strcmp(arg, "mile") == 0) {
        op = "mile";
    } else if (strcmp(arg, "yard") == 0) {
        op = "yard";
    } else if (strcmp(arg, "ft") == 0) {
        op = "ft";
    } else if (strcmp(arg, "inch") == 0) {
        op = "inch";
    } else {
        throw std::string("Wrong operation format!");
    }
    return op;
}

std::string LengthCalculator::operator()(int argc, const char** argv) {
    Arguments args;

    if (!ValidateNumberOfArgs(argc, argv)) {
        return message_;
    }
    try {
        args.value = parseDouble(argv[1]);
        args.operation = parseOperation(argv[2]);
        args.side = parseSide(argv[3]);
    }
    catch (std::string& str) {
        return str;
    }

    std::ostringstream stream;

    if (args.operation == "inch") {
        stream << "Inch-meter converter: " <<
            LengthConverter::m_inch(args.value, args.side);
    } else if (args.operation == "ft") {
        stream << "Ft-meter converter: " <<
            LengthConverter::m_ft(args.value, args.side);
    } else if (args.operation == "kilometer") {
        stream << "Kilometer-meter converter: " <<
            LengthConverter::m_kmeter(args.value, args.side);
    } else if (args.operation == "santimeter") {
        stream << "Santimeter-meter converter: " <<
            LengthConverter::m_smeter(args.value, args.side);
    } else if (args.operation == "mile") {
        stream << "Mile-meter converter: " <<
            LengthConverter::m_mile(args.value, args.side);
    } else if (args.operation == "yard") {
        stream << "Yard-meter converter: " <<
            LengthConverter::m_yard(args.value, args.side);
    }
    message_ = stream.str();

    return message_;
}
