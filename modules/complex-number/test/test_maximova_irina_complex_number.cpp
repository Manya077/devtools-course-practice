// Copyright 2020 Maximova Irina

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Maximova_Irina_ComplexNumberTest, Can_Create_Default_Without_Throw) {
  // Arrange & Act & Assert
  ASSERT_NO_THROW(ComplexNumber());
}

TEST(Maximova_Irina_ComplexNumberTest, Can_Create_Default_Zero) {
  // Arrange
  double def = 0.0;

  // Act
  ComplexNumber z;

  // Assert
  EXPECT_EQ(def, z.getRe());
  EXPECT_EQ(def, z.getIm());
}

TEST(Maximova_Irina_ComplexNumberTest, Can_Create_With_Real_And_Imaginary) {
  // Arrange
  double re = -3.0;
  double im = 5.6;

  // Act
  ComplexNumber z(re, im);

  // Assert
  ASSERT_EQ(re, z.getRe());
  ASSERT_EQ(im, z.getIm());
}

TEST(Maximova_Irina_ComplexNumberTest, Can_Equate) {
  // Arrange
  ComplexNumber a;
  ComplexNumber b(1.5, 3.0);

  // Act
  a = b;

  // Assert
  ASSERT_EQ(a, b);
}

TEST(Maximova_Irina_ComplexNumberTest, Can_Create_Copy) {
  // Arrange
  ComplexNumber z(1.1, 0.6);

  // Act
  ComplexNumber expected_z(z);

  // Assert
  EXPECT_EQ(expected_z, z);
}

TEST(Maximova_Irina_ComplexNumberTest, Can_Set_Real_and_Imaginary) {
  // Arrange
  ComplexNumber z;
  double re = 5.0;
  double im = -3.0;

  // Act
  z.setRe(re);
  z.setIm(im);

  // Assert
  ASSERT_EQ(im, z.getIm());
  ASSERT_EQ(re, z.getRe());
}

TEST(Maximova_Irina_ComplexNumberTest, Can_Add_Complex_Number) {
  // Arrange
  ComplexNumber a(1.0, 3.0);
  ComplexNumber b(-1.0, 5.1);

  // Act
  ComplexNumber z = a + b;

  // Assert
  ComplexNumber expected_z(0.0, 8.1);
  ASSERT_EQ(expected_z, z);
}

TEST(Maximova_Irina_ComplexNumberTest, Can_Difference_Complex_Number) {
  // Arrange
  ComplexNumber a(1.0, 3.1);
  ComplexNumber b(1.0, 5.0);

  // Act
  ComplexNumber z = a - b;

  // Assert
  ComplexNumber expected_z(0.0, -1.9);
  ASSERT_EQ(expected_z, z);
}

TEST(Maximova_Irina_ComplexNumberTest, Can_Multiplication_Complex_Number) {
  // Arrange
  ComplexNumber a(2.0, -1.0);
  ComplexNumber b(1.0, 3.0);

  // Act
  ComplexNumber z = a * b;

  // Assert
  ComplexNumber expected_z(5.0, 5.0);
  EXPECT_EQ(expected_z, z);
}

TEST(Maximova_Irina_ComplexNumberTest, Assert_Throw_When_Division_By_Zero) {
  // Arrange
  ComplexNumber a(3.0, 1.0);
  ComplexNumber b;

  // Act & Assert
  ASSERT_ANY_THROW(a / b);
}

TEST(Maximova_Irina_ComplexNumberTest, Can_Division_Complex_Number) {
  // Arrange
  ComplexNumber a(2.0, -1.0);
  ComplexNumber b(1.0, 3.0);

  // Act
  ComplexNumber z = a / b;

  // Assert
  ComplexNumber expected_z(-0.1, -0.7);
  EXPECT_EQ(expected_z, z);
}

TEST(Maximova_Irina_ComplexNumberTest, Equal_Is_True) {
  // Arrange
  ComplexNumber z(1.0, 3.0);

  // Act & Assert
  EXPECT_TRUE(z == z);
}

TEST(Maximova_Irina_ComplexNumberTest, Equal_Is_False) {
  // Arrange
  ComplexNumber a(1.0, -3.0);
  ComplexNumber b(1.0, 3.0);

  // Act & Assert
  EXPECT_FALSE(a == b);
}

TEST(Maximova_Irina_ComplexNumberTest, Different_Is_True) {
  // Arrange
  ComplexNumber a(1.0, -3.0);
  ComplexNumber b(1.0, 3.0);

  // Act & Assert
  EXPECT_TRUE(a != b);
}

TEST(Maximova_Irina_ComplexNumberTest, Different_Is_False) {
  // Arrange
  ComplexNumber a(1.0, 3.0);
  ComplexNumber b(1.0, 3.0);

  // Act & Assert
  EXPECT_FALSE(a != b);
}
