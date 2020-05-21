// Copyright 2020 Golubev Vladislav

#include <gtest/gtest.h>
#include "include/complex_number.h"

TEST(Golubev_Vlad_ComplexNumberTest, can_create_default_complex_number) {
  // Arrange
  ComplexNumber expected_z(0, 0);

  // Act
  ComplexNumber z;

  // Assert
  EXPECT_EQ(z, expected_z);
}

TEST(Golubev_Vlad_ComplexNumberTest, mult_by_default_complex_number_is_zero) {
  // Arrange
  double re = 12.342;
  double im = -3.534;
  ComplexNumber def;
  ComplexNumber z(re, im);

  // Act
  ComplexNumber res = def * z;

  // Assert
  EXPECT_EQ(res, def);
}

TEST(Golubev_Vlad_ComplexNumberTest, add_default_number_is_the_same_number) {
  // Arrange
  double re = 12.342;
  double im = -3.534;
  ComplexNumber def;
  ComplexNumber z(re, im);

  // Act
  ComplexNumber res = def + z;

  // Assert
  EXPECT_EQ(res, z);
}
