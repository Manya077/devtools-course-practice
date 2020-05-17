// Copyright 2020 Golubeva Anna

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Golubeva_Anna_ComplexNumberTest, Can_Set_Real_And_Imaginary) {
// Arrange
  ComplexNumber num;
  double real = 2.2;
  double imaginary = 1.1;

  // Act
  num.setRe(real);
  num.setIm(imaginary);

  // Assert
  ASSERT_EQ(real, num.getRe());
  ASSERT_EQ(imaginary, num.getIm());
}

TEST(Golubeva_Anna_ComplexNumberTest, Copy_Constructor) {
  // Arrange
  ComplexNumber num1(3.3, 2.2);

  // Act
  ComplexNumber num2(num1);

  // Assert
  EXPECT_EQ(num1, num2);
}

TEST(Golubeva_Anna_ComplexNumberTest, Can_Add) {
  // Arrange
  ComplexNumber num1(5.0, 4.0);
  ComplexNumber num2(2.2, 1.2);

  // Act
  ComplexNumber num3 = num1 + num2;

  // Assert
  EXPECT_EQ(num3, ComplexNumber(7.2, 5.2));
}

TEST(Golubeva_Anna_ComplexNumberTest, Can_Substract_Complex_Number) {
// Arrange
  ComplexNumber num1(2.2, 3.3);
  ComplexNumber num2(1.1, -3.3);

  // Act
  ComplexNumber num3 = num1 - num2;

  // Assert
  EXPECT_EQ(num3, ComplexNumber(1.1, 6.6));
}

TEST(Golubeva_Anna_ComplexNumberTest, Division_By_Zero) {
// Arrange
  ComplexNumber num1(1.1, 2.2);
  ComplexNumber num2;

  // Act & Assert
  ASSERT_ANY_THROW(num1 / num2);
}
