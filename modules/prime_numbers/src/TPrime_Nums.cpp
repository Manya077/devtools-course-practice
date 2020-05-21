// Copyright 2020 Kuzhelev Anton & Dobrohotov Vitaly

#include <utility>
#include <vector>
#include "include/TPrime_Nums.h"

TPrime_Nums::TPrime_Nums(int left = 0, int right = 0) {
    if (left < 0 || right < 0 || left > right) {
        throw -1;
    }
    left_edge = left;
    right_edge = right;
}

void TPrime_Nums::SetInterval(std::pair<int, int> interval) {
    if (interval.first < 0 || interval.second < 0
        || interval.first > interval.second) {
        throw -1;
    }
    left_edge = interval.first;
    right_edge = interval.second;
}

std::pair<int, int> TPrime_Nums::GetInterval() {
    return std::make_pair(left_edge, right_edge);
}

std::vector<unsigned int> TPrime_Nums::Get_Prime_Nums() {
    std::vector<unsigned int> result;

    for (unsigned int i = left_edge; i <= right_edge; ++i) {
        unsigned int j;
        for (j = 2; j < i; ++j) {
            if (i % j == 0) {
                break;
            }
        }
        if (j == i) {
            result.push_back(i);
        }
    }
    return result;
}
