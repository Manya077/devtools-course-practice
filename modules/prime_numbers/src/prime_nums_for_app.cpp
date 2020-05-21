// Copyright 2020 Dobrohotov Vitaly

#include <string>
#include <vector>

#include "include/prime_nums_for_app.h"
#include "include/TPrime_Nums.h"

PrimeNums::PrimeNums() : message_("") {}

void PrimeNums::help(const char* appname, const char* error_message) {
    message_ = std::string(std::string(error_message)) +
        "This is a primary numbers application.\n" +
        "Please provide arguments in the following format:\n" +
        "<left border> <right border>\n" +
        "Where all arguments are int numbers,\n" +
        "left border less than right border,\n" +
        "both of border not equal null,\n"+
        "and must be possitive number";
}

bool PrimeNums::checkArgs(int argc, const char** argv) {
    int a, b;
    if (argc != 3) {
        help(argv[0], "ERROR: Should be 2 arguments\n");
        return false;
    }
    a = atoi(argv[1]);
    b = atoi(argv[2]);
    if (a < 0) {
        help(argv[0], "ERROR: Left border can't be less than zero\n");
        return false;
    }
    if (a > b) {
        help(argv[0], "ERROR: Left border must be less than right\n");
        return false;
    } else if (a == 0 || b == 0) {
        help(argv[0], "ERROR: incorrect input data\n");
        return false;
    }
    return true;
}

std::string PrimeNums::operator()(int argc, const char** argv) {
    int a;
    int b;
    if (!checkArgs(argc, argv)) {
        return message_;
    }
    a = atoi(argv[1]);
    b = atoi(argv[2]);
    TPrime_Nums pn(a, b);
    std::vector <unsigned int> v = pn.Get_Prime_Nums();
    message_ = "Interval: " + std::to_string(pn.GetInterval().first) +"-" +
        std::to_string(pn.GetInterval().second) + "\nPrimary numbers: ";
    for (auto i : v) {
       message_ += std::to_string(i) + " ";
    }
    return message_;
}
