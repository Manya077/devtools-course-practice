// Copyright 2020 Brazhnikov Eugene

#include "include/length_converter.h"

double LengthConverter::m_kmeter(const double& curr, bool side) {
    if (curr >= 0 && side == false)   // meter to kilometer
        return curr / 1000;
    if (curr >= 0 && side == true)   // kilometer to meter
        return curr * 1000;
    return -1;
}

double LengthConverter::m_smeter(const double& curr, bool side) {
    if (curr >= 0 && side == false)
        return curr * 100;
    if (curr >= 0 && side == true)
        return curr / 100;
    return -1;
}

double LengthConverter::m_mile(const double& curr, bool side) {
    if (curr >= 0 && side == false)
        return curr * 0.000621371;
    if (curr >= 0 && side == true)
        return curr / 0.000621371;
    return -1;
}

double LengthConverter::m_yard(const double& curr, bool side) {
    if (curr >= 0 && side == false)
        return curr * 1.09361;
    if (curr >= 0 && side == true)
        return curr / 1.09361;
    return -1;
}

double LengthConverter::m_ft(const double& curr, bool side) {
    if (curr >= 0 && side == false)
        return curr * 3.28084;
    if (curr >= 0 && side == true)
        return curr / 3.28084;
    return -1;
}

double LengthConverter::m_inch(const double& curr, bool side) {
    if (curr >= 0 && side == false)
        return curr * 39.3701;
    if (curr >= 0 && side == true)
        return curr / 39.3701;
    return -1;
}
