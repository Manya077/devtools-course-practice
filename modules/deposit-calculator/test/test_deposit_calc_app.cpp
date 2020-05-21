// Copyright 2020 Kornev Nikita

#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "include/DepositCalc_app.h"

using std::string;
using std::vector;
using ::testing::internal::RE;

class DepositCalc_app_test : public ::testing::Test {
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
  DepositCalc_app app_;
  string output_;
};

TEST_F(DepositCalc_app_test, Do_Print_Help_Without_Arguments) {
  // Arrange
  vector<string> args = {};

  // Act
  Act(args);

  // Assert
  Assert("This is a deposit calc application\\..*");
}

TEST_F(DepositCalc_app_test, Is_Checking_Number_Of_Arguments) {
  // Arrange
  vector<string> args = { "1", "2" };

  // Act
  Act(args);

  // Assert
  Assert("ERROR: Should be 3 arguments\\..*");
}

TEST_F(DepositCalc_app_test, Is_Checking_Period_Is_Negative) {
  // Arrange
  vector<string> args = { "0", "-1", "0" };

  // Act
  Act(args);

  // Assert
  Assert("ERROR: Period cant be negative\\..*");
}

TEST_F(DepositCalc_app_test, Is_Checking_Period_Equal_Zero) {
  // Arrange
  vector<string> args = { "0", "0", "0" };

  // Act
  Act(args);

  // Assert
  Assert("ERROR: Period cant be equal zero\\..*");
}

TEST_F(DepositCalc_app_test, Is_Checking_Period_Smaller_Then_1827) {
  // Arrange
  vector<string> args = { "0", "2000", "0" };

  // Act
  Act(args);

  // Assert
  Assert("ERROR: Period cant be bigger then 1826\\..*");
}

TEST_F(DepositCalc_app_test, Can_Calculate_Deposit) {
  // Arrange
  vector<string> args = { "100000", "366", "10" };

  // Act
  Act(args);

  // Assert
  Assert("Deposit with rate = 110000, interest charges = 10000\\..*");
}

TEST_F(DepositCalc_app_test, Can_Calculate_Deposit_With_Small_Period) {
  // Arrange
  vector<string> args = { "100000", "1", "10" };

  // Act
  Act(args);

  // Assert
  Assert("Deposit with rate = 100027, interest charges = 27\\..*");
}

TEST_F(DepositCalc_app_test, Can_Calculate_Deposit_With_Big_Period) {
  // Arrange
  vector<string> args = { "100000", "1826", "10" };

  // Act
  Act(args);

  // Assert
  Assert("Deposit with rate = 149890, interest charges = 49890\\..*");
}

TEST_F(DepositCalc_app_test, Can_Calculate_Deposit_With_Zero_Rate) {
  // Arrange
  vector<string> args = { "100000", "366", "0" };

  // Act
  Act(args);

  // Assert
  Assert("Deposit with rate = 100000, interest charges = 0\\..*");
}

TEST_F(DepositCalc_app_test, Can_Calculate_Deposit_With_Zero_Deposit) {
  // Arrange
  vector<string> args = { "0", "366", "10" };

  // Act
  Act(args);

  // Assert
  Assert("Deposit with rate = 0, interest charges = 0\\..*");
}
