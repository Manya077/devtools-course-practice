// Copyright 2020 Petrov Anton

#include "include/MortgageCalc.h"
#include <cmath>

MortgageCalc::MortgageCalc(int _cost, int _downPayment,
    int _creditTerm, double _interestRate) :cost(_cost),
    downPayment(_downPayment), creditTerm(_creditTerm),
    interestRate(_interestRate) {}

int MortgageCalc::getCost() const {
    return cost;
}

int MortgageCalc::getDownPayment() const {
    return downPayment;
}

int MortgageCalc::getCreditTerm() const {
    return creditTerm;
}

double MortgageCalc::getInterestRate() const {
    return interestRate;
}

int MortgageCalc::getTotalFee() const {
    return totalFee;
}

double MortgageCalc::getMonthlyRate() const {
    return monthlyRate;
}

int MortgageCalc::getMonthlyPayment() const {
    return monthlyPayment;
}

void MortgageCalc::setCost(const int& cost) {
    this->cost = cost;
}

void MortgageCalc::setDownPayment(const int& downPayment) {
    this->downPayment = downPayment;
}

void MortgageCalc::setCreditTerm(const int& creditTerm) {
    this->creditTerm = creditTerm;
}

void MortgageCalc::setInterestRate(const double& interestRate) {
    this->interestRate = interestRate;
}

void MortgageCalc::calc() {
    cost -= downPayment;
    creditTerm *= 12;
    monthlyRate = ((interestRate) / 100) / 12;
    double tmp = pow((1 + monthlyRate), creditTerm);
    monthlyPayment = cost * monthlyRate * (tmp / (tmp - 1));
    totalFee = monthlyPayment * creditTerm;
}
