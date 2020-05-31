// Copyright 2020 Tihomirova Mariya

#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "include/leftist_heap_application.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class LeftHeapAppTest : public ::testing::Test {
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
  LeftHeapApp app_;
  string output_;
};

TEST_F(LeftHeapAppTest, Can_Print_Help_Without_Arguments) {
  vector<string> args = {};

  Act(args);

  Assert("This is a Leftist Heap application\\..*");
}

TEST_F(LeftHeapAppTest, Can_Detect_Wrong_Args) {
  vector<string> args = { "1357" };

  Act(args);

  Assert("Bad arguments!");
}

TEST_F(LeftHeapAppTest, Can_Insert_Invalid) {
  vector<string> args = { "insert", "123abc" };

  Act(args);

  Assert("Invalid value: 123abc");
}

TEST_F(LeftHeapAppTest, Can_IsEmpty_In_Empty_Heap) {
  vector<string> args = { "isEmpty" };

  Act(args);

  Assert("Heap is empty");
}

TEST_F(LeftHeapAppTest, Can_IsEmpty_In_Not_Empty_Heap) {
  vector<string> args = { "insert", "77", "isEmpty" };

  Act(args);

  Assert("Heap is not empty");
}

TEST_F(LeftHeapAppTest, Can_Insert_And_Find_Min) {
  vector<string> args = { "insert", "10", "insert", "7",
    "insert", "15", "findMin"};

  Act(args);

  Assert("Min is 7");
}

TEST_F(LeftHeapAppTest, Can_Find_Min_In_Empty_Heap) {
  vector<string> args = { "findMin" };

  Act(args);

  Assert("Heap is empty");
}

TEST_F(LeftHeapAppTest, Can_Delete_In_Empty_Heap) {
  vector<string> args = { "deleteMin" };

  Act(args);

  Assert("Heap is empty");
}

TEST_F(LeftHeapAppTest, Can_Insert_And_Delete) {
  vector<string> args = { "insert", "10", "insert", "5", "deleteMin" };

  Act(args);

  Assert("5 is delete");
}
