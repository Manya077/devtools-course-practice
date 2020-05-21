// Copyright 2020 Makarikhin Semen

#include <gtest/gtest.h>
#include "include/complex_number.h"


TEST(Makarikhin_Semen_ComplexNumberTest, Inequality_Operator_Test) {
  // Arrange
  double re_1 = 9.0;
  double im_1 = 4.0;
  double re_2 = 11.0;
  double im_2 = 4.0;

  // Act
  ComplexNumber z1(re_1, im_1);
  ComplexNumber z2(re_2, im_2);

  // Assert
  EXPECT_TRUE(z1 != z2);
}

TEST(Makarikhin_Semen_ComplexNumberTest, Addition_Complex_Number) {
  // Arrange
  double re_1 = 6.2;
  double im_1 = 4.0;
  double re_2 = 7.3;
  double im_2 = 4.1;
  ComplexNumber z1(re_1, im_1);
  ComplexNumber z2(re_2, im_2);
  ComplexNumber res(re_1 + re_2, im_1 + im_2);

  // Act
  ComplexNumber z = z1 + z2;

  // Assert
  EXPECT_EQ(z, res);
}

TEST(Makarikhin_Semen_ComplexNumberTest, Subtraction_Complex_Number) {
  // Arrange
  double re_1 = 14.3;
  double im_1 = 7.0;
  double re_2 = 9.3;
  double im_2 = 4.1;
  ComplexNumber z1(re_1, im_1);
  ComplexNumber z2(re_2, im_2);
  ComplexNumber res(re_1 - re_2, im_1 - im_2);

  // Act
  ComplexNumber z = z1 - z2;

  // Assert
  EXPECT_EQ(z, res);
}

TEST(Makarikhin_Semen_ComplexNumberTest, Operator_Assigment_Test) {
  // Arrange
  double re_1 = 14.3;
  double im_1 = 9.0;

  ComplexNumber z1;
  ComplexNumber z2(re_1, im_1);

  // Act
  z1 = z2;

  // Assert
  EXPECT_EQ(z1, z2);
}
