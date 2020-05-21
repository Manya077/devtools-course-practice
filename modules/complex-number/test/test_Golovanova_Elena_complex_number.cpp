// Copyright 2020 Golovanova Elena

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Golovanova_Elena_ComplexNumberTest, Can_Create_Complex) {
  // Arrange
  double re = 3.4;
  double im = 9.0;

  // Act
  ComplexNumber z(re, im);

  // Assert
  EXPECT_EQ(re, z.getRe());
  EXPECT_EQ(im, z.getIm());
}

TEST(Golovanova_Elena_ComplexNumberTest, Can_Create_Addition) {
  // Arrange
  ComplexNumber z1(1.5, 6.4);
  ComplexNumber z2(3.0, 2.1);

  // Act
  ComplexNumber z3 = z1 + z2;

  // Assert
  EXPECT_EQ(4.5, z3.getRe());
  EXPECT_EQ(8.5, z3.getIm());
}

TEST(Golovanova_Elena_ComplexNumberTest, Can_Create_Subtraction) {
  // Arrange
  ComplexNumber z1(5.0, 4.0);
  ComplexNumber z2(2.0, 1.0);

  // Act
  ComplexNumber z3 = z1 - z2;

  // Assert
  EXPECT_EQ(3.0, z3.getRe());
  EXPECT_EQ(3.0, z3.getIm());
}

TEST(Golovanova_Elena_ComplexNumberTest, Can_Create_Multiplication) {
  // Arrange
  ComplexNumber z1(2.0, 4.0);
  ComplexNumber z2(3.0, 1.0);

  // Act
  ComplexNumber z3 = z1 * z2;

  // Assert
  EXPECT_EQ(2.0, z3.getRe());
  EXPECT_EQ(14.0, z3.getIm());
}

TEST(Golovanova_Elena_ComplexNumberTest, Can_Create_Division) {
  // Arrange
  ComplexNumber z1(4.0, 2.0);
  ComplexNumber z2(1.0, 1.0);

  // Act
  ComplexNumber z3 = z1 / z2;

  // Assert
  EXPECT_EQ(3.0, z3.getRe());
  EXPECT_EQ(-1.0, z3.getIm());
}

TEST(Golovanova_Elena_ComplexNumberTest, Can_Not_Create_Division) {
  // Arrange
  ComplexNumber z1(4.0, 2.0);
  ComplexNumber z2(0.0, 0.0);

  // Act & Assert
  ASSERT_ANY_THROW(z1/z2);
}

TEST(Golovanova_Elena_ComplexNumberTest, Equal_is_true) {
  // Arrange
  ComplexNumber z1(15.0, 17.4);
  ComplexNumber z2(15.0, 17.4);

  // Act & Assert
  EXPECT_TRUE(z1 == z2);
}

TEST(Golovanova_Elena_ComplexNumberTest, Equal_is_not_true) {
  // Arrange
  ComplexNumber z1(5.0, 78.1);
  ComplexNumber z2(5.9, 8.6);

  // Act & Assert
  EXPECT_FALSE(z1 == z2);
}

TEST(Golovanova_Elena_ComplexNumberTest, Different_is_true) {
  // Arrange
  ComplexNumber z1(10.0, 7.4);
  ComplexNumber z2(20.0, 1.4);

  // Act & Assert
  EXPECT_TRUE(z1 != z2);
}

TEST(Golovanova_Elena_ComplexNumberTest, Different_is_false) {
  // Arrange
  ComplexNumber z1(1.0, 7.9);
  ComplexNumber z2(1.0, 7.9);

  // Act & Assert
  EXPECT_FALSE(z1 != z2);
}
