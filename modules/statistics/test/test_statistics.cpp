// Copyright 2020 Maximova Irina & Kukushkina Ksenia

#include <gtest/gtest.h>

#include <map>
#include <vector>

#include "include/statistics.h"

class DistributionTest : public ::testing::Test {
 protected:
  double epsilon = 0.001;
};

TEST_F(DistributionTest, Can_Initialize_Rand_Variable) {
  // Arrange
  std::vector<int> value = {0, 1, 2};
  std::vector<double> probability = {0.2, 0.3, 0.5};
  std::map<int, double> rand_var = {{0, 0.2}, {1, 0.3}, {2, 0.5}};

  // Act
  Distribution s(rand_var);

  // Assert
  ASSERT_EQ(s.getValue(), value);
  ASSERT_EQ(s.getProbability(), probability);
}

TEST_F(DistributionTest, Throws_When_The_Sum_Probabilities_Not_Equal_Unit) {
  // Arrange
  std::map<int, double> rand_var = {{0, 0.7}, {1, 0.9}};

  // Act & Assert
  ASSERT_ANY_THROW(Distribution s(rand_var));
}

TEST_F(DistributionTest, Throws_When_Probability_Is_Negative) {
  // Arrange
  std::map<int, double> rand_var = {{0, 0.2}, {1, -0.3}};

  // Act & Assert
  ASSERT_ANY_THROW(Distribution s(rand_var));
}

TEST_F(DistributionTest, Throws_When_Value_Is_Repeated) {
  // Arrange
  std::map<int, double> rand_var = {{0, 0.2}, {0, 0.8}};

  // Act & Assert
  ASSERT_ANY_THROW(Distribution s(rand_var));
}

TEST_F(DistributionTest, Can_Create_Via_Copying) {
  // Arrange
  Distribution s({{0, 0.4}, {1, 0.6}});

  // Act
  Distribution copy_s(s);

  // Assert
  ASSERT_EQ(s.getRandomVar(), copy_s.getRandomVar());
}

TEST_F(DistributionTest, Can_Set_Random_Variable) {
  // Arrange
  Distribution s;
  std::map<int, double> rand_var = {{0, 0.1}, {1, 0.3}, {2, 0.6}};

  // Act
  s.setRandomVar(rand_var);

  // Assert
  ASSERT_EQ(s.getRandomVar(), rand_var);
}

TEST_F(DistributionTest, Can_Equate_Object) {
  // Arrange
  Distribution s({{0, 0.1}, {1, 0.3}, {2, 0.6}});
  Distribution equal_s;

  // Act
  equal_s = s;

  // Assert
  ASSERT_EQ(s.getRandomVar(), equal_s.getRandomVar());
}

TEST_F(DistributionTest, Get_Expected_Value) {
  // Arrange
  Distribution s({{0, 0.1}, {1, 0.3}, {2, 0.05}, {3, 0.55}});
  double exp_val = 2.05;

  // Act
  double exp_val_s = s.expectedValue();

  // Assert
  ASSERT_NEAR(exp_val, exp_val_s, DistributionTest::epsilon);
}

TEST_F(DistributionTest, Throws_When_Call_Expected_Value_But_Data_Is_Empty) {
  // Arrange
  Distribution s;

  // Act & Assert
  ASSERT_ANY_THROW(s.expectedValue());
}

TEST_F(DistributionTest, Get_Fifth_Order_Moment_of_Random_Variable) {
  // Arrange
  Distribution s({{0, 0.1}, {1, 0.3}, {2, 0.05}, {3, 0.55}});
  double disp_val = 17.55;
  double a = 1.;
  int order = 5;

  // Act
  double disp_val_s = s.moment(order, a);

  // Assert
  ASSERT_NEAR(disp_val, disp_val_s, DistributionTest::epsilon);
}

TEST_F(DistributionTest, Zero_Order_Moment_Equal_Unit) {
  // Arrange
  Distribution s({{0, 0.1}, {1, 0.3}, {2, 0.05}, {3, 0.55}});
  int order = 0;
  double a = 4;
  double exp_disp_val = 1;

  // Act
  double disp_val = s.moment(order, a);

  // Assert
  ASSERT_NEAR(exp_disp_val, disp_val, DistributionTest::epsilon);
}

TEST_F(DistributionTest, Throws_When_Call_Moment_But_Data_Is_Empty) {
  // Arrange
  Distribution s;
  double a = 1.;
  int order = 5;

  // Act & Assert
  ASSERT_ANY_THROW(s.moment(order, a));
}

TEST_F(DistributionTest, Throws_When_Order_Is_Negative) {
  // Arrange
  Distribution s({{0, 0.1}, {1, 0.3}, {2, 0.05}, {3, 0.55}});
  double exp_val = s.expectedValue();
  int order = -2;

  // Act & Assert
  ASSERT_ANY_THROW(s.moment(order, exp_val));
}

TEST_F(DistributionTest, Get_Dispersion_Value) {
  // Arrange
  Distribution s({{0, 0.1}, {1, 0.3}, {2, 0.05}, {3, 0.55}});
  double disp_val = 1.2475;

  // Act
  double disp_val_s = s.dispersion();

  // Assert
  ASSERT_NEAR(disp_val, disp_val_s, DistributionTest::epsilon);
}

TEST_F(DistributionTest, Random_Variable_Is_Equal_To_Itself) {
  // Arrange
  Distribution s({{2, 0.9}, {4, 0.1}});

  // Act & Assert
  EXPECT_TRUE(s == s);
}

TEST_F(DistributionTest, Equal_Random_Variables_Are_Equal) {
  // Arrange
  Distribution s1({{2, 0.9}, {4, 0.1}});
  Distribution s2({{2, 0.9}, {4, 0.1}});

  // Act & Assert
  EXPECT_EQ(s1, s2);
}

TEST_F(DistributionTest,
       Equal_Random_Variables_With_Different_Position_Values) {
  // Arrange
  Distribution s1({{2, 0.9}, {4, 0.1}});
  Distribution s2({{4, 0.1}, {2, 0.9}});

  // Act & Assert
  EXPECT_EQ(s1, s2);
}

TEST_F(DistributionTest, Different_Random_Variables_Not_Equal) {
  // Arrange
  Distribution s1({{2, 0.9}, {4, 0.1}});
  Distribution s2({{1, 0.6}, {-4, 0.4}});

  // Act & Assert
  EXPECT_TRUE(s1 != s2);
}

TEST_F(DistributionTest, Dispersion_Through_Math_Expectation) {
  // Arrange
  Distribution s({{0, 0.1}, {1, 0.3}, {2, 0.05}, {3, 0.55}});
  Distribution ss({{0, 0.1}, {1, 0.3}, {4, 0.05}, {9, 0.55}});

  // Act
  double exp_s = s.expectedValue();
  double exp_ss = ss.expectedValue();
  double disp = s.dispersion();

  // Assert
  double expected_disp = exp_ss - exp_s * exp_s;
  ASSERT_NEAR(disp, expected_disp, DistributionTest::epsilon);
}
