// Copyright 2020 Golubeva Anna

#include <gtest/gtest.h>
#include <vector>
#include <string>
#include "include/graph_diameter_search_app.h"
using ::testing::internal::RE;

class GraphAppTest : public ::testing::Test {
 protected:
  void Act(std::vector<std::string> args_) {
    std::vector<const char*> options;
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
  std::string output_;
  GraphApp app_;
};

TEST_F(GraphAppTest, Can_Print_Help_Without_Arguments) {
  // Arrange
  std::vector<std::string> args = {};

  // Act
  Act(args);

  // Assert
  Assert("This is a graph diameter search application\\..*");
}

TEST_F(GraphAppTest, Check_Number_Of_Arguments) {
  // Arrange
  std::vector<std::string> args = {"1"};

  // Act
  Act(args);

  // Assert
  Assert("Wrong arguments");
}

TEST_F(GraphAppTest, Can_Get_Diameter_Of_Graph) {
  // Arrange
  std::vector<std::string> args = {"3", "1", "2", "2", "3"};

  // Act
  Act(args);

  // Assert
  Assert("2");
}
