// Copyright 2020 Vlasov Andrey

#include <gtest/gtest.h>
#include "include/complex_number.h"

TEST(Vlasov_Andrey_ComplexNumberTest, Can_Dividing_The_Number_By_Itself) {
  // Arrange
  ComplexNumber z1(3.0, 7.0);
  ComplexNumber z2;
  double re = 3.0;
  double im = 7.0;

  // Act
  z2.setRe(re);
  z2.setIm(im);
  ComplexNumber z = z2 / z1;

  // Assert
  ComplexNumber expected_z(1.0, 0.0);
  EXPECT_EQ(z, expected_z);
}

TEST(Vlasov_Andrey_ComplexNumberTest, Can_Divide_By_Zero) {
  // Arrange
  ComplexNumber z1;
  ComplexNumber z2(z1);

  // Act & Assert
  EXPECT_ANY_THROW(z2 / z1);
}

TEST(Vlasov_Andrey_ComplexNumberTest, Difference_And_GetRe_GetIm) {
  // Arrange
  ComplexNumber z1(3.0, 7.0);
  ComplexNumber z2(5.0, 5.0);

  // Act
  ComplexNumber z = z2 - z1;

  // Assert
  EXPECT_EQ(2.0, z.getRe());
  EXPECT_EQ(-2.0, z.getIm());
}
