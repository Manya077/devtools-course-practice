// Copyright 2020 Golovanova Elena

#ifndef MODULES_QUICK_SORT_INCLUDE_QUICK_SORT_H_
#define MODULES_QUICK_SORT_INCLUDE_QUICK_SORT_H_

#include <vector>

class QuickSort {
 private:
  std::vector<int> vector;
  int GetIndex(int _first, int _last);
 public:
  explicit QuickSort(std::vector<int>_vector);
  std::vector<int> GetVector()const;
  void QSort(int _first, int _last);
};

#endif  // MODULES_QUICK_SORT_INCLUDE_QUICK_SORT_H_
