// Copyright 2020 Guschin Alexander

#include <gtest/gtest.h>

#include <vector>
#include "include/radix_sort.h"

TEST(RadixSortTest, Can_Fill_Array) {
  // Arrange
  std::vector<std::int32_t> vec(3, 0);
  std::vector<std::int32_t> old_vec(3, 0);

  // Act
  FillRandom(&vec);

  // Assert
  EXPECT_TRUE(vec != old_vec);
}

TEST(RadixSortTest, Can_Find_Unsorted_Array) {
  // Arrange
  std::vector<std::int32_t> vec = {1, 4, 2};

  // Act
  bool result = IsSorted(vec);

  // Assert
  EXPECT_FALSE(result);
}

TEST(RadixSortTest, Can_Find_Sorted_Array) {
  // Arrange
  std::vector<std::int32_t> vec = {1, 2, 4};

  // Act
  bool result = IsSorted(vec);

  // Assert
  EXPECT_TRUE(result);
}

TEST(RadixSortTest, Can_Sort_Sorted_Array) {
  // Arrange
  std::vector<std::int32_t> vec = {1, 2, 4};
  std::vector<std::int32_t> expected_vec = {1, 2, 4};
  std::vector<std::int32_t> tmp_vec;

  // Act
  tmp_vec = RadixSort(vec);

  // Assert
  EXPECT_EQ(expected_vec, tmp_vec);
}

TEST(RadixSortTest, Can_Sort_Unsorted_Array) {
  // Arrange
  std::vector<std::int32_t> vec = {1, 2, 4};
  std::vector<std::int32_t> expected_vec = {1, 2, 4};
  std::vector<std::int32_t> tmp_vec;

  // Act
  tmp_vec = RadixSort(vec);

  // Assert
  EXPECT_EQ(expected_vec, tmp_vec);
}

TEST(RadixSortTest, Can_Sort_Unsorted_Array_With_Negative_Numbers) {
  // Arrange
  std::vector<std::int32_t> vec = {
      -32, 332, 1 << 28, -8, 1 << 26, -(1 << 26), -24, -(1 << 27), 1111};
  std::vector<std::int32_t> expected_vec = {
      -(1 << 27), -(1 << 26), -32, -24, -8, 332, 1111, 1 << 26, 1 << 28};

  // Act
  std::vector<std::int32_t> res(RadixSort(vec));

  // Assert
  EXPECT_EQ(expected_vec, res);
}

TEST(RadixSortTest, Can_Sort_Unsorted_Array_With_Random_Numbers) {
  // Arrange
  std::vector<std::int32_t> vec(100, 0);
  FillRandom(&vec);

  // Act
  bool result = IsSorted(RadixSort(vec));

  // Assert
  EXPECT_TRUE(result);
}
