// Copyright 2020 Tihomirova Maria

#include <gtest/gtest.h>
#include "include/complex_number.h"

TEST(Tihomirova_Maria_ComplexNumberTest, Can_GetRe) {
  // Arrange
  ComplexNumber z;

  // Act
  z.setRe(77);

  // Assert
  EXPECT_EQ(77, z.getRe());
}

TEST(Tihomirova_Maria_ComplexNumberTest, Multiplication_By_Zero) {
  // Arrange
  ComplexNumber z1;
  ComplexNumber z2(7.0, 1.0);

  // Act
  ComplexNumber z = z1 * z2;

  // Assert
  EXPECT_EQ(z1, z);
}

TEST(Tihomirova_Maria_ComplexNumberTest, Check_Copy) {
  // Arrange
  ComplexNumber z1(1.0, -3.0);

  // Act
  ComplexNumber z2(z1);

  // Assert
  EXPECT_TRUE(z1 == z2);
}
