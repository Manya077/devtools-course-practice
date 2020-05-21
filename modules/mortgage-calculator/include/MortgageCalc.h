// Copyright 2020 Petrov Anton & Savin Dmitry

#ifndef MODULES_MORTGAGE_CALCULATOR_INCLUDE_MORTGAGECALC_H_
#define MODULES_MORTGAGE_CALCULATOR_INCLUDE_MORTGAGECALC_H_

class MortgageCalc {
    int cost;
    int downPayment;
    int creditTerm;
    double interestRate;
    int totalFee;
    double monthlyPayment;
    double monthlyRate;
 public:
    MortgageCalc(int _cost, int _downPayment,
        int _creditTerm, double _interestRate);
    void calc();
    void setCost(const int& cost);
    void setDownPayment(const int& cost);
    void setCreditTerm(const int& cost);
    void setInterestRate(const double& cost);
    int getCost() const;
    int getDownPayment() const;
    int getCreditTerm() const;
    double getInterestRate() const;
    int getTotalFee() const;
    double getMonthlyRate() const;
    int getMonthlyPayment() const;
};

#endif  // MODULES_MORTGAGE_CALCULATOR_INCLUDE_MORTGAGECALC_H_
