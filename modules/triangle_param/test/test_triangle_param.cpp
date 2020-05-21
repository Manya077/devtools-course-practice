// Copyright 2020 Mazur Daniil
#include <gtest/gtest.h>
#include <utility>
#include "../include/triangle_param.h"

TEST(TriangleParamTest, DefaultComstructor) {
  // Arrange
  Triangle triag{};
  std::pair<double, double> expextedA(0, 0);
  std::pair<double, double> expextedB(1, 0);
  std::pair<double, double> expextedC(0, 1);

  // Assert
  ASSERT_EQ(expextedA, triag.getTopA());
  ASSERT_EQ(expextedB, triag.getTopB());
  ASSERT_EQ(expextedC, triag.getTopC());
}

TEST(TriangleParamTest, ComstructorByArgs) {
  // Arrange
  std::pair<double, double> expextedA(0, 0);
  std::pair<double, double> expextedB(2, 4);
  std::pair<double, double> expextedC(10, 3);
  Triangle triag(expextedA, expextedB, expextedC);

  // Assert
  ASSERT_EQ(expextedA, triag.getTopA());
  ASSERT_EQ(expextedB, triag.getTopB());
  ASSERT_EQ(expextedC, triag.getTopC());
}

TEST(TriangleParamTest, ComstructorByArgsEx1) {
  // Arrange
  std::pair<double, double> expextedA(0, 0);
  std::pair<double, double> expextedB(0, 0);
  std::pair<double, double> expextedC(1, 1);

  // Assert
  ASSERT_ANY_THROW(Triangle triag(expextedA, expextedB, expextedC));
}

TEST(TriangleParamTest, ComstructorByArgsEx2) {
  // Arrange
  std::pair<double, double> expextedA(0, 0);
  std::pair<double, double> expextedB(1, 1);
  std::pair<double, double> expextedC(2, 2);

  // Assert
  ASSERT_ANY_THROW(Triangle triag(expextedA, expextedB, expextedC));
}

TEST(TriangleParamTest, NotCorrect) {
  // Arrange
  std::pair<double, double> expextedA(0, 0);
  std::pair<double, double> expextedB(1, 1);
  std::pair<double, double> expextedC(1, 2);
  std::pair<double, double> newC(1, 1);
  Triangle triag{};

  // Act
  triag.setTopA(expextedA);
  triag.setTopB(expextedB);
  triag.setTopC(expextedC);

  // Assert
  ASSERT_ANY_THROW(triag.setTopC(newC));
}

TEST(TriangleParamTest, NotCorrectA) {
  // Arrange
  std::pair<double, double> expextedA(-1, 0);
  std::pair<double, double> expextedB(1, 1);
  std::pair<double, double> expextedC(2, 2);
  std::pair<double, double> newA(0, 0);
  Triangle triag{};

  // Act
  triag.setTopA(expextedA);
  triag.setTopB(expextedB);
  triag.setTopC(expextedC);

  // Assert
  ASSERT_ANY_THROW(triag.setTopA(newA));
}

TEST(TriangleParamTest, NotCorrectB) {
  // Arrange
  std::pair<double, double> expextedA(0, 0);
  std::pair<double, double> expextedB(-1, 1);
  std::pair<double, double> expextedC(2, 2);
  std::pair<double, double> newB(1, 1);
  Triangle triag{};

  // Act
  triag.setTopA(expextedA);
  triag.setTopB(expextedB);
  triag.setTopC(expextedC);

  // Assert
  ASSERT_ANY_THROW(triag.setTopB(newB));
}

TEST(TriangleParamTest, NotCorrectC) {
  // Arrange
  std::pair<double, double> expextedA(0, 0);
  std::pair<double, double> expextedB(1, 1);
  std::pair<double, double> expextedC(1, 2);
  std::pair<double, double> newC(2, 2);
  Triangle triag{};

  // Act
  triag.setTopA(expextedA);
  triag.setTopB(expextedB);
  triag.setTopC(expextedC);

  // Assert
  ASSERT_ANY_THROW(triag.setTopC(newC));
}

TEST(TriangleParamTest, ComstructorByCopy) {
  // Arrange
  std::pair<double, double> expextedA(0, 0);
  std::pair<double, double> expextedB(2, 4);
  std::pair<double, double> expextedC(10, 3);
  Triangle triag(expextedA, expextedB, expextedC);
  Triangle triag2(triag);

  // Assert
  ASSERT_EQ(triag.getTopA(), triag2.getTopA());
  ASSERT_EQ(triag.getTopB(), triag2.getTopB());
  ASSERT_EQ(triag.getTopC(), triag2.getTopC());
}

TEST(TriangleParamTest, SetTops) {
  // Arrange
  std::pair<double, double> expextedA(0, 0);
  std::pair<double, double> expextedB(2, 4);
  std::pair<double, double> expextedC(10, 3);
  Triangle triag{};

  // Act
  triag.setTopA(expextedA);
  triag.setTopB(expextedB);
  triag.setTopC(expextedC);
  // Assert
  ASSERT_EQ(expextedA, triag.getTopA());
  ASSERT_EQ(expextedB, triag.getTopB());
  ASSERT_EQ(expextedC, triag.getTopC());
}

TEST(TriangleParamTest, AssignOverloaded) {
  // Arrange
  std::pair<double, double> expextedA(0, 0);
  std::pair<double, double> expextedB(2, 4);
  std::pair<double, double> expextedC(10, 3);
  Triangle triag(expextedA, expextedB, expextedC);
  Triangle triag2{};
  // Act
  triag2 = triag;
  // Assert
  ASSERT_EQ(triag.getTopA(), triag2.getTopA());
  ASSERT_EQ(triag.getTopB(), triag2.getTopB());
  ASSERT_EQ(triag.getTopC(), triag2.getTopC());
}

TEST(TriangleParamTest, EqOverloaded) {
  // Arrange
  std::pair<double, double> expextedA(0, 0);
  std::pair<double, double> expextedB(2, 4);
  std::pair<double, double> expextedC(10, 3);
  Triangle triag(expextedA, expextedB, expextedC);

  // Act
  Triangle triag2 = triag;
  // Assert
  ASSERT_TRUE(triag == triag2);
}

TEST(TriangleParamTest, NoEqOverloaded) {
  // Arrange
  std::pair<double, double> expextedA(0, 0);
  std::pair<double, double> expextedB(2, 4);
  std::pair<double, double> expextedC(10, 3);
  Triangle triag(expextedA, expextedB, expextedC);

  // Act
  Triangle triag2{};
  // Assert
  ASSERT_TRUE(triag != triag2);
}

TEST(TriangleParamTest, Perimetr) {
  // Arrange
  std::pair<double, double> expextedA(0, 0);
  std::pair<double, double> expextedB(2, 4);
  std::pair<double, double> expextedC(10, 3);
  Triangle triag(expextedA, expextedB, expextedC);

  // Act
  double AB = triag.side(triag.getTopA(), triag.getTopB());
  double BC = triag.side(triag.getTopC(), triag.getTopB());
  double AC = triag.side(triag.getTopA(), triag.getTopC());
  // Assert
  ASSERT_EQ(triag.perimetr(), AB + BC + AC);
}

TEST(TriangleParamTest, Square) {
  // Arrange
  std::pair<double, double> expextedA(0, 0);
  std::pair<double, double> expextedB(4, 0);
  std::pair<double, double> expextedC(4, 3);
  Triangle triag(expextedA, expextedB, expextedC);

  // Assert
  ASSERT_EQ(triag.square(), 6);
}

TEST(TriangleParamTest, Corners) {
  // Arrange
  std::pair<double, double> expextedA(0, 0);
  std::pair<double, double> expextedB(4, 0);
  std::pair<double, double> expextedC(4, 3);
  Triangle triag(expextedA, expextedB, expextedC);
  const double PI = 3.141592653589793238463;

  // Assert
  ASSERT_EQ(triag.cornA() + triag.cornB() + triag.cornC(), PI);
}
