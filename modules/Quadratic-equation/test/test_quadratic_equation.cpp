// Copyright 2020 Arisova Anastasiia

#include <gtest/gtest.h>

#include "include/Quadratic-equation.h"

TEST(QuadraticEquationTest, Can_Create_Quadratic_Equation) {
    // Arrange & Act & Assert
    EXPECT_NO_THROW(QuadraticEquation equat(2.0, 4.0, 1.0));
}

TEST(QuadraticEquationTest,
    Can_Create_Quadratic_Equation_First_Coeff_Equal_Zero) {
    // Arrange & Act & Assert
    EXPECT_ANY_THROW(QuadraticEquation equat(0.0, 4.0, 1.0));
}

TEST(QuadraticEquationTest, Can_Get_First_Root) {
    // Arrange
    QuadraticEquation equat(1.0, -2.0, 1.0);
    double root = 1.0;

    // Act
    equat.SolveQuadraticEquation();

    // Assert
    EXPECT_EQ(root, equat.GetRoot1());
}

TEST(QuadraticEquationTest, Can_Get_Second_Root) {
    // Arrange
    QuadraticEquation equat(1.0, -2.0, 1.0);
    double root = 1.0;

    // Act
    equat.SolveQuadraticEquation();

    // Assert
    EXPECT_EQ(root, equat.GetRoot2());
}

TEST(QuadraticEquationTest, Can_Find_Root) {
    // Arrange
    QuadraticEquation equat(1.0, -2.0, 1.0);

    // Act & Assert
    EXPECT_NO_THROW(equat.SolveQuadraticEquation());
}

TEST(QuadraticEquationTest, Can_Find_Count_Roots_1) {
    // Arrange
    QuadraticEquation equat(1.0, -2.0, 1.0);
    char count_roots = '1';

    // Act
    equat.SolveQuadraticEquation();

    // Assert
    EXPECT_EQ(count_roots, equat.GetCountRoots());
}

TEST(QuadraticEquationTest, Can_Find_Count_Roots_2) {
    // Arrange
    QuadraticEquation equat(1.0, 5.0, 4.0);
    char count_roots = '2';

    // Act
    equat.SolveQuadraticEquation();

    // Assert
    EXPECT_EQ(count_roots, equat.GetCountRoots());
}

TEST(QuadraticEquationTest, Can_Find_Count_Roots_If_They_Complex) {
    // Arrange
    QuadraticEquation equat(1.0, 4.0, 5.0);
    char count_roots = '0';

    // Act
    equat.SolveQuadraticEquation();

    // Assert
    EXPECT_EQ(count_roots, equat.GetCountRoots());
}

TEST(QuadraticEquationTest, Can_Not_Get_Root1_If_They_Complex) {
    // Arrange
    QuadraticEquation equat(1.0, 4.0, 5.0);

    // Act
    equat.SolveQuadraticEquation();

    // Assert
    EXPECT_ANY_THROW(equat.GetRoot1());
}

TEST(QuadraticEquationTest, Can_Not_Get_Root2_If_They_Complex) {
    // Arrange
    QuadraticEquation equat(1.0, 4.0, 5.0);

    // Act
    equat.SolveQuadraticEquation();

    // Assert
    EXPECT_ANY_THROW(equat.GetRoot2());
}

TEST(QuadraticEquationTest, Can_Set_New_Equation) {
    // Arrange
    QuadraticEquation equat(1.0, 4.0, 5.0);

    // Act & Assert
    EXPECT_NO_THROW(equat.SetNewCoefficients(3.0, 1.0, 2.0));
}

TEST(QuadraticEquationTest, Can_Set_New_Equation_With_First_Coeff_Zero) {
    // Arrange
    QuadraticEquation equat(1.0, 4.0, 5.0);

    // Act & Assert
    EXPECT_ANY_THROW(equat.SetNewCoefficients(0.0, 1.0, 2.0));
}

TEST(QuadraticEquationTest, Can_Update_Count_Roots_By_New_Coefficient) {
    // Arrange
    QuadraticEquation equat(1.0, 5.0, 4.0);
    char count_roots = '1';

    // Act
    equat.SolveQuadraticEquation();
    equat.SetNewCoefficients(1.0, -2.0, 1.0);
    equat.SolveQuadraticEquation();

    // Assert
    EXPECT_EQ(count_roots, equat.GetCountRoots());
}

TEST(QuadraticEquationTest, Can_Get_Count_Roots_If_New_Equation_Not_Solve) {
    // Arrange
    QuadraticEquation equat(1.0, 5.0, 4.0);
    char count_roots = '-';

    // Act
    equat.SolveQuadraticEquation();
    equat.SetNewCoefficients(1.0, -2.0, 1.0);

    // Assert
    EXPECT_EQ(count_roots, equat.GetCountRoots());
}

TEST(QuadraticEquationTest, Can_Get_Count_Root1_If_New_Equation_Not_Solve) {
    // Arrange
    QuadraticEquation equat(1.0, 5.0, 4.0);

    // Act
    equat.SolveQuadraticEquation();
    equat.SetNewCoefficients(1.0, -2.0, 1.0);

    // Assert
    EXPECT_ANY_THROW(equat.GetRoot1());
}

TEST(QuadraticEquationTest, Can_Get_Count_Root2_If_New_Equation_Not_Solve) {
    // Arrange
    QuadraticEquation equat(1.0, 5.0, 4.0);

    // Act
    equat.SolveQuadraticEquation();
    equat.SetNewCoefficients(1.0, -2.0, 1.0);

    // Assert
    EXPECT_ANY_THROW(equat.GetRoot2());
}

TEST(QuadraticEquationTest, Can_Get_Count_Root1_If_New_Equation_Solve) {
    // Arrange
    QuadraticEquation equat(1.0, -2.0, 1.0);
    double root1 = -1.0;

    // Act
    equat.SolveQuadraticEquation();
    equat.SetNewCoefficients(1.0, 5.0, 4.0);
    equat.SolveQuadraticEquation();

    // Assert
    EXPECT_EQ(root1, equat.GetRoot1());
}

TEST(QuadraticEquationTest, Can_Get_Count_Root2_If_New_Equation_Solve) {
    // Arrange
    QuadraticEquation equat(1.0, -2.0, 1.0);
    double root2 = -4.0;

    // Act
    equat.SolveQuadraticEquation();
    equat.SetNewCoefficients(1.0, 5.0, 4.0);
    equat.SolveQuadraticEquation();

    // Assert
    EXPECT_EQ(root2, equat.GetRoot2());
}
