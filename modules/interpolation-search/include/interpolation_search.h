// Copyright 2020 Golubeva Anna

#ifndef MODULES_INTERPOLATION_SEARCH_INCLUDE_INTERPOLATION_SEARCH_H_
#define MODULES_INTERPOLATION_SEARCH_INCLUDE_INTERPOLATION_SEARCH_H_

#include <stdio.h>
#include <vector>

std::vector<int> generateRandomVector(int size);
int partition(std::vector<int> *vec, int left, int right);
int interpolationSearch(std::vector<int> *vec, int val);
void quickSort(std::vector<int> *vec, int left, int right);

#endif  // MODULES_INTERPOLATION_SEARCH_INCLUDE_INTERPOLATION_SEARCH_H_
