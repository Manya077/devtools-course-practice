// Copyright 2020 Golubeva Anna

#include <gtest/gtest.h>
#include <vector>
#include "include/interpolation_search.h"

TEST(InterpolationSearchTest, can_generate_vector) {
  // Arrange
  int size = 5;

  // Act
  std::vector<int> vec(5);

  // Assert
  ASSERT_NO_THROW(vec = generateRandomVector(size));
}

TEST(InterpolationSearchTest, throw_when_invalid_size) {
  // Arrange
  int size = -5;

  // Act && Assert
  ASSERT_ANY_THROW(std::vector<int> vec = generateRandomVector(size));
}

TEST(InterpolationSearchTest, throw_when_size_0) {
  // Arrange
  int size = 0;

  // Act && Assert
  ASSERT_ANY_THROW(std::vector<int> vec = generateRandomVector(size));
}

TEST(InterpolationSearchTest, throw_when_vec_size_0_interpolation_search) {
  // Arrange
  std::vector<int> vec;

  // Act && Assert
  ASSERT_ANY_THROW(int result = interpolationSearch(&vec, 3));
}

TEST(InterpolationSearchTest, partition_works) {
  // Arrange
  int size = 10;

  // Act
  std::vector<int> vec = generateRandomVector(size);

  // Assert
  ASSERT_NO_THROW(int result = partition(&vec, 0, size - 1));
}

TEST(InterpolationSearchTest, throw_when_partition_boarders_are_negative) {
  // Arrange
  int size = 10;

  // Act
  std::vector<int> vec = generateRandomVector(size);

  // Assert
  ASSERT_ANY_THROW(int result = partition(&vec, -2, -3));
}

TEST(InterpolationSearchTest, throw_when_partition_right_boarder_is_negative) {
  // Arrange
  int size = 10;

  // Act
  std::vector<int> vec = generateRandomVector(size);

  // Assert
  ASSERT_ANY_THROW(int result = partition(&vec, -2, 5));
}

TEST(InterpolationSearchTest, throw_when_partition_left_boarder_is_negative) {
  // Arrange
  int size = 10;

  // Act
  std::vector<int> vec = generateRandomVector(size);

  // Assert
  ASSERT_ANY_THROW(int result = partition(&vec, 2, -3));
}

TEST(InterpolationSearchTest, throw_when_partition_boarders_min_greater_max) {
  // Arrange
  int size = 10;

  // Act
  std::vector<int> vec = generateRandomVector(size);

  // Assert
  ASSERT_ANY_THROW(int result = partition(&vec, 5, 2));
}

TEST(InterpolationSearchTest, partition_result_is_positive) {
  // Arrange
  int size = 10;

  // Act
  std::vector<int> vec = generateRandomVector(size);

  // Assert
  ASSERT_LE(0, partition(&vec, 0, size - 1));
}

TEST(InterpolationSearchTest, interpolation_search_works) {
  // Arrange
  int size = 10;

  // Act
  std::vector<int> vec = generateRandomVector(size);

  // Assert
  ASSERT_NO_THROW(int result = interpolationSearch(&vec, vec[3]));
}

TEST(InterpolationSearchTest, interpolation_search_works_correctly) {
  // Arrange
  std::vector<int> vec = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  // Act && Assert
  EXPECT_EQ(3, interpolationSearch(&vec, 3));
}

TEST(InterpolationSearchTest, interpolation_search_value_exists) {
  // Arrange
  int size = 10;

  // Act
  std::vector<int> vec = generateRandomVector(size);

  // Assert
  ASSERT_LE(0, interpolationSearch(&vec, vec[5]));
}

TEST(InterpolationSearchTest, interpolation_search_value_does_not_exist) {
  // Arrange
  std::vector<int> vec = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  // Act && Assert
  ASSERT_GE(0, interpolationSearch(&vec, 100));
}

TEST(InterpolationSearchTest, returns_right) {
  // Arrange
  std::vector<int> vec = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  // Act && Assert
  ASSERT_LE(4, interpolationSearch(&vec, 9));
}

TEST(InterpolationSearchTest, returns_left) {
  // Arrange
  std::vector<int> vec = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  // Act && Assert
  ASSERT_GE(4, interpolationSearch(&vec, 0));
}

TEST(InterpolationSearchTest, returns_left_double_check) {
  // Arrange
  std::vector<int> vec = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  // Act && Assert
  ASSERT_LE(0, interpolationSearch(&vec, 0));
}

TEST(InterpolationSearchTest, right_value_changes) {
  // Arrange
  std::vector<int> vec = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  // Act && Assert
  ASSERT_LE(0, interpolationSearch(&vec, 3));
}

TEST(InterpolationSearchTest, right_value_changes_2) {
  // Arrange
  std::vector<int> vec = {0, 1, 2, 3, 4, 51, 6, 7, 8, 90, 100, 11};

  // Act && Assert
  ASSERT_LE(0, interpolationSearch(&vec, 51));
}

TEST(InterpolationSearchTest, mid_greater_val) {
  // Arrange
  std::vector<int> vec = {1, 4, 7, 9, 9, 12,
                          13, 14, 15, 15, 16, 17,
                          18, 19, 20, 21, 22, 23, 24, 25};

  // Act && Assert
  ASSERT_LE(0, interpolationSearch(&vec, 13));
}

TEST(InterpolationSearchTest, right_eq_left_val_exists) {
  // Arrange
  std::vector<int> vec = {0};

  // Act && Assert
  EXPECT_EQ(0, interpolationSearch(&vec, 0));
}

TEST(InterpolationSearchTest, right_eq_left_val_does_not_exist) {
  // Arrange
  std::vector<int> vec = {5};

  // Act && Assert
  EXPECT_EQ(-1, interpolationSearch(&vec, 0));
}
