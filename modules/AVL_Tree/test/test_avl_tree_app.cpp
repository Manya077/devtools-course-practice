// Copyright 2020 Pauzin Leonid

#include <gtest/gtest.h>

#include <vector>
#include <string>
#include "include/avl_tree_app.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class AvlAppTest : public ::testing::Test {
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
    AvlApp app_;
    string output_;
};

TEST_F(AvlAppTest, Print_Help_If_No_Args_Given) {
  vector<string> args = {};

  Act(args);

  Assert("This is a AVL-tree application\\..*");
}


TEST_F(AvlAppTest, Detects_Wrong_Args) {
  std::vector<std::string> args = { "ins", "1" };

  Act(args);

  Assert("Bad arguments!");
}

TEST_F(AvlAppTest, Cant_Add_Wrong_Number) {
  std::vector<std::string> args = { "insert", "a" };

  Act(args);

  Assert("Invalid value: a");
}

TEST_F(AvlAppTest, Can_insert_value) {
  std::vector<std::string> args = { "insert", "1"};

  Act(args);

  Assert("");
}

TEST_F(AvlAppTest, Can_insert_more_than_1_value) {
  std::vector<std::string> args = { "insert", "1",
    "insert", "2", "insert", "4" };

  Act(args);

  Assert("");
}

TEST_F(AvlAppTest, Cant_remove) {
  std::vector<std::string> args = { "remove", "2" };

  Act(args);

  Assert("\\(No that data in tree\\)");
}

TEST_F(AvlAppTest, Can_remove_value) {
  std::vector<std::string> args = { "insert", "1",
    "remove", "1"};

  Act(args);

  Assert("");
}
