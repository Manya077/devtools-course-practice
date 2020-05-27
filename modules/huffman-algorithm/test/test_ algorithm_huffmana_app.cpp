// Copyright 2020 Golovanova Elena

#include <gtest/gtest.h>

#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>

#include <include/algorithm_huffmana_app.h>

using ::testing::internal::RE;
using std::vector;
using std::string;

class AlgorithmHuffmanaAppTest : public ::testing::Test {
protected:
  // virtual void SetUp() {}

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
  AlgorithmHuffmanaApp app_;
  string output_;
};

TEST_F(AlgorithmHuffmanaAppTest, Do_Print_Help_Without_Arguments) {
  vector<string> args = {};

  Act(args);

  Assert("ERR0R: should be non-empty string\\..*");
}