// Copyright 2020  Baldin Alexey & completed Sokolov Nikolay

#ifndef MODULES_FRACTION_INCLUDE_FRACTION_H_
#define MODULES_FRACTION_INCLUDE_FRACTION_H_

class Fraction {
 private:
    int numerator_;
    int denominator_;

 public:
    explicit Fraction(const int& nom = 0, const int& den = 1);
    Fraction(const Fraction& f);

    int getNumerator() const;
    int getDenominator() const;

    void setNumerator(const int& nom);
    void setDenominator(const int& den);

    bool operator ==(const Fraction& f) const;
    bool operator !=(const Fraction& f) const;

    void fractionReduction();

    Fraction operator +(const Fraction& f) const;
    Fraction operator -(const Fraction& f) const;
    Fraction operator *(const Fraction& f) const;
    Fraction operator /(const Fraction& f) const;

    Fraction operator +(const int& n) const;
    Fraction operator -(const int& n) const;
    Fraction operator *(const int& n) const;
    Fraction operator /(const int& n) const;

    Fraction& operator=(const Fraction& f);

    operator double() const;

    bool operator>(const Fraction& f);
    bool operator>=(const Fraction& f);
    bool operator<(const Fraction& f);
    bool operator<=(const Fraction& f);

    int changeDenominator(const int& den);

    void increaseIntegerTimes(int n);
};

int nod(int a, int b);

Fraction operator +(const int& n, const Fraction& f);
Fraction operator -(const int& n, const Fraction& f);
Fraction operator *(const int& n, const Fraction& f);
Fraction operator /(const int& n, const Fraction& f);

#endif  // MODULES_FRACTION_INCLUDE_FRACTION_H_
