// Copyright 2020 Egorov Danil

#include "include/converter.h"
#include "include/converter_app.h"

#include <iostream>
#include <string>
#include <cstring>
#include <sstream>

Converter_impl::Converter_impl() : message_("") {}

void Converter_impl::help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
        "This is a temperature converter application.\n\n" +
        "Please provide arguments in the following format:\n\n"+

        "  $ " + appname + " <celsius> <format>\n\n" +

        "Where <celsius> argument are double-precision number, " +
        "and <format> is one of 'kelv', 'fahr', 'newt'.\n";
}

bool Converter_impl::validateNumberOfArguments(int argc, const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else if (argc != 3) {
        help(argv[0], "ERROR: Should be 2 arguments.\n\n");
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

char parseFormat(const char* arg) {
    char format;
    if (strcmp(arg, "kelv") == 0) {
        format = 'k';
    } else if (strcmp(arg, "fahr") == 0) {
        format = 'f';
    } else if (strcmp(arg, "newt") == 0) {
        format = 'n';
    } else {
        throw std::string("Wrong format!");
    }
    return format;
}

std::string Converter_impl::operator()(int argc, const char** argv) {
    Arguments args;

    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }
    try {
        args.celsius = parseDouble(argv[1]);
        args.format  = parseFormat(argv[2]);
    }
    catch(std::string& str) {
        return str;
    }

    Convert convertor;
    double output;

    std::ostringstream stream;
    switch (args.format) {
     case 'k':
        output = convertor.convert_to_Kelvins(args.celsius);
        stream << "Celsius = " << args.celsius << " "
               << "Kelvins = " << output;
        break;
     case 'f':
        output = convertor.convert_to_Fahrenheit(args.celsius);
        stream << "Celsius = " << args.celsius << " "
               << "Farenheits = " << output;
        break;
     case 'n':
        output = convertor.convert_to_Newton(args.celsius);
        stream << "Celsius = " << args.celsius << " "
               << "Newtons = " << output;
        break;
    }

    message_ = stream.str();

    return message_;
}
