// Copyright 2020 Zinkov Artem

#ifndef MODULES_ODD_EVEN_BATCHER_MERGE_INCLUDE_MERGE_BATCHER_APP_H_
#define MODULES_ODD_EVEN_BATCHER_MERGE_INCLUDE_MERGE_BATCHER_APP_H_

#include <string>
#include <vector>

class Merge_Batcher_App {
 public:
    Merge_Batcher_App();
    std::string operator()(int argc, const char** argv);

 private:
    void help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);
    std::string message_;
    typedef struct {
        std::vector<int> v1;
        std::vector<int> v2;
    } Arguments;
};

#endif  // MODULES_ODD_EVEN_BATCHER_MERGE_INCLUDE_MERGE_BATCHER_APP_H_
