// Copyright 2020 Dobrohotov Vitaly

#include <iostream>
#include <string>

#include "include/prime_nums_for_app.h"

int main(int argc, const char** argv) {
    PrimeNums prime_nums;
    std::cout << prime_nums(argc, argv) << std::endl;
    return 0;
}
