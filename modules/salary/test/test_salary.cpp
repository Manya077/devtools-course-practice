// Copyright 2020 Savin Dmitry & Petrov Anton

#include <gtest/gtest.h>
#include "include/Salary.h"

class SalaryTest1 : public ::testing::Test {
};

TEST_F(SalaryTest1, Work_Without_Administrative_Leave_And_Without_H_W) {
    // Arrange
    float m_salary = 120000;
    float m_hours = 40;
    float m_hours_over = 0;
    float m_hours_admin = 0;
    Salary a1;
    a1.setSalary(120000);
    a1.setHours(40);
    a1.setOverHours(0);
    a1.setAdminHours(0);

    // Act
    float payment = a1.payment();

    // Assert
    EXPECT_EQ(120000, payment);
}

TEST_F(SalaryTest1, Work_Without_Administrative_Leave_With_Two_R_H) {
    // Arrange
    float m_salary = 120000;
    float m_hours = 40;
    float m_hours_over = 2;
    float m_hours_admin = 0;
    Salary a2;
    a2.setSalary(120000);
    a2.setHours(40);
    a2.setOverHours(2);
    a2.setAdminHours(0);

    // Act
    float payment = a2.payment();

    // Assert
    EXPECT_EQ(129000, payment);
}

TEST_F(SalaryTest1, Work_With_Administrative_Leave_With_Recycled_W) {
    // Arrange
    float m_salary = 120000;
    float m_hours = 40;
    float m_hours_over = 3;
    float m_hours_admin = 6;
    Salary a3;
    a3.setSalary(120000);
    a3.setHours(40);
    a3.setOverHours(3);
    a3.setAdminHours(6);

    // Act
    float payment = a3.payment();

    // Assert
    EXPECT_EQ(117000, payment);
}

TEST_F(SalaryTest1, Work_With_Administrative_Leave_Without_Hours) {
    // Arrange
    float m_salary = 120000;
    float m_hours = 40;
    float m_hours_over = 0;
    float m_hours_admin = 17;
    Salary a4;
    a4.setSalary(120000);
    a4.setHours(40);
    a4.setOverHours(0);
    a4.setAdminHours(17);

    // Act
    float payment = a4.payment();

    // Assert
    EXPECT_EQ(69000, payment);
}

TEST_F(SalaryTest1, Working_With_Zero_Hours_Worked) {
    // Arrange
    float m_salary = 120000;
    float m_hours = 0;
    float m_hours_over = 19;
    float m_hours_admin = 17;
    Salary a5;
    a5.setSalary(120000);
    a5.setHours(0);
    a5.setOverHours(19);
    a5.setAdminHours(17);

    // Act
    float payment = a5.payment();
    float exptcted = 0.0;

    // Assert
    EXPECT_EQ(exptcted, payment);
}

TEST_F(SalaryTest1, Erroneous_Salary_Payment) {
    // Arrange
    float m_salary = -120000;
    float m_hours = 0;
    float m_hours_over = 19;
    float m_hours_admin = 17;
    Salary a6;
    a6.setSalary(-120000);
    a6.setHours(0);
    a6.setOverHours(19);
    a6.setAdminHours(17);

    // Act
    float payment = a6.payment();
    float exptcted = 0.0;

    // Assert
    EXPECT_EQ(exptcted, payment);
}

TEST_F(SalaryTest1, Erroneous_Salary_Payment_Chek_Wrong_Admin_H) {
    // Arrange
    float m_hours_admin = -1;
    Salary a7;

    // Act
    bool res = a7.setAdminHours(m_hours_admin);

    // Assert
    EXPECT_FALSE(res);
}

TEST_F(SalaryTest1, Erroneous_Salary_Payment_Chek_Wrong_Ower_H) {
    // Arrange
    float m_hours_over = -1;
    Salary a8;

    // Act
    bool res = a8.setOverHours(m_hours_over);

    // Assert
    EXPECT_FALSE(res);
}

TEST_F(SalaryTest1, Can_Calculation_With_Zero_Numbers) {
    // Arrange & Act
    Salary a9;
    a9.setSalary(0);
    a9.setHours(0);
    a9.setOverHours(0);
    a9.setAdminHours(0);

    // Assert
    ASSERT_FALSE(a9.payment());
}

TEST_F(SalaryTest1, Create_Copy_Constructor) {
    // Arrange & Act
    Salary a10;
    a10.setSalary(120000);
    a10.setHours(40);
    a10.setOverHours(0);
    a10.setAdminHours(17);
    Salary a11(a10);

    // Assert
    EXPECT_EQ(a10.payment(), a11.payment());
}
