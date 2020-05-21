
// Copyright 2020 Nazarov Vladislav

#include <gtest/gtest.h>
#include <vector>
#include <string>

#include "include/hashmap_application.h"

using ::testing::internal::RE;

class HashmapAppTest: public ::testing::Test {
 protected:
    void Act(std::vector<std::string> args_) {
        std::vector<const char*> options;

        options.push_back("HashmapApplication");
        for (size_t i = 0; i < args_.size(); ++i) {
            options.push_back(args_[i].c_str());
        }

        const char** argv = &options.front();
        int argc = static_cast<int>(args_.size()) + 1;

        _output = _app(argc, argv);
    }

    void Assert(std::string expected) {
        EXPECT_TRUE(RE::PartialMatch(_output, RE(expected)));
    }
 private:
    std::string _output;
    hashmapApp _app;
};

TEST_F(HashmapAppTest, Print_Help_If_No_Args_Given) {
    std::vector<std::string> args = {};

    Act(args);

    Assert("This is a Hashmap application\\..*");
}

TEST_F(HashmapAppTest, Detects_Wrong_Args) {
    std::vector<std::string> args = {"delete", "1"};

    Act(args);

    Assert("Bad arguments!");
}

TEST_F(HashmapAppTest, Can_Insert_And_Get) {
    std::vector<std::string> args = {"insert", "1", "2", "get", "1"};

    Act(args);

    Assert("\\(value = 2 with key = 1\\)");
}

TEST_F(HashmapAppTest, Cant_Insert_Wrong_Argument) {
    std::vector<std::string> args = {"insert", "4", "arg"};

    Act(args);

    Assert("Invalid value: arg");
}

TEST_F(HashmapAppTest, Cant_Insert_Wrong_Key) {
    std::vector<std::string> args = {"insert", "key", "5"};

    Act(args);

    Assert("Invalid value: key");
}

TEST_F(HashmapAppTest, Can_Remove_Element) {
    std::vector<std::string> args = {"insert", "1", "2", "remove",
        "1", "get", "1"};

    Act(args);

    Assert("\\(No value with this key\\)");
}

TEST_F(HashmapAppTest, Cant_Remove_Not_Existing_Elem) {
    std::vector<std::string> args = {"remove", "1"};

    Act(args);

    Assert("\\(No value with this key\\)");
}

TEST_F(HashmapAppTest, Cant_Insert_Out_Of_Range_Elem) {
    std::vector<std::string> args = {"insert", "1", "12000000000000"};

    Act(args);

    Assert("\\(Out of range\\)");
}

TEST_F(HashmapAppTest, Cant_Insert_Out_Of_Range_Negative_Elem) {
    std::vector<std::string> args = {"insert", "1", "-12000000000000"};

    Act(args);

    Assert("\\(Out of range\\)");
}

TEST_F(HashmapAppTest, Cant_Insert_Trash) {
    std::vector<std::string> args = {"insert", "dasad1asda", "afw2edw"};

    Act(args);

    Assert("Invalid value: afw2edw");
}

TEST_F(HashmapAppTest, Cant_Remove_Trash) {
    std::vector<std::string> args = {"insert", "2", "5", "remove",
        "daw1fa124asw"};

    Act(args);

    Assert("\\(Invalid value: daw1fa124asw\\)");
}
