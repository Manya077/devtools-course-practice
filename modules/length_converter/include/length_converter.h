// Copyright 2020 Brazhnikov Eugene
#ifndef MODULES_LENGTH_CONVERTER_INCLUDE_LENGTH_CONVERTER_H_
#define MODULES_LENGTH_CONVERTER_INCLUDE_LENGTH_CONVERTER_H_

class LengthConverter {
 private:
    double curr;
    bool side;
 public:
    LengthConverter() : curr(0), side(false) {}
    LengthConverter(double currency, bool amount)
        : curr(currency), side(amount) {}
    static double m_kmeter(const double& curr, bool side);
    static double m_smeter(const double& curr, bool side);
    static double m_mile(const double& curr, bool side);
    static double m_yard(const double& curr, bool side);
    static double m_ft(const double& curr, bool side);
    static double m_inch(const double& curr, bool side);
};

#endif  // MODULES_LENGTH_CONVERTER_INCLUDE_LENGTH_CONVERTER_H_
