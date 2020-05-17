// Copyright 2020 Vladislav Golubev

#include <vector>
#include <cmath>
#include "../include/distance_between_vectors.h"

Metrics::Metrics() : fst(std::vector<float>(1)),
                     sec(std::vector<float>(1)) {}

Metrics::Metrics(const std::vector<float>& _fst,
                 const std::vector<float>& _sec) {
    if (_fst.size() != _sec.size()) {
        throw "vectors of different dimensions";
    }
    fst = _fst;
    sec = _sec;
}

Metrics::~Metrics() {}

std::vector<float> Metrics::getFirst() const {
    return fst;
}

std::vector<float> Metrics::getSecond() const {
    return sec;
}

void Metrics::setFirst(const std::vector<float>& _fst) {
    if (fst.size() != _fst.size()) {
        throw "vectors of different dimensions";
    }
    fst = _fst;
}

void Metrics::setSecond(const std::vector<float>& _sec) {
    if (sec.size() != _sec.size()) {
        throw "vectors of different dimensions";
    }
    sec = _sec;
}

void Metrics::setBoth(const std::vector<float>& _fst,
                      const std::vector<float>& _sec) {
    if (_fst.size() != _sec.size()) {
        throw "both new vectors of different dimensions";
    }
    fst = _fst;
    sec = _sec;
}

double L1::getMetrics() const {
    double res = 0;
    for (std::size_t i = 0; i < fst.size(); ++i) {
        res += std::abs(fst[i] - sec[i]);
    }
    return res;
}

double L2::getMetrics() const {
    double res = 0;
    for (std::size_t i = 0; i < fst.size(); ++i) {
        res += (fst[i] - sec[i]) * (fst[i] - sec[i]);
    }
    return std::sqrt(res);
}

double L3::getMetrics() const {
    double res = 0;
    for (std::size_t i = 0; i < fst.size(); ++i) {
        res += std::pow(std::abs(fst[i] - sec[i]), 3);
    }
    return std::pow(res, 1.0 / 3.0);
}

double L4::getMetrics() const {
    double res = 0;
    for (std::size_t i = 0; i < fst.size(); ++i) {
        res += std::pow(fst[i] - sec[i], 4);
    }
    return std::pow(res, 1.0 / 4.0);
}

double LInf::getMetrics() const {
    double res = std::abs(fst[0] - sec[0]);
    for (std::size_t i = 1; i < fst.size(); ++i) {
        double curElem = std::abs(fst[i] - sec[i]);
        if (curElem > res) {
            res = curElem;
        }
    }
    return res;
}
