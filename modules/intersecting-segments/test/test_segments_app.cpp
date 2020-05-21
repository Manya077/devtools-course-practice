// Copyright 2020 Maximova Irina

#include <gtest/gtest.h>

#include <algorithm>
#include <functional>
#include <iterator>
#include <string>
#include <vector>

#include "include/segments_app.h"

using std::string;
using std::vector;
using ::testing::internal::RE;

class Segment_app_test : public ::testing::Test {
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
  Segment_app app_;
  string output_;
};

TEST_F(Segment_app_test, Do_Print_Help_Without_Arguments) {
  // Arrange
  vector<string> args = {};

  // Act
  Act(args);

  // Assert
  Assert("This is an intersecting segments application\\..*");
}

TEST_F(Segment_app_test, Is_Checking_Number_Of_Arguments) {
  // Arrange
  vector<string> args = {"1", "2"};

  // Act
  Act(args);

  // Assert
  Assert("ERROR: Incurrect number arguments\\..*");
}

TEST_F(Segment_app_test, Is_Checking_Number_Operation) {
  // Arrange
  vector<string> args = {"7", "1", "1", "1", "5", "0", "3", "2", "4"};

  // Act
  Act(args);

  // Assert
  Assert("ERROR: Number operation must be 1 or 2 or 3\\..*");
}

TEST_F(Segment_app_test, Calculate_Triangle_Area) {
  // Arrange
  vector<string> args = {"1", "8", "15", "1", "6", "5", "2"};

  // Act
  Act(args);

  // Assert
  Assert("Triangle area = 32\\..*");
}

TEST_F(Segment_app_test, Point_To_Right_Of_Vector) {
  // Arrange
  vector<string> args = {"2", "1", "1", "0", "0", "0", "1"};

  // Act
  Act(args);

  // Assert
  Assert("Point to the right of the vector.");
}

TEST_F(Segment_app_test, Point_To_Left_Of_Vector) {
  // Arrange
  vector<string> args = {"2", "-1", "1", "0", "0", "0", "1"};

  // Act
  Act(args);

  // Assert
  Assert("Point to the left of the vector.");
}

TEST_F(Segment_app_test, Point_On_Vector) {
  // Arrange
  vector<string> args = {"2", "0", "8", "0", "0", "0", "1"};

  // Act
  Act(args);

  // Assert
  Assert("Point on the vector.");
}

TEST_F(Segment_app_test, Intersection_True) {
  // Arrange
  vector<string> args = {"3", "1", "1", "1", "5", "0", "3", "2", "4"};

  // Act
  Act(args);

  // Assert
  Assert("Segments do intersect");
}

TEST_F(Segment_app_test, Intersection_False) {
  // Arrange
  vector<string> args = {"3", "1", "1", "1", "5", "2", "3", "2", "4"};

  // Act
  Act(args);

  // Assert
  Assert("Segments do not intersect");
}

TEST_F(Segment_app_test, Intersection_On_The_Line) {
  // Arrange
  vector<string> args = {"3", "1", "1", "3", "3", "2", "2", "4", "4"};

  // Act
  Act(args);

  // Assert
  Assert("Segments do intersect");
}
