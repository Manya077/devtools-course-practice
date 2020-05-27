// Copyright 2020 Tihomirova Mariya

#ifndef MODULES_SEARCH_BINARY_INCLUDE_SEARCH_BINARY_H_
#define MODULES_SEARCH_BINARY_INCLUDE_SEARCH_BINARY_H_

#include "vector"

class SearchBinary {
 public:
    static int Search(const int key, const int *arr, const int size);
    static int Search(const int key, const std::vector<int> arr);
};

#endif  // MODULES_SEARCH_BINARY_INCLUDE_SEARCH_BINARY_H_
