// Copyright 2020 Zinkov Artem

#ifndef MODULES_ODD_EVEN_BATCHER_MERGE_INCLUDE_ODD_EVEN_BATCHER_MERGE_H_
#define MODULES_ODD_EVEN_BATCHER_MERGE_INCLUDE_ODD_EVEN_BATCHER_MERGE_H_

#include <vector>

std::vector<int> merge_batcher(const std::vector<int>& vec1,
    const std::vector<int>& vec2);
std::vector<int> shuffle(const std::vector<int>& vec);
std::vector<int> merge_odd_even(const std::vector<int>& vec1,
    const std::vector<int>& vec2);
std::vector<int> unshuffle(const std::vector<int>& odd,
    const std::vector<int>& even);

#endif  // MODULES_ODD_EVEN_BATCHER_MERGE_INCLUDE_ODD_EVEN_BATCHER_MERGE_H_
