// Copyright 2020 Golubev Vladislav

#include <gtest/gtest.h>
#include <string>
#include <vector>
#include "include/matrix_calculator.h"

using ::testing::internal::RE;

class MatrixCalculatorTest : public ::testing::Test {
 protected:
  void Act(std::vector<std::string> args_) {
    std::vector<const char*> options;

    options.push_back("MatrixCalculator");
    for (std::size_t i = 0; i < args_.size(); ++i) {
      options.push_back(args_[i].c_str());
    }

    const char** argv = &options.front();
    int argc = static_cast<int>(args_.size()) + 1;

    output_ = app_(argc, argv);
  }

  void Assert(std::string expected) {
    EXPECT_TRUE(RE::PartialMatch(output_, RE(expected)));
  }

 private:
  MatrixCalculator app_;
  std::string output_;
};

TEST_F(MatrixCalculatorTest, Do_Print_Help_Without_Arguments) {
  std::vector<std::string> args = {};

  Act(args);

  Assert("This is a matrix calculator application.");
}

TEST_F(MatrixCalculatorTest, Is_Checking_Number_Of_Arguments) {
  std::vector<std::string> args = { "1.0", "2.0", "3.0", "*" };

  Act(args);

  Assert("Should be 5, 6 or 9 arguments!");
}

TEST_F(MatrixCalculatorTest, Can_Detect_Wrong_Operation_Format) {
  std::vector<std::string> args = { "1.0", "2.0", "3.0", "1.0",
    "2.0", "3.0", "2.0", "3.0", "+-" };

  Act(args);

  Assert("Wrong operation format!");
}

TEST_F(MatrixCalculatorTest, Can_Add_Matrixes) {
  std::vector<std::string> args = { "1.0", "2.0", "3.0", "4.0",
    "4.0", "3.0", "2.0", "1.0", "+" };

  Act(args);

  Assert("res = 5 5 5 5 ");
}

TEST_F(MatrixCalculatorTest, Can_Substract_Matrixes) {
  std::vector<std::string> args = { "5.0", "5.0", "5.0", "5.0",
    "1.0", "2.0", "3.0", "4.0", "-" };

  Act(args);

  Assert("res = 4 3 2 1 ");
}

TEST_F(MatrixCalculatorTest, Can_Multiply_Matrixes) {
  std::vector<std::string> args = { "1.0", "2.0", "3.0", "4.0",
    "2.0", "5.0", "1.0", "3.0", "*" };

  Act(args);

  Assert("res = 4 11 10 27 ");
}

TEST_F(MatrixCalculatorTest, Can_Multiply_Matrix_To_Scalar) {
  std::vector<std::string> args = { "1.0", "2.0", "3.0", "4.0", "12.0", "*" };

  Act(args);

  Assert("res = 12 24 36 48 ");
}

TEST_F(MatrixCalculatorTest, Can_Compare_For_Equality) {
  std::vector<std::string> args = { "1.0", "2.0", "3.0", "4.0",
    "1.0", "2.0", "3.0", "4.0", "==" };

  Act(args);

  Assert("res = 1");
}

TEST_F(MatrixCalculatorTest, Can_Compare_For_Inequality) {
  std::vector<std::string> args = { "1.0", "2.0", "3.0", "4.0",
    "1.0", "2.0", "3.0", "4.0", "!=" };

  Act(args);

  Assert("res = 0");
}

TEST_F(MatrixCalculatorTest, Can_Get_Determinant) {
  std::vector<std::string> args = { "1.0", "2.0", "3.0", "4.0", "det" };

  Act(args);

  Assert("res = -2");
}

TEST_F(MatrixCalculatorTest, Can_Get_Transpose_Matrix) {
  std::vector<std::string> args = { "1.0", "2.0", "3.0", "4.0", "T" };

  Act(args);

  Assert("res = 1 3 2 4 ");
}

TEST_F(MatrixCalculatorTest, Can_Get_Inverse_Matrix) {
  std::vector<std::string> args = { "6.0", "7.0", "7.0", "8.0", "inv" };

  Act(args);

  Assert("res = -8 7 7 -6 ");
}
