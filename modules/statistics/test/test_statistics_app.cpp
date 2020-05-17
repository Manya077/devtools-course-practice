// Copyright 2020 Kukushkina Ksenia

#include <gtest/gtest.h>

#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>

#include "include/statistics_app.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class Statistics_app_test : public ::testing::Test {
 protected:
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
  Statistics_app app_;
  string output_;
};

TEST_F(Statistics_app_test, Do_Print_Help_Without_Arguments) {
  // Arrange
  vector<string> args = {};

  // Act
  Act(args);

  // Assert
  Assert("This is a statistics application\\..*");
}

TEST_F(Statistics_app_test, Is_Checking_Number_Of_Arguments) {
  // Arrange
  vector<string> args = { "1", "2" };

  // Act
  Act(args);

  // Assert
  Assert("ERROR: Should be more than 2 arguments\\..*");
}

TEST_F(Statistics_app_test, Is_Checking_Number_Of_Arguments_odd) {
  // Arrange
  vector<string> args = { "1", "2", "4", "3" };

  // Act
  Act(args);

  // Assert
  Assert("ERROR: Number of arguments should be odd\\..*");
}

TEST_F(Statistics_app_test, Can_Detect_Wrong_Probability_Format) {
  // Arrange
  vector<string> args = { "2", ",", "4", "1" , "m"};

  // Act
  Act(args);

  // Assert
  Assert("Wrong probability format!");
}

TEST_F(Statistics_app_test, Can_Detect_Wrong_Value_Format) {
  // Arrange
  vector<string> args = { "pi", "0", "4", "1" , "m" };

  // Act
  Act(args);

  // Assert
  Assert("Wrong value format!");
}

TEST_F(Statistics_app_test, Can_Detect_Wrong_Operation_Format) {
  // Arrange
  vector<string> args = { "2", "0", "4", "1" , "k" };

  // Act
  Act(args);

  // Assert
  Assert("Wrong operation format!");
}

TEST_F(Statistics_app_test, Can_Detect_Wrong_Probabilities_sum) {
  // Arrange
  vector<string> args = { "2", "1", "4", "1" , "m" };

  // Act
  Act(args);

  // Assert
  Assert("The sum of the probabilities must be equal Unit");
}

TEST_F(Statistics_app_test, Can_Detect_Negative_Probabilities) {
  // Arrange
  vector<string> args = { "2", "-1", "4", "1" , "m" };

  // Act
  Act(args);

  // Assert
  Assert("The probability must be positive");
}

TEST_F(Statistics_app_test, Can_Process_Correct_Arguments_m) {
  // Arrange
  vector<string> args = { "1", "0.2", "2", "0.8" , "m" };

  // Act
  Act(args);

  // Assert
  Assert("Expected value is 1.8");
}

TEST_F(Statistics_app_test, Can_Process_Correct_Arguments_d) {
  // Arrange
  vector<string> args = { "1", "0.2", "2", "0.8" , "d" };

  // Act
  Act(args);

  // Assert
  Assert("Dispersion is 0.16");
}

TEST_F(Statistics_app_test, Can_Process_Correct_Arguments_num) {
  // Arrange
  vector<string> args = { "1", "0.2", "2", "0.8" , "3" };

  // Act
  Act(args);

  // Assert
  Assert("3 order moment is -0.096");
}
