// Copyright 2020 Yasakova Anastasia

#include <gtest/gtest.h>
#include <vector>
#include <string>
#include "include/queue_application.h"

using ::testing::internal::RE;

class QueueAppTest : public ::testing::Test {
 protected:
     void Act(std::vector<std::string> args_) {
         std::vector<const char*> options;
         options.push_back("QueueApplication");
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
     QueueApp app_;
};


TEST_F(QueueAppTest, Do_Print_Help_Without_Arguments) {
    std::vector<std::string> args = {};

    Act(args);

    Assert("This is a Queue application\\..*");
}

TEST_F(QueueAppTest, Detects_Wrong_Args) {
    std::vector<std::string> args = {"put", "1"};

    Act(args);

    Assert("Bad arguments!");
}

TEST_F(QueueAppTest, Add_Elem) {
    std::vector<std::string> args = { "putElement", "1", "topElement" };

    Act(args);

    Assert("TopElem = 1");
}

TEST_F(QueueAppTest, Add_Difficult_Elem) {
    std::vector<std::string> args = {"putElement", "-3405", "topElement"};

    Act(args);

    Assert("TopElem = -3405");
}


TEST_F(QueueAppTest, Add_Wrong_Elem) {
    std::vector<std::string> args = {"putElement", "k"};

    Act(args);

    Assert("Invalid value: k");
}

TEST_F(QueueAppTest, Get_Count) {
    std::vector<std::string> args = { "putElement", "1",
        "putElement", "2", "putElement", "3",
        "putElement", "4", "putElement", "5", "getCount" };

    Act(args);

    Assert("Number of Elements = 5");
}

TEST_F(QueueAppTest, Get_Elem) {
    std::vector<std::string> args = { "putElement", "1",
        "putElement", "2", "putElement", "3", "getElement", "getCount"};

    Act(args);

    Assert("GetElem = 1, Number of Elements = 2");
}

TEST_F(QueueAppTest, Get_Not_Existing_Elem) {
    std::vector<std::string> args = {"getElement"};

    Act(args);

    Assert("Queue is empty");
}

TEST_F(QueueAppTest, Top_Not_Existing_Elem) {
    std::vector<std::string> args = { "topElement" };

    Act(args);

    Assert("Queue is empty");
}

TEST_F(QueueAppTest, Put_Into_Full_Queue) {
    std::vector<std::string> args = { "putElement", "1",  "putElement", "2",
        "putElement", "3", "putElement", "4", "putElement", "5",
        "putElement", "6", "putElement", "7", "putElement", "8",
        "putElement", "9", "putElement", "10", "putElement", "11" };

    Act(args);

    Assert("No");
}
