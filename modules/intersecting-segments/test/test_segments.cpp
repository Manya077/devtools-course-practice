// Copyright 2020 Kukushkina Ksenia & Maximova Irina

#include <gtest/gtest.h>

#include <utility>

#include "include/segments.h"

TEST(Segment, can_create_segment) {
  // Arrange & Act & Assert
  ASSERT_NO_THROW(Segment(1, 2, 3, 4));
}

TEST(Segment, can_create_segment_used_pair) {
  // Arrange
  std::pair<double, double> coord_1 = std::make_pair(1, 2);
  std::pair<double, double> coord_2 = std::make_pair(3, 4);

  // Act & Assert
  ASSERT_NO_THROW(Segment(coord_1, coord_2));
}

TEST(Segment, area_correctness) {
  // Arrange
  Segment A(2, 7, 10, 3);

  // Act & Assert
  ASSERT_EQ(12, abs(A.area(8, 7)));
}

TEST(Segment, area_sign) {
  // Arrange
  Segment A(1, 3, 7, 9);
  Segment A1(7, 9, 1, 3);

  // Act & Assert
  ASSERT_EQ(-1, A1.area(5, 5) / A.area(5, 5));
}

TEST(Segment, same_line_area) {
  // Arrange
  Segment A(1, 1, 3, 3);

  // Act & Assert
  ASSERT_EQ(0, A.area(6, 6));
}

TEST(Segment, intersection_true) {
  // Arrange
  Segment A(2, 7, 10, 3);
  Segment B(8, 7, 5, 2);

  // Act & Assert
  ASSERT_EQ(1, A.isIntersect(B));
}

TEST(Segment, intersection_false) {
  // Arrange
  Segment A(2, 7, 5, 2);
  Segment B(8, 7, 10, 3);

  // Act & Assert
  ASSERT_EQ(0, A.isIntersect(B));
}

TEST(Segment, same_line_intersection_true) {
  // Arrange
  Segment A(1, 1, 4, 10);
  Segment B(3, 7, 2, 4);

  // Act & Assert
  ASSERT_EQ(1, A.isIntersect(B));
}

TEST(Segment, same_line_intersection_false) {
  // Arrange
  Segment A(1, 1, 2, 4);
  Segment B(3, 7, 4, 10);

  // Act & Assert
  ASSERT_EQ(0, A.isIntersect(B));
}

TEST(Segment, commutativity) {
  // Arrange
  Segment A(1, 3, 7, 8);
  Segment B(3, 9, 1, 1);

  // Act & Assert
  ASSERT_EQ(A.isIntersect(B), B.isIntersect(A));
}
