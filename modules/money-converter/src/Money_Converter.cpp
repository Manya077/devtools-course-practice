// Copyright 2020 Brazhnikov Eugene

#include "include/Money_Converter.h"

const double dollarRate = 77.73;
const double eurRate = 85.73;
const double jpyRate = 71.40;
const double sekRate = 78;
const double uahRate = 2.79;

double MoneyConverter::rubUSD(const double& curr, bool  whichone) {
    if (curr >= 0 && whichone == 0)
        return curr / dollarRate;
    else if (curr >= 0 && whichone == 1)
        return curr * dollarRate;
    else
        return -1;
}

double MoneyConverter::rubEUR(const double& curr, bool whichone) {
    if (curr >= 0 && whichone == 0)
        return curr / eurRate;
    else if (curr >= 0 && whichone == 1)
        return curr * eurRate;
    else
        return -1;
}

double MoneyConverter::rubJPY(const double& curr, bool whichone) {
    if (curr >= 0 && whichone == 0)
        return curr / jpyRate;
    else if (curr >= 0 && whichone == 1)
        return curr * jpyRate;
    else
        return -1;
}

double MoneyConverter::rubSEK(const double& curr, bool whichone) {
    if (curr >= 0 && whichone == 0)
        return curr / sekRate;
    else if (curr >= 0 && whichone == 1)
        return curr * sekRate;
    else
        return -1;
}

double MoneyConverter::rubUAH(const double& curr, bool whichone) {
    if (curr >= 0 && whichone == 0)
        return curr / uahRate;
    else if (curr >= 0 && whichone == 1)
        return curr * uahRate;
    else
        return -1;
}
