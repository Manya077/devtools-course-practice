// Copyright 2020 Arisova Anastasiia

#include "../include/roman-arabic-converter.h"
#include "../include/roman-arabic-converter-calculator.h"

#include <string>
#include <sstream>
#include <utility>

RomanArabicConvertCalculator::
    RomanArabicConvertCalculator() : message_("") {}

void RomanArabicConvertCalculator::
    help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
          "This is a Roman-Arabic Convert calculator application.\n\n" +
          "Please provide arguments in the following format:\n\n"+

          appname + " <count of elements>" +
          "<mode for first element> <first element>" +
          "<mode for second element> <second element> " +
          "... <mode for last element> <last element>\n\n" +

          "Where count of elements is a natural numbers, " +
          "mode is one of 'roman_to_arabic', 'arabic_to_roman'.\n" +
          "Please, input correct value for right work of converter!\n";
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

bool RomanArabicConvertCalculator::
    validateNumberOfArguments(int argc, const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    }
    int count_of_elements = parseInt(argv[1]);
    if (argc == 2 * count_of_elements + 2) {
        return true;
    }
    help(argv[0],
        "ERROR: incorrect number of parameters. Please try again.\n\n");
    return false;
}

std::string parseMode(const char* arg) {
    std::string op(arg);
    if ((op == "roman_to_arabic") || (op == "arabic_to_roman")) {
        return op;
    } else {
        throw std::string("Wrong mode format!");
    }
}

std::string RomanArabicConvertCalculator::
    operator()(int argc, const char** argv) {
    Arguments args;

    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }
    try {
        args.count_of_elements = parseInt(argv[1]);
        args.elements.resize(args.count_of_elements);
        for (int i = 0, j = 2; i < args.count_of_elements; i++, j += 2) {
            std::pair <std::string, std::string>temp
                (parseMode(argv[j]), std::string(argv[j + 1]));
            args.elements[i] = temp;
        }
    }
    catch(std::string& str) {
        return str;
    }
    RomanArabicConverter converter;

    std::ostringstream stream;

    try {
        stream << "Results of the conversion: ";
        for (int i = 0; i < args.count_of_elements; i++) {
            if (i != 0)
                stream << "   ";
            if (args.elements[i].first == "arabic_to_roman") {
                std::string res_roman;
                res_roman = converter.arabicToRoman
                    (std::stoi(args.elements[i].second));
                stream << args.elements[i].second << " -> ";
                stream << res_roman;
            } else {
                int res_arabic;
                res_arabic = converter.romanToArabic(args.elements[i].second);
                stream << args.elements[i].second << " -> ";
                stream << res_arabic;
            }
        }
    }
    catch(std::string& str) {
        return str;
    }

    message_ = stream.str();

    return message_;
}
