// Copyright 2020 Boganov Sergei

#ifndef MODULES_SEGMENT_TREE_APP_INCLUDE_SEGMENT_TREE_APP_H_
#define MODULES_SEGMENT_TREE_APP_INCLUDE_SEGMENT_TREE_APP_H_

#include <string>
#include <vector>

class SegmentTreeApp {
 public:
     SegmentTreeApp() : message_("") {}
     std::string operator()(int argc, const char** argv);

 private:
     void help(const char* appname, const char* message = "");
     bool validateNumberOfArguments(int argc, const char** argv);
     std::string message_;
     using Arguments = struct {
        int count_of_elements;
        std::vector<int> elements;
        int count_of_queries;
        std::vector<int> left_borders;
        std::vector<int> right_borders;
        std::string operation;
     };
};

#endif  // MODULES_SEGMENT_TREE_APP_INCLUDE_SEGMENT_TREE_APP_H_
