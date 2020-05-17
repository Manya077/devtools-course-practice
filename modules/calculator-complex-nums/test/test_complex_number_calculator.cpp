// Copyright 2020 Kuzhelev Anton

#include <gtest/gtest.h>

#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>

#include "include/complex_number_calculator.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class ComplexCalculatorTest : public ::testing::Test {
 protected:
    // virtual void SetUp() {}

    void Act(vector<string> args_) {
        vector<const char*> options;

        options.push_back("appname");
        for (size_t i = 0; i < args_.size(); ++i) {
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
    ComplexCalculator app_;
    string output_;
};

TEST_F(ComplexCalculatorTest, Do_Print_Help_Without_Arguments) {
    // Arrange
    vector<string> args = {};

    // Act
    Act(args);

    // Assert
    Assert("This is a complex number calculator application\\..*");
}

TEST_F(ComplexCalculatorTest, Is_Checking_Number_Of_Arguments) {
    // Arrange
    vector<string> args = {"1", "2"};

    // Act
    Act(args);

    // Assert
    Assert("ERROR: Should be 5 arguments\\..*");
}

TEST_F(ComplexCalculatorTest, Can_Detect_Wrong_Number_Format) {
    // Arrange
    vector<string> args = {"1", "pi", "2", "4", "+"};

    // Act
    Act(args);

    // Assert
    Assert("Wrong number format!.*");
}

TEST_F(ComplexCalculatorTest, Can_Detect_Wrong_Operation_Format) {
    // Arrange
    vector<string> args = {"1", "1", "1", "1", "garbage"};

    // Act
    Act(args);

    // Assert
    Assert("Wrong operation format!");
}

TEST_F(ComplexCalculatorTest, Can_Add_Complexs) {
    // Arrange
    vector<string> args = {"2.0", "3.5", "1.5", "4.0", "+"};

    // Act
    Act(args);

    // Assert
    Assert("Real = 3.5 Imaginary = 7.5");
}

TEST_F(ComplexCalculatorTest, Can_Diff_Complexs) {
    // Arrange
    vector<string> args = {"13", "7.6", "26", "-14", "-"};

    // Act
    Act(args);

    // Assert
    Assert("Real = -13 Imaginary = 21.6");
}

TEST_F(ComplexCalculatorTest, Can_Mult_Complexs) {
    // Arrange
    vector<string> args = {"0", "-3.6", "17.4", "21", "*"};

    // Act
    Act(args);

    // Assert
    Assert("Real = 75.6 Imaginary = -62.64");
}

TEST_F(ComplexCalculatorTest, Can_Divide_Complexs) {
    // Arrange
    vector<string> args = {"27", "30", "15", "20", "/"};

    // Act
    Act(args);

    // Assert
    Assert("Real = 1.608 Imaginary = -0.144");
}

TEST_F(ComplexCalculatorTest, Can_Detect_Divide_By_Zero) {
    // Arrange
    vector<string> args = {"27", "30", "0", "0", "/"};

    // Act
    Act(args);

    // Assert
    Assert("Can't divide by zero");
}

TEST_F(ComplexCalculatorTest, Can_Add_Negative_Complexs) {
    // Arrange
    vector<string> args = {"-1", "-2", "-3", "-4", "+"};

    // Act
    Act(args);

    // Assert
    Assert("Real = -4 Imaginary = -6");
}

TEST_F(ComplexCalculatorTest, Can_Add_Natural_To_Complex) {
    // Arrange
    vector<string> args = {"1", "2", "3", "0", "+"};

    // Act
    Act(args);

    // Assert
    Assert("Real = 4 Imaginary = 2");
}

TEST_F(ComplexCalculatorTest, Can_Substruct_Natural_From_Complex) {
    // Arrange
    vector<string> args = {"1", "2", "3", "0", "-"};

    // Act
    Act(args);

    // Assert
    Assert("Real = -2 Imaginary = 2");
}

TEST_F(ComplexCalculatorTest, Can_Multiply_Natural_By_Complex) {
    // Arrange
    vector<string> args = {"1", "2", "3", "0", "*"};

    // Act
    Act(args);

    // Assert
    Assert("Real = 3 Imaginary = 6");
}

TEST_F(ComplexCalculatorTest, Can_Divide_Complex_by_Natural) {
    // Arrange
    vector<string> args = {"1", "2", "3", "0", "/"};

    // Act
    Act(args);

    // Assert
    Assert("Real = 0.333333 Imaginary = 0.666667");
}
