// Copyright 2020 Petrov Anton & Savin Dmitry

#include <gtest/gtest.h>

#include "include/MortgageCalc.h"

TEST(CalculatorTest, Can_Set_Cost) {
    // Arrange
    int num = 1000000;
    // Act
    MortgageCalc mortgage(0, 0, 0, 0);
    mortgage.setCost(num);
    // Assert
    EXPECT_EQ(num, mortgage.getCost());
}

TEST(CalculatorTest, Can_Set_DownPayment) {
    // Arrange
    int num = 1000000;
    // Act
    MortgageCalc mortgage(0, 0, 0, 0);
    mortgage.setDownPayment(num);
    // Assert
    EXPECT_EQ(num, mortgage.getDownPayment());
}

TEST(CalculatorTest, Can_Set_CreditTerm) {
    // Arrange
    int num = 1000000;
    // Act
    MortgageCalc mortgage(0, 0, 0, 0);
    mortgage.setCreditTerm(num);
    // Assert
    EXPECT_EQ(num, mortgage.getCreditTerm());
}

TEST(CalculatorTest, Can_Set_InterestRate) {
    // Arrange
    int num = 10;
    // Act
    MortgageCalc mortgage(0, 0, 0, 0);
    mortgage.setInterestRate(num);
    // Assert
    EXPECT_EQ(num, mortgage.getInterestRate());
}

TEST(CalculatorTest, Can_Get_TotalFee) {
    // Arrange
    int num = 3872038;
    // Act
    MortgageCalc mortgage(2000000, 0, 10, 15);
    mortgage.calc();
    // Assert
    EXPECT_EQ(num, mortgage.getTotalFee());
}

TEST(CalculatorTest, Can_Get_MonthlyPayment) {
    // Arrange
    int num = 32266;
    // Act
    MortgageCalc mortgage(2000000, 0, 10, 15);
    mortgage.calc();
    // Assert
    EXPECT_EQ(num, mortgage.getMonthlyPayment());
}

TEST(CalculatorTest, Can_Get_MonthlyRate) {
    // Arrange
    double num = 0.0125;
    // Act
    MortgageCalc mortgage(2000000, 0, 10, 15);
    mortgage.calc();
    // Assert
    EXPECT_DOUBLE_EQ(num, mortgage.getMonthlyRate());
}

TEST(CalculatorTest, Can_Calculation_With_Zero_Numbers) {
    // Arrange & Act
    MortgageCalc mortgage(0, 0, 0, 0);
    // Assert
    ASSERT_TRUE(mortgage.getTotalFee());
}

TEST(CalculatorTest, Is_Copy_Constructort_Working_Fine) {
    // Arrange & Act
    MortgageCalc mortgage(1, 1, 1, 1);
    MortgageCalc mortgage2(mortgage);
    // Assert
    EXPECT_EQ(mortgage.getCost(), mortgage2.getCost());
    EXPECT_EQ(mortgage.getDownPayment(), mortgage2.getDownPayment());
    EXPECT_EQ(mortgage.getCreditTerm(), mortgage2.getCreditTerm());
    EXPECT_DOUBLE_EQ(mortgage.getInterestRate(), mortgage2.getInterestRate());
}

TEST(CalculatorTest, Create_Copy_Constructor) {
    // Arrange & Act
    MortgageCalc mortgage(1, 1, 1, 1);
    MortgageCalc mortgage2(mortgage);
    // Assert
    ASSERT_NO_THROW(mortgage2.getCost());
    ASSERT_NO_THROW(mortgage2.getDownPayment());
    ASSERT_NO_THROW(mortgage2.getCreditTerm());
    ASSERT_NO_THROW(mortgage2.getInterestRate());
}

TEST(CalculatorTest, Money_Amount_Comparison) {
    // Arrange
    int num = 1000;
    // Act
    MortgageCalc mortgage(2000000, 0, 10, 15);
    mortgage.calc();
    // Assert
    ASSERT_LT(num, mortgage.getMonthlyPayment());
}

TEST(CalculatorTest, Money_Amount_Comparison_Version) {
    // Arrange
    int num = 10000000;
    // Act
    MortgageCalc mortgage(2000000, 0, 5, 15);
    mortgage.calc();
    // Assert
    ASSERT_GT(num, mortgage.getMonthlyPayment());
}
