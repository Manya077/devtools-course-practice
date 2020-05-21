// Copyright 2020 Golubeva Anna

#include "include/interpolation_search.h"
#include <random>
#include <iostream>
#include <vector>
#include <ctime>

std::vector<int> generateRandomVector(int size) {
  if (size <= 0) {
    throw "Invalid vector size";
  }
  std::mt19937 gen;
  gen.seed(static_cast<unsigned int>(time(0)));
  std::vector<int> vec = std::vector<int>(size, 0);
  for (int i = 0; i < size; ++i) {
    vec[i] = gen() % (100 - 4);
  }
  return vec;
}

int partition(std::vector<int> *vec, int left, int right) {
  if (left > right) {
    throw "Right should be greater then left";
  }
  if (left < 0 || right < 0) {
    throw "Right & left should be >= 0";
  }
  int pivot = (*vec)[right];
  int count = left;
  for (int j = left; j < right; j++) {
    if ((*vec)[j] <= pivot) {
      int temp = (*vec)[j];
      (*vec)[j] = (*vec)[count];
      (*vec)[count] = temp;
      count += 1;
    }
  }
  (*vec)[right] = (*vec)[count];
  (*vec)[count] = pivot;

  return count;
}

void quickSort(std::vector<int> *vec, int left, int right) {
  if (left < right) {
    int pivot = partition(vec, left, right);
    quickSort(vec, left, pivot - 1);
    quickSort(vec, pivot + 1, right);
  }
}

int interpolationSearch(std::vector<int> *vec, int val) {
  int left = 0;
  int size = static_cast<int>((*vec).size());
  if (size == 0) {
    throw "Vector size is 0";
  }
  int right = size - 1;

  if ((*vec)[right] == (*vec)[left]) {
    if ((*vec)[right] == val) {
      return right;
    } else {
      return -1;
    }
  }

  quickSort(vec, 0, size - 1);

  while ((*vec)[left] < val && (*vec)[right] > val) {
      int first = ((val - (*vec)[left]) * (right - left));
      int mid = left + first / ((*vec)[right] - (*vec)[left]);

      if ((*vec)[mid] < val) {
          left = mid + 1;
      } else if ((*vec)[mid] > val) {
          right = mid - 1;
      } else {
          return mid;
      }
    }

  if ((*vec)[left] == val) {
      return left;
  }
  if ((*vec)[right] == val) {
      return right;
  }

  return -1;
}
