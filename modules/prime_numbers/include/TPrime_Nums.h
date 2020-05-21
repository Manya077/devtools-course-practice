// Copyright 2020 Kuzhelev Anton & Dobrohotov Vitaly

#ifndef MODULES_PRIME_NUMBERS_INCLUDE_TPRIME_NUMS_H_
#define MODULES_PRIME_NUMBERS_INCLUDE_TPRIME_NUMS_H_

#include <vector>
#include <utility>

class TPrime_Nums {
 public:
    TPrime_Nums(int left, int right);
    std::pair<int, int> GetInterval();
    std::vector<unsigned int> Get_Prime_Nums();
    void SetInterval(std::pair<int, int> interval);
 private:
    unsigned int left_edge, right_edge;
};

#endif  // MODULES_PRIME_NUMBERS_INCLUDE_TPRIME_NUMS_H_
