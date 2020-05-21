// Copyright 2020 Golovanova Elena

#include <gtest/gtest.h>
#include <vector>
#include "include/quick_sort.h"

TEST(Golovanova_Elena_QuickSortTest, Assignment_Vector) {
  // Arrange
  std::vector<int> example = { 4, 6, 6, 9, 1 };
  // Act
  QuickSort Elementary(example);
  // Assert
  ASSERT_EQ(example, Elementary.GetVector());
}

TEST(Golovanova_Elena_QuickSortTest, Sort_Works) {
  // Arrange
  std::vector<int> wait = { 1, 3, 5, 6 };
  // Act
  QuickSort Elementary(wait);
  Elementary.QSort(0, 3);
  // Assert
  ASSERT_EQ(wait, Elementary.GetVector());
}
