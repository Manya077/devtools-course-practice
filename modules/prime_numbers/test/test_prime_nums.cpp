// Copyright 2020 Kuzhelev Anton

#include <gtest/gtest.h>

#include <utility>
#include <vector>
#include "include/TPrime_Nums.h"

bool compare_vec(std::vector<unsigned int> v1, std::vector<unsigned int> v2) {
    if (v1.size() != v2.size()) {
        return false;
    }

    for (size_t i = 0; i < v1.size(); ++i) {
        if (v1[i] != v2[i]) {
            return false;
        }
    }
    return true;
}

TEST(TPrime_Nums, can_create_default_class) {
    // Arrange, Act and Assert
    ASSERT_NO_THROW(TPrime_Nums p());
}

TEST(TPrime_Nums, can_create_class_with_valid_parameters) {
    // Arrange, Act and Assert
    ASSERT_NO_THROW(TPrime_Nums p(3, 5));
}

TEST(TPrime_Nums, cannot_create_class_with_negative_piece) {
    // Arrange, Act and Assert
    ASSERT_ANY_THROW(TPrime_Nums p(-5, -3));
}

TEST(TPrime_Nums, cannot_create_class_with_negative_left_side) {
    // Arrange, Act and Assert
    ASSERT_ANY_THROW(TPrime_Nums p(-3, 6));
}

TEST(TPrime_Nums, cannot_create_class_if_left_is_bigger_than_right) {
    // Arrange, Act and Assert
    ASSERT_ANY_THROW(TPrime_Nums p(5, 2));
}

TEST(TPrime_Nums, check_that_values_on_correct_position) {
    // Arrange
    TPrime_Nums p(3, 5);
    // Act
    std::pair<int, int> val = p.GetInterval();
    // Assert
    EXPECT_EQ(3, val.first);
    EXPECT_EQ(5, val.second);
}

TEST(TPrime_Nums, check_that_do_not_change_left_edge) {
    // Arrange
    TPrime_Nums p(0, 3);
    // Act
    p.Get_Prime_Nums();
    // Assert
    EXPECT_EQ(0, (p.GetInterval()).first);
}

TEST(TPrime_Nums, check_that_can_set_interval_by_setter) {
    // Arrange
    TPrime_Nums p(0, 1);
    // Act and Assert
    ASSERT_NO_THROW(p.SetInterval(std::make_pair(0, 10)));
}

TEST(TPrime_Nums, check_that_cannot_set_negative_interval) {
    // Arrange
    TPrime_Nums p(0, 1);
    // Act and Assert
    ASSERT_ANY_THROW(p.SetInterval(std::make_pair(-5, -3)));
}

TEST(TPrime_Nums, check_that_cannpt_set_left_edge_bigger_than_right) {
    // Arrange
    TPrime_Nums p(0, 1);
    // Act and Assert
    ASSERT_ANY_THROW(p.SetInterval(std::make_pair(5, 3)));
}

TEST(TPrime_Nums, check_that_change_interval_by_setter) {
    // Arrange
    TPrime_Nums p(0, 1);
    // Act
    p.SetInterval(std::make_pair(5, 10));
    std::pair<int, int> interval = p.GetInterval();
    // Assert
    EXPECT_EQ(5, interval.first);
    EXPECT_EQ(10, interval.second);
}

TEST(TPrime_Nums, check_that_no_primes_on_0_to_1) {
    // Arrange
    TPrime_Nums p(0, 1);
    // Act
    std::vector<unsigned int> primes = p.Get_Prime_Nums();
    // Assert
    EXPECT_EQ(0, primes.size());
}

TEST(TPrime_Nums, check_interval_7_7) {
    // Arrange
    TPrime_Nums p(7, 7);
    // Act
    std::vector<unsigned int> result = p.Get_Prime_Nums();
    // Assert
    EXPECT_EQ(7, result[0]);
}

TEST(TPrime_Nums, check_prime_nums_from_0_to_10) {
    // Arrange
    TPrime_Nums p(0, 10);
    // Act
    std::vector<unsigned int> res = p.Get_Prime_Nums();
    std::vector<unsigned int> tmp = {2, 3, 5, 7};
    // Assert
    EXPECT_TRUE(compare_vec(res, tmp));
}

TEST(TPrime_Nums, check_no_prime_nums_between_212_to_222) {
    // Arrange
    TPrime_Nums p(212, 222);
    // Act
    std::vector<unsigned int> res = p.Get_Prime_Nums();
    // Assert
    EXPECT_EQ(0, res.size());
}
