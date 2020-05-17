// Copyright 2020 Mikhail Zakharov

#include <gtest/gtest.h>

#include "include/DepositCalc.h"

TEST(DepositCalculatorTest, Can_Set_DepositAmount) {
    // Arrange
    int var = 1000;
    // Act
    DepositCalc dep(0, 1, 0);
    dep.setDepositAmount(var);
    // Assert
    EXPECT_EQ(var, dep.getDepositAmount());
}

TEST(DepositCalculatorTest, Can_Set_Rate) {
    // Arrange
    int var = 1000;
    // Act
    DepositCalc dep(0, 1, 0);
    dep.setRate(var);
    // Assert
    EXPECT_EQ(var, dep.getRate());
}

TEST(DepositCalculatorTest, Can_Set_Period) {
    // Arrange
    int var = 1000;
    // Act
    DepositCalc dep(0, 1, 0);
    dep.setPeriod(var);
    // Assert
    EXPECT_EQ(var, dep.getPeriod());
}

TEST(DepositCalculatorTest, Can_Work_With_Zero_Parameters) {
    // Arrange & Act
    DepositCalc dep(0, 1, 0);
    dep.calc();
    // Assert
    ASSERT_FALSE(dep.getDepositWithRate());
    ASSERT_FALSE(dep.getInterestCharges());
}

TEST(DepositCalculatorTest, Is_Deposit_Rate_Calculation_Right) {
    // Arrange
    int _depositWithRate = 708606;
    // Act
    DepositCalc dep(700000, 30, 15);
    dep.calc();
    // Assert
    EXPECT_EQ(_depositWithRate, dep.getDepositWithRate());
}

TEST(DepositCalculatorTest, Is_Interest_Charges_Calculation_Right) {
    // Arrange
    int _interestCharges = 8606;
    // Act
    DepositCalc dep(700000, 30, 15);
    dep.calc();
    // Assert
    EXPECT_EQ(_interestCharges, dep.getInterestCharges());
}

TEST(DepositCalculatorTest, Can_Throw_Exception_If_Zero_Period) {
    // Arrange & Act
    DepositCalc dep(0, 0, 0);
    // Assert
    ASSERT_ANY_THROW(dep.setPeriod(0));
}

TEST(DepositCalculatorTest, Can_Throw_Exception_If_Period_More_Than_1826) {
    // Arrange & Act
    DepositCalc dep(0, 0, 0);
    // Assert
    ASSERT_ANY_THROW(dep.setPeriod(1827));
}

TEST(DepositCalculatorTest, Can_Throw_Exception_If_Zero_Deposit_Amount) {
    // Arrange & Act
    DepositCalc dep(1, 1, 1);
    // Assert
    ASSERT_ANY_THROW(dep.setPeriod(0));
}

TEST(DepositCalculatorTest, Can_Throw_Exception_If_Zero_Rate) {
    // Arrange & Act
    DepositCalc dep(1, 1, 1);
    // Assert
    ASSERT_ANY_THROW(dep.setRate(0));
}
