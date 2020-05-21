// Copyright 2020 Sokolov Nikolay

#include "include/fraction.h"
#include "include/fraction_calculator.h"

#include <string>
#include <sstream>
#include <stdexcept>

FractionCalculator::FractionCalculator() : message_("") {}

void FractionCalculator::help(std::string appname, std::string message) {
    message_ =
        message +
        "This is a fraction calculator application.\n\n" +
        "Please provide arguments in the following format:\n\n" +
        "  $ " + appname + " <f_num> <f_den> <operation>\n\n" +
        "Where all arguments are double-precision numbers, " +
        "and <operation> is one of 'd', 'r', '=', '>', '<'.\n\n" +
        "or\n\n" +
        "  $ " + appname + " <f_num> <f_den> <int> <operation>\n\n" +
        "Where all arguments are double-precision numbers, " +
        "and <operation> is one of '+', '-', '*', '/', 'i', '=', '>', '<'.\n"
        "or\n\n" +
        "  $ " + appname + " <f1_num> <f1_den> "
        + "<f2_num> <f2_den> <operation>\n\n" +
        "Where all arguments are double-precision numbers, " +
        "and <operation> is one of '+', '-', '*', '/', '=', '>', '<'.\n\n" +

        "Operation: '+' = addition,\n '-' = subtraction,\n" +
        "'*' = multiplication,\n '/' = division,\n " +
        "'d' = double translation,\n 'r' = reduction,\n" +
        "'i' = increase in the numerator and denominator n times\n";
}

bool FractionCalculator::validateNumberOfArguments(int argc,
    std::string str) {
    if (argc == 1) {
        help(str);
        return false;
    } else if (argc != 4 && (argc != 6 && argc != 5)) {
        help(str, "ERROR: Should be 3, 4 or 5 arguments.\n\n");
        return false;
    }
    return true;
}

std::string FractionCalculator::operator()(int argc, const char** argv) {
    if (!validateNumberOfArguments(argc, argv[0])) {
        return message_;
    }
    if (argc == 6) {
        FractionCalculator5Arg Calculater5;
        message_ = Calculater5(argv);
    } else if (argc == 5) {
        FractionCalculator4Arg Calculater4;
        message_ = Calculater4(argv);
    } else {
        FractionCalculator3Arg Calculater3;
        message_ = Calculater3(argv);
    }
    return message_;
}

char FractionCalculator5Arg::parseOperation(std::string str) {
    //'+', '-', '*', '/', '=', '>', '<'
    if (str.size() == 1) {
        char op = str[0];
        switch (op) {
        case '+':
            return '+';
        case '-':
            return '-';
        case '*':
            return '*';
        case '/':
            return '/';
        case '=':
            return '=';
        case '<':
            return '<';
        case '>':
            return '>';
        }
    }
    throw std::string("Wrong operation format!");
    return ' ';
}

char FractionCalculator4Arg::parseOperation(std::string str) {
    //'+', '-', '*', '/', 'i', '=', '>', '<'
    if (str.size() == 1) {
        char op = str[0];
        switch (op) {
        case '+':
            return '+';
        case '-':
            return '-';
        case '*':
            return '*';
        case '/':
            return '/';
        case 'i':
            return 'i';
        case '=':
            return '=';
        case '<':
            return '<';
        case '>':
            return '>';
        }
    }
    throw std::string("Wrong operation format!");
    return ' ';
}

char FractionCalculator3Arg::parseOperation(std::string str) {
    // 'd', 'r' '=', '>', '<'
    if (str.size() == 1) {
         char op = str[0];
        switch (op) {
        case 'd':
            return 'd';
        case 'r':
            return 'r';
        case '=':
            return '=';
        case '<':
            return '<';
        case '>':
            return '>';
        }
    }
    throw std::string("Wrong operation format!");
    return ' ';
}

std::string FractionCalculator5Arg::operator()(const char** argv) {
    char operation;
    Fraction f1;
    Fraction f2;

    try {
        f1 = Fraction(std::stoi(argv[1]), std::stoi(argv[2]));
        f2 = Fraction(std::stoi(argv[3]), std::stoi(argv[4]));
        operation = parseOperation(argv[5]);
    }
    catch (std::string& str) {
        return str;
    }
    catch (std::invalid_argument) {
        return std::string("Wrong number format!");
    }
    catch (std::out_of_range) {
        return std::string("Wrong number format!");
    }

    bool res;
    std::ostringstream stream;

    Fraction fr;

    //'+', '-', '*', '/', '=', '>', '<'
    switch (operation) {
    case '+':
        fr = f1 + f2;
        stream << "Numerator = " << fr.getNumerator() << " "
            << "Denominator = " << fr.getDenominator();
        break;
    case '-':
        fr = f1 - f2;
        stream << "Numerator = " << fr.getNumerator() << " "
            << "Denominator = " << fr.getDenominator();
        break;
    case '*':
        fr = f1 * f2;
        stream << "Numerator = " << fr.getNumerator() << " "
            << "Denominator = " << fr.getDenominator();
        break;
    case '/':
        try {
            fr = f1 / f2;
            stream << "Numerator = " << fr.getNumerator() << " "
                << "Denominator = " << fr.getDenominator();
            break;
        }
        catch (std::string& str) {
            return str;
        }
    case '<':
        res = f1 < f2;
        if (res)
            stream << "True";
        else
            stream << "False";
        break;
    case '>':
        res = f1 > f2;
        if (res)
            stream << "True";
        else
            stream << "False";
        break;
    case '=':
        res = f1 == f2;
        if (res)
            stream << "True";
        else
            stream << "False";
        break;
    }

    return std::string(stream.str());
}

std::string FractionCalculator4Arg::operator()(const char ** argv) {
    char operation;
    Fraction f1;
    int number;
    try {
        f1 = Fraction(std::stoi(argv[1]), std::stoi(argv[2]));
        number = std::stoi(argv[3]);
        operation = parseOperation(argv[4]);
    }
    catch (std::string& str) {
        return str;
    }
    catch (std::invalid_argument) {
        return std::string("Wrong number format!");
    }
    catch (std::out_of_range) {
        return std::string("Wrong number format!");
    }

    bool res;
    std::ostringstream stream;

    Fraction fr;

    //'+', '-', '*', '/', 'i', '=', '>', '<'
    switch (operation) {
    case '+':
        fr = f1 + number;
        stream << "Numerator = " << fr.getNumerator() << " "
            << "Denominator = " << fr.getDenominator();
        break;
    case '-':
        fr = f1 - number;
        stream << "Numerator = " << fr.getNumerator() << " "
            << "Denominator = " << fr.getDenominator();
        break;
    case '*':
        fr = f1 * number;
        stream << "Numerator = " << fr.getNumerator() << " "
            << "Denominator = " << fr.getDenominator();
        break;
    case '/':
        try {
            fr = f1 / number;
            stream << "Numerator = " << fr.getNumerator() << " "
                << "Denominator = " << fr.getDenominator();
            break;
        }
        catch (std::string& str) {
            return str;
        }
    case 'i':
        try {
            f1.increaseIntegerTimes(number);
            stream << "Numerator = " << f1.getNumerator() << " "
                << "Denominator = " << f1.getDenominator();
            break;
        }
        catch (std::string& str) {
            return str;
        }
    case '<':
        fr.setNumerator(number);
        res = f1 < fr;
        if (res)
            stream << "True";
        else
            stream << "False";
        break;
    case '>':
        fr.setNumerator(number);
        res = f1 > fr;
        if (res)
            stream << "True";
        else
            stream << "False";
        break;
    case '=':
        fr.setNumerator(number);
        res = f1 == fr;
        if (res)
            stream << "True";
        else
            stream << "False";
        break;
    }

    return std::string(stream.str());
}

std::string FractionCalculator3Arg::operator()(const char ** argv) {
    char operation;
    Fraction f;
    try {
        f = Fraction(std::stoi(argv[1]), std::stoi(argv[2]));
        operation = parseOperation(argv[3]);
    }
    catch (std::string& str) {
        return str;
    }
    catch (std::invalid_argument) {
        return std::string("Wrong number format!");
    }
    catch (std::out_of_range) {
        return std::string("Wrong number format!");
    }

    bool res;
    std::ostringstream stream;
    double dres;

    // 'r', 'd', '=', '>', '<'
    switch (operation) {
    case 'r':
        f.fractionReduction();
        stream << "Numerator = " << f.getNumerator() << " "
            << "Denominator = " << f.getDenominator();
        break;
    case 'd':
        dres = f.operator double();
        stream << "Double fraction = " << dres;
        break;
    case '<':
        res = f.getNumerator() < f.getDenominator();
        if (res)
            stream << "Denominator is greater than Numerator";
        else
            stream << "Denominator is not greater than Numerator";
        break;
    case '>':
        res = f.getNumerator() > f.getDenominator();
        if (res)
            stream << "Numerator is greater than Denominator";
        else
            stream << "Numerator is not greater than Denominator";
        break;
    case '=':
        res = f.getNumerator() == f.getDenominator();
        if (res)
            stream << "Numerator is equal to Denominator";
        else
            stream << "Numerator is not equal to Denominator";
        break;
    }

    return std::string(stream.str());
}
