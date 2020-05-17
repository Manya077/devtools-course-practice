// Copyright 2020 Brazhnikov Eugene

#ifndef MODULES_MONEY_CONVERTER_INCLUDE_MONEY_CONVERTER_H_
#define MODULES_MONEY_CONVERTER_INCLUDE_MONEY_CONVERTER_H_

extern const double dollarCurr;
extern const double eurRate;
extern const double jpyRate;
extern const double sekRate;
extern const double uahRate;

class MoneyConverter {
 public:
     double rubUSD(const double& curr, bool whichone);
     double rubEUR(const double& curr, bool whichone);
     double rubJPY(const double& curr, bool whichone);
     double rubSEK(const double& curr, bool whichone);
     double rubUAH(const double& curr, bool whichone);
};

#endif  // MODULES_MONEY_CONVERTER_INCLUDE_MONEY_CONVERTER_H_
