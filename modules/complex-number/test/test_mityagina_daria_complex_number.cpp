// Copyright 2020 Mityagina Daria

#include <gtest/gtest.h>

#include "include/complex_number.h"

class Mityagina_Daria_ComplexNumberTest : public ::testing::Test {
};

TEST_F(Mityagina_Daria_ComplexNumberTest, Compare_different_numbers_false) {
  // Arrange
  ComplexNumber num_1(9.0, 13.0);
  ComplexNumber num_2(-9.0, -13.0);

  // Act & Assert
  EXPECT_FALSE(num_1 == num_2);
}

TEST_F(Mityagina_Daria_ComplexNumberTest, Compare_different_numbers_true) {
  // Arrange
  ComplexNumber num_1(9.0, 13.0);
  ComplexNumber num_2(9.0, 13.0);

  // Act & Assert
  EXPECT_TRUE(num_1 == num_2);
}

TEST_F(Mityagina_Daria_ComplexNumberTest, Can_set_real) {
  // Arrange
  double real = 0.0;
  double imaginary = 0.0;

  // Act
  ComplexNumber num(real, imaginary);
  num.setRe(3);

  // Assert
  EXPECT_EQ(3, num.getRe());
}

TEST_F(Mityagina_Daria_ComplexNumberTest, Can_set_imaginary) {
  // Arrange
  double real = 0.0;
  double imaginary = 0.0;

  // Act
  ComplexNumber num(real, imaginary);
  num.setIm(3);

  // Assert
  EXPECT_EQ(3, num.getIm());
}

TEST_F(Mityagina_Daria_ComplexNumberTest, Can_add) {
  // Arrange
  ComplexNumber num_1(9.0, 13.0);
  ComplexNumber num_2(-9.0, -13.0);

  // Act
  ComplexNumber num_sum = num_1 + num_2;

  // Assert
  EXPECT_EQ(num_sum, ComplexNumber(0.0, 0.0));
}

TEST_F(Mityagina_Daria_ComplexNumberTest, Copy_constructor_works_correctly) {
  // Arrange
  ComplexNumber num(9.0, 13.0);

  // Act
  ComplexNumber copy_should_have(num);

  // Assert
  EXPECT_EQ(num, copy_should_have);
}
