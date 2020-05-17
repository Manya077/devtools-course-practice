// Copyright 2020 Kukushkina Ksenia

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Kukushkina_Ksenia_ComplexNumberTest, correct_imaginary_1_representation) {
  // Arrange
  ComplexNumber a(0, 1);

  // Act
  ComplexNumber b = a * a;

  // Assert
  EXPECT_EQ(b.getRe(), -1);
  EXPECT_EQ(b.getIm(), 0);
}

TEST(Kukushkina_Ksenia_ComplexNumberTest, conjugate_numbers_multiplication) {
  // Arrange
  ComplexNumber a(3, 1);
  ComplexNumber b(3, -1);

  // Act
  ComplexNumber c = a * b;

  // Assert
  EXPECT_EQ(c.getRe(), 10);
  EXPECT_EQ(c.getIm(), 0);
}

TEST(Kukushkina_Ksenia_ComplexNumberTest, natural_numbers_multiplication) {
  // Arrange
  ComplexNumber a(3, 0);
  ComplexNumber b(5, 0);

  // Act
  ComplexNumber c = a * b;

  // Assert
  EXPECT_EQ(c.getRe(), 15);
  EXPECT_EQ(c.getIm(), 0);
}

TEST(Kukushkina_Ksenia_ComplexNumberTest, natural_number_division) {
  // Arrange
  ComplexNumber a(15, -5);
  ComplexNumber b(5, 0);

  // Act
  ComplexNumber c = a / b;

  // Assert
  EXPECT_EQ(c.getRe(), 3);
  EXPECT_EQ(c.getIm(), -1);
}

TEST(Kukushkina_Ksenia_ComplexNumberTest, complex_numbers_division) {
  // Arrange
  ComplexNumber a(25, 49);
  ComplexNumber b(5, 3);

  // Act
  ComplexNumber c = a / b;

  // Assert
  EXPECT_EQ(c.getRe(), 8);
  EXPECT_EQ(c.getIm(), 5);
}
