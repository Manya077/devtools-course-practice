// Copyright 2020  Baldin Alexey & completed Sokolov Nikolay

#include "include/fraction.h"
#include <string>
#include <iostream>

Fraction::Fraction(const int& num, const int& den) {
    if (den == 0) {
        denominator_ = 1;
        throw std::string("Denominator can`t be zero. Use denominator = 1");
    } else if (den < 0) {
        numerator_ = -num;
        denominator_ = -den;
    } else {
        numerator_ = num;
        denominator_ = den;
    }
}

Fraction::Fraction(const Fraction & f) {
    this->numerator_ = f.numerator_;
    this->denominator_ = f.denominator_;
}

int Fraction::getNumerator() const {
    return numerator_;
}

int Fraction::getDenominator() const {
    if (numerator_ == 0) {
        throw std::string("Nominator = 0. Denominator don`t need.");
    } else {
        return denominator_;
    }
}

void Fraction::setNumerator(const int& num) {
    numerator_ = num;
}

void Fraction::setDenominator(const int& den) {
    if (den == 0) {
        denominator_ = 1;
        throw std::string("Denominator can`t be zero. Use denominator = 1");
    } else if (den < 0) {
        numerator_ = -numerator_;
        denominator_ = -den;
    } else {
        denominator_ = den;
    }
}

bool Fraction::operator==(const Fraction & f) const {
    Fraction f1(this->getNumerator(), this->getDenominator());
    Fraction f2(f.getNumerator(), f.getDenominator());

    f1.fractionReduction();
    f2.fractionReduction();

    return f1.getNumerator() == f2.getNumerator() &&
           f1.getDenominator() == f2.getDenominator();
}

bool Fraction::operator!=(const Fraction & f) const {
    Fraction f1(this->getNumerator(), this->getDenominator());
    Fraction f2(f.getNumerator(), f.getDenominator());

    f1.fractionReduction();
    f2.fractionReduction();

    return f1.getNumerator() != f2.getNumerator() ||
           f1.getDenominator() != f2.getDenominator();
}

void Fraction::fractionReduction() {
    int nodND = nod(numerator_, denominator_);

    if (nodND != 1) {
        numerator_ = numerator_ / nodND;
        denominator_ = denominator_ / nodND;
    }
}

Fraction Fraction::operator+(const Fraction & f) const {
    int num = this->getNumerator() * f.getDenominator() +
              this->getDenominator() * f.getNumerator();
    int den = this->getDenominator() * f.getDenominator();

    Fraction sum(num, den);
    sum.fractionReduction();

    return sum;
}

Fraction Fraction::operator-(const Fraction & f) const {
    int num = this->getNumerator() * f.getDenominator() -
        this->getDenominator() * f.getNumerator();
    int den = this->getDenominator() * f.getDenominator();

    Fraction dif(num, den);
    dif.fractionReduction();

    return dif;
}

Fraction Fraction::operator*(const Fraction & f) const {
    int num = this->getNumerator() * f.getNumerator();
    int den = this->getDenominator() * f.getDenominator();

    Fraction mult(num, den);
    mult.fractionReduction();

    return mult;
}

Fraction Fraction::operator/(const Fraction & f) const {
    if (f.getNumerator() != 0) {
        int num = this->getNumerator() * f.getDenominator();
        int den = this->getDenominator() * f.getNumerator();

        Fraction division(num, den);
        division.fractionReduction();

        return division;
    } else {
        throw std::string("Numerator divider can`t be zero");
    }
    return Fraction();
}

Fraction Fraction::operator+(const int & n) const {
    int num = this->getNumerator() + this->getDenominator() * n;

    Fraction sum(num, this->getDenominator());
    sum.fractionReduction();

    return sum;
}

Fraction Fraction::operator-(const int & n) const {
    int num = this->getNumerator() - this->getDenominator() * n;

    Fraction dif(num, this->getDenominator());
    dif.fractionReduction();

    return dif;
}

Fraction Fraction::operator*(const int & n) const {
    int num = this->getNumerator() * n;

    Fraction mult(num, this->getDenominator());
    mult.fractionReduction();

    return mult;
}

Fraction Fraction::operator/(const int & n) const {
    if (n != 0) {
        int den = this->getDenominator() * n;

        Fraction division(this->getNumerator(), den);
        division.fractionReduction();

        return division;
    } else {
        throw std::string("Divider can`t be zero");
    }
    return Fraction();
}

Fraction& Fraction::operator=(const Fraction & f) {
    this->numerator_ = f.numerator_;
    this->denominator_ = f.denominator_;

    return *this;
}

Fraction::operator double() const {
    return static_cast<double>(numerator_) / denominator_;
}

bool Fraction::operator>(const Fraction & f) {
    double f1 = *this;
    double f2 = f;

    return f1 > f2;
}

bool Fraction::operator>=(const Fraction & f) {
    double f1 = *this;
    double f2 = f;

    return f1 >= f2;
}

bool Fraction::operator<(const Fraction & f) {
    double f1 = *this;
    double f2 = f;

    return f1 < f2;
}

bool Fraction::operator<=(const Fraction & f) {
    double f1 = *this;
    double f2 = f;

    return f1 <= f2;
}

int Fraction::changeDenominator(const int & den) {
    if (denominator_ < den && den % denominator_ == 0) {
        denominator_ = den;
        numerator_ *= (den / denominator_);
    } else if (denominator_ > den && denominator_ % den == 0 &&
               numerator_ % (denominator_ / den) == 0) {
        numerator_ /= denominator_ / den;
        denominator_ = den;
    } else {
        throw std::string("Can`t change denominator for this fraction.");
    }
    return 0;
}

void Fraction::increaseIntegerTimes(int n) {
    if (n != 0) {
        numerator_ *= n;
        denominator_ *= n;
    } else {
        throw std::string("Argument is Zero");
    }
}

int nod(int a, int b) {
    if (a < 0) {
        a = -a;
    }
    if (b < 0) {
        b = -b;
    }

    while (a && b) {
        if (a >= b) {
            a = a % b;
        } else {
            b = b % a;
        }
    }

    if (a == 0) {
        return b;
    } else {
        return a;
    }
}

Fraction operator+(const int & n, const Fraction & f) {
    return f + n;
}

Fraction operator-(const int & n, const Fraction & f) {
    int num = f.getDenominator() * n - f.getNumerator();

    Fraction dif(num, f.getDenominator());
    dif.fractionReduction();

    return dif;
}

Fraction operator*(const int & n, const Fraction & f) {
    return f * n;
}

Fraction operator/(const int & n, const Fraction & f) {
    int num = f.getDenominator() * n;

    Fraction division(num, f.getNumerator());
    division.fractionReduction();

    return division;
}
