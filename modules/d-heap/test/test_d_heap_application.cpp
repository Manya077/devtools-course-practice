// Copyright 2020 Guschin Alexandr

#include <gtest/gtest.h>
#include <string>
#include <vector>
#include "include/d-heap-sort.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class DHeapSortTest : public ::testing::Test {
 protected:
    void Act(vector<string> args_) {
        vector<const char*> options;

        options.push_back("d-heap");
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
    d_heap_sort app_;
    string output_;
};

TEST_F(DHeapSortTest, Can_Help) {
  vector<string> args = {};

  Act(args);

  Assert("This is D-Heap sorting application*");
}

TEST_F(DHeapSortTest, Can_Add_Element) {
  vector<string> args = {"add", "1", "show"};

  Act(args);

  Assert("1");
}

TEST_F(DHeapSortTest, Can_Add_And_Delete_Element) {
  vector<string> args = {"add", "1", "add", "23", "del", "1", "show"};

  Act(args);

  Assert("23");
}

TEST_F(DHeapSortTest, Can_Sort) {
  vector<string> args = {"add", "1", "add", "23", "add", "12", "sort"};

  Act(args);

  Assert("1 12 23");
}

TEST_F(DHeapSortTest, Can_Throw_When_Parse_Invalid_Operator) {
  vector<string> args = {"just_work", "1"};

  Act(args);

  Assert("Bad arguments!");
}

TEST_F(DHeapSortTest, Can_Throw_When_Parse_Negative_Element) {
  vector<string> args = {"add", "-1"};

  Act(args);

  Assert("Negative Number!");
}

TEST_F(DHeapSortTest, Can_Throw_When_Parse_Invalid_Element) {
  vector<string> args = {"add", "qwerty123"};

  Act(args);

  Assert("Cannot parse Number!");
}
