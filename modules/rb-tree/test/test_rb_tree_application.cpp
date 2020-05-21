// Copyright 2020 Isaev Ilya

#include <gtest/gtest.h>
#include <vector>
#include <string>

#include "include/rb_tree_application.h"

using ::testing::internal::RE;

class RBTreeAppTest: public ::testing::Test {
 protected:
    void Act(std::vector<std::string> args_) {
        std::vector<const char*> options;

        options.push_back("RBTreeApplication");
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
    RBTreeApp app_;
};

TEST_F(RBTreeAppTest, Print_Help_If_No_Args_Given) {
    std::vector<std::string> args = {};

    Act(args);

    Assert("This is a Red-black tree application\\..*");
}

TEST_F(RBTreeAppTest, Detects_Wrong_Args) {
    std::vector<std::string> args = {"ins", "1"};

    Act(args);

    Assert("Bad arguments!");
}

TEST_F(RBTreeAppTest, Can_Add_And_Find) {
    std::vector<std::string> args = {"insert", "1", "find", "1"};

    Act(args);

    Assert("\\(1 is found\\)");
}

TEST_F(RBTreeAppTest, Cant_Add_Wrong_Number) {
    std::vector<std::string> args = {"insert", "a"};

    Act(args);

    Assert("Invalid value: a");
}

TEST_F(RBTreeAppTest, Cant_Add_Wrong_Garbage_Value) {
    std::vector<std::string> args = {"insert", "-155asdasd"};

    Act(args);

    Assert("Invalid value: -155asdasd");
}

TEST_F(RBTreeAppTest, Can_Remove_Element) {
    std::vector<std::string> args = {"insert", "1", "remove", "1", "find", "1"};

    Act(args);

    Assert("\\(1 is not found\\)");
}

TEST_F(RBTreeAppTest, Cant_Remove_Not_Existing_Elem) {
    std::vector<std::string> args = {"remove", "1"};

    Act(args);

    Assert("\\(No that data in tree\\)");
}

TEST_F(RBTreeAppTest, Can_Get_Root) {
    std::vector<std::string> args = {"insert", "1", "insert", "2",
        "insert", "3", "getRoot"};

    Act(args);

    Assert("\\(Root value: 2\\)");
}

TEST_F(RBTreeAppTest, Cant_Get_Root_Of_Empty_Tree) {
    std::vector<std::string> args = {"getRoot"};

    Act(args);

    Assert("\\(Tree is empty\\)");
}
