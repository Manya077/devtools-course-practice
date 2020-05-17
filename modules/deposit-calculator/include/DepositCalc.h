// Copyright 2020 Mikhail Zakharov & Kornev Nikita

#ifndef MODULES_DEPOSIT_CALCULATOR_INCLUDE_DEPOSITCALC_H_
#define MODULES_DEPOSIT_CALCULATOR_INCLUDE_DEPOSITCALC_H_

class DepositCalc {
    unsigned int depositAmount;
    unsigned int period;
    unsigned int rate;
    unsigned int depositWithRate;
    unsigned int interestCharges;

    const unsigned int maxPeriodDays = 1826;
 public:
    DepositCalc(unsigned const int _depositAmount = 1000,
      unsigned const int _period = 1, unsigned const int _rate = 1);
    void calc();
    void setDepositAmount(unsigned const int depositAmount);
    void setPeriod(unsigned const int period);
    void setRate(unsigned const int rate);
    unsigned int getDepositAmount() const;
    unsigned int getPeriod() const;
    unsigned int getRate() const;
    unsigned int getDepositWithRate() const;
    unsigned int getInterestCharges() const;
    unsigned int getMaxPeriodDays() const;
};

#endif  // MODULES_DEPOSIT_CALCULATOR_INCLUDE_DEPOSITCALC_H_
