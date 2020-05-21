// Copyright 2020 Sokova Anastasia

#include "include/money_converter_app.h"

#include <string>
#include <sstream>
#include "include/Money_Converter.h"

void MoneyCalculator::Help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
        "**************************\n"
        "This is a money calculator application.\n\n" +
        "Please provide arguments in the following format:\n" +

        "  $ " + appname + " <value> <operation> <side>\n\n" +

        "<value> have to be a double-precision number\n\n" +
        "<operation> is one of the following\n\n" +
        "and <side> is which way to translate \n\n" +
        "For example:" + "  $ " + appname + " 50.0 usd 1 \n\n" +
        "'usd' - usd-rub,\n" +
        "'eur' - eur-rub,\n" +
        "'jpy'- jpy-rub,\n" +
        "'sek' - sek-rub,\n" +
        "'uah' - uah-rub\n\n" +
        "Where 1 is the forward path and 0 is the reverse\n\n" +
        "**************************\n";
}

bool MoneyCalculator::ValidateNumberOfArgs(int argc, const char** argv) {
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

std::string parseOperation(const char* arg) {
    std::string op(arg);
    if (op == "usd")
        return op;
    if (op == "eur")
        return op;
    if (op == "jpy")
        return op;
    if (op == "sek")
        return op;
    if (op == "uah")
        return op;
    throw std::string("Wrong operation format!");
}

std::string MoneyCalculator::operator()(int argc, const char** argv) {
    Arguments args;

    if (!ValidateNumberOfArgs(argc, argv)) {
        return message_;
    }
    try {
        args.value = parseDouble(argv[1]);
        args.operation = parseOperation(argv[2]);
        args.side = static_cast<bool>(std::stod(argv[3]));
    }
    catch (std::string & str) {
        return str;
    }

    std::ostringstream stream;

    if (args.operation == "usd") {
        stream << "usd-rub converter: " <<
            MoneyConverter::rubUSD(args.value, args.side);
    } else if (args.operation == "eur") {
        stream << "eur-rub converter: " <<
            MoneyConverter::rubEUR(args.value, args.side);
    } else if (args.operation == "jpy") {
        stream << "jpy-rub converter: " <<
            MoneyConverter::rubJPY(args.value, args.side);
    } else if (args.operation == "sek") {
        stream << "sek-rub converter: " <<
            MoneyConverter::rubSEK(args.value, args.side);
    } else if (args.operation == "uah") {
        stream << "uah-rub converter: " <<
            MoneyConverter::rubUAH(args.value, args.side);
    }
    message_ = stream.str();

    return message_;
}
