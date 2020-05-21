// Copyright 2020 Brazhnikov Eugene

#include "include/Money_Converter.h"

double result = -1;

double MoneyConverter::rubUSD(const double& curr, bool  whichone) {
    if (curr < 0) return result;
    if (whichone)
       return curr * 77.73;
    else
        return curr / 77.73;
}

double MoneyConverter::rubEUR(const double& curr, bool whichone) {
    if (curr < 0) return result;
    if (whichone)
        return curr * 85.73;
    else
        return curr / 85.73;
}

double MoneyConverter::rubJPY(const double& curr, bool whichone) {
    if (curr < 0) return result;
    if (whichone)
        return curr * 0.69;
    else
        return curr / 0.69;
}

double MoneyConverter::rubSEK(const double& curr, bool whichone) {
    if (curr < 0) return result;
    if (whichone)
        return curr * 7.45;
    else
        return curr / 7.45;
}

double MoneyConverter::rubUAH(const double& curr, bool whichone) {
    if (curr < 0) return result;
    if (whichone)
        return curr * 2.79;
    else
        return curr / 2.79;
}
