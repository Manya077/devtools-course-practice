// Copyright 2020 Kornev Nikita

#include <gtest/gtest.h>
#include "include/complex_number.h"

TEST(Kornev_Nikita_ComplexNumberTest, can_create_complex_without_arguments) {
  // Arrange
  ComplexNumber z;

  // Assert
  EXPECT_EQ(z.getRe(), 0);
  EXPECT_EQ(z.getIm(), 0);
}

TEST(Kornev_Nikita_ComplexNumberTest, can_create_complex_with_arguments) {
  // Arrange
  ComplexNumber z(1, -1);

  // Assert
  EXPECT_EQ(z.getRe(), 1);
  EXPECT_EQ(z.getIm(), -1);
}

TEST(Kornev_Nikita_ComplexNumberTest, can_create_complex_with_complex) {
  // Arrange
  ComplexNumber z1(1, -1), z2(z1);

  // Assert
  EXPECT_EQ(z2.getRe(), z1.getRe());
  EXPECT_EQ(z2.getIm(), z1.getIm());
}

TEST(Kornev_Nikita_ComplexNumberTest, can_get_real_) {
  // Arrange
  ComplexNumber z(1, -1);

  // Act
  int a = z.getRe();

  // Assert
  EXPECT_EQ(a, 1);
}

TEST(Kornev_Nikita_ComplexNumberTest, can_get_im_) {
  // Arrange
  ComplexNumber z(1, -1);

  // Act
  int a = z.getIm();

  // Assert
  EXPECT_EQ(a, -1);
}

TEST(Kornev_Nikita_ComplexNumberTest, can_set_real_) {
  // Arrange
  ComplexNumber z;

  // Act
  z.setRe(1);

  // Assert
  EXPECT_EQ(z.getRe(), 1);
}

TEST(Kornev_Nikita_ComplexNumberTest, can_set_im_) {
  // Arrange
  ComplexNumber z;

  // Act
  z.setIm(1);

  // Assert
  EXPECT_EQ(z.getIm(), 1);
}

TEST(Kornev_Nikita_ComplexNumberTest, op_plus) {
  // Arrange
  ComplexNumber z1(1, 0), z2(0, 1), z3;

  // Act
  z3 = z1 + z2;

  // Assert
  EXPECT_EQ(z3.getRe(), 1);
  EXPECT_EQ(z3.getIm(), 1);
}

TEST(Kornev_Nikita_ComplexNumberTest, op_minus) {
  // Arrange
  ComplexNumber z1(2, 2), z2(1, 1), z3;

  // Act
  z3 = z1 - z2;

  // Assert
  EXPECT_EQ(z3.getRe(), 1);
  EXPECT_EQ(z3.getIm(), 1);
}

TEST(Kornev_Nikita_ComplexNumberTest, op_mult) {
  // Arrange
  ComplexNumber z1(2, 3), z2(-1, 1), z3;

  // Act
  z3 = z1 * z2;

  // Assert
  EXPECT_EQ(z3.getRe(), -5);
  EXPECT_EQ(z3.getIm(), -1);
}

TEST(Kornev_Nikita_ComplexNumberTest, op_div) {
  // Arrange
  ComplexNumber z1(-2, 1), z2(1, -1), z3;

  // Act
  z3 = z1 / z2;

  // Assert
  EXPECT_EQ(z3.getRe(), -1.5);
  EXPECT_EQ(z3.getIm(), -.5);
}

TEST(Kornev_Nikita_ComplexNumberTest, op_eq1) {
  // Arrange
  ComplexNumber z1(2, 3), z2(-1, 1);
  bool res;

  // Act
  res = z1 == z2;

  // Assert
  EXPECT_EQ(res, 0);
}

TEST(Kornev_Nikita_ComplexNumberTest, op_eq2) {
  // Arrange
  ComplexNumber z1(2, 2), z2(2, 2);
  bool res;

  // Act
  res = z1 == z2;

  // Assert
  EXPECT_EQ(res, 1);
}

TEST(Kornev_Nikita_ComplexNumberTest, op_non_eq1) {
  // Arrange
  ComplexNumber z1(2, 2), z2(2, 1);
  bool res;

  // Act
  res = z1 != z2;

  // Assert
  EXPECT_EQ(res, 1);
}

TEST(Kornev_Nikita_ComplexNumberTest, op_non_eq2) {
  // Arrange
  ComplexNumber z1(2, 2), z2(2, 2);
  bool res;

  // Act
  res = z1 != z2;

  // Assert
  EXPECT_EQ(res, 0);
}
