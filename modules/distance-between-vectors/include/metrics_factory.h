// Copyright 2020 Sokolov Andrey

#ifndef MODULES_DISTANCE_BETWEEN_VECTORS_INCLUDE_METRICS_FACTORY_H_
#define MODULES_DISTANCE_BETWEEN_VECTORS_INCLUDE_METRICS_FACTORY_H_
#include <string>
#include <vector>

#include "include/distance_between_vectors.h"

class MetricsFactory {
 public:
    static Metrics* create(const std::string& _operation);
    static Metrics* create(const std::string& _operation,
                           const std::vector<float>& _fst,
                           const std::vector<float>& _sec);
};

#endif  // MODULES_DISTANCE_BETWEEN_VECTORS_INCLUDE_METRICS_FACTORY_H_
