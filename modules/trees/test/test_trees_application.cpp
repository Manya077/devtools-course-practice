// Copyright 2020 Sinitsina Maria
#include <gtest/gtest.h>
#include <string>
#include <vector>
#include "include/trees_application.h"

using ::testing::internal::RE;

class TreesApplicationTest : public ::testing::Test {
 protected:
    void Act(std::vector<std::string> args_) {
        std::vector<const char*> options;

        options.push_back("appname");
        int s = args_.size();
        for (int i = 0; i < s; ++i) {
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
    TreesApplication app_;
    std::string output_;
};

TEST_F(TreesApplicationTest, Do_Print_Help_Without_Arguments) {
    // Arrange
    std::vector<std::string> args = {};

    Act(args);

    Assert("This is application for tree class.*");
}

TEST_F(TreesApplicationTest, Adds_And_Searches_The_Same_Number) {
  // Arrange
  std::vector<std::string> args = { "add", "1", "search", "1" };

  Act(args);

  Assert("1 is found.");
}

TEST_F(TreesApplicationTest, Adds_Deletes_And_Searches_The_Same_Number) {
  // Arrange
  std::vector<std::string> args = { "add", "1", "del", "1", "search", "1" };

  Act(args);

  Assert("1 is not found.");
}

TEST_F(TreesApplicationTest, Search_Twice_The_Same_Number) {
  // Arrange
  std::vector<std::string> args = { "add", "1", "search", "1",
                         "del", "1", "search", "1" };

  Act(args);

  Assert("1 is found.1 is not found.");
}

TEST_F(TreesApplicationTest, Handles_Unknown_Operation) {
  // Arrange
  std::vector<std::string> args = { "addd", "2", "search", "2",
                                   "clear", "2" };
  Act(args);

  Assert("Unknown operation: addd");
}

TEST_F(TreesApplicationTest, Handles_Deleting_Element_With_Zero_Count) {
  // Arrange
  std::vector<std::string> args = { "del", "2", "search", "2" };

  Act(args);

  Assert("2 is not found.");
}

TEST_F(TreesApplicationTest, Throws_An_Error_If_Argument_Is_Not_Numeric) {
  // Arrange
  std::vector<std::string> args = { "add", "a" };

  Act(args);

  Assert("a is not the number");
}

TEST_F(TreesApplicationTest, Throws_An_Error_If_Int_Overflows) {
  // Arrange
  std::vector<std::string> args = { "add", "20000000000" };

  Act(args);

  Assert("Number is out of bounds");
}

TEST_F(TreesApplicationTest, Add_And_Search_Negative_Number) {
  // Arrange
  std::vector<std::string> args = { "add", "-1", "search", "-1" };

  Act(args);

  Assert("-1 is found.");
}

TEST_F(TreesApplicationTest, Add_Negative_Number_And_Search_Positive_Number) {
  // Arrange
  std::vector<std::string> args = { "add", "-1", "search", "1" };

  Act(args);

  Assert("1 is not found.");
}

TEST_F(TreesApplicationTest, Search_Twice_The_Same_Negative_Number) {
  // Arrange
  std::vector<std::string> args = { "add", "-1", "search", "-1",
                         "del", "-1", "search", "-1" };

  Act(args);

  Assert("-1 is found.-1 is not found.");
}

TEST_F(TreesApplicationTest, Handles_Numbers_That_End_With_The_Dash) {
  // Arrange
  std::vector<std::string> args = { "add", "1-" };

  Act(args);

  Assert("1- is not the number");
}
