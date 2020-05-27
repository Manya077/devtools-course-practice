// Copyright 2020 Golovanova Elena

#ifndef MODULES_HUFFMAN_ALGORITHM_INCLUDE_ALGORITHM_HUFFMANA_APP_H_
#define MODULES_HUFFMAN_ALGORITHM_INCLUDE_ALGORITHM_HUFFMANA_APP_H_

#include <string>
#include <vector>

class AlgorithmHuffmanaApp {
 public:
   AlgorithmHuffmanaApp();
   std::string operator()(int argc, const char** argv);
 private:
   void Help(const char* appname, const char* message = "");
};


#endif  // MODULES_HUFFMAN_ALGORITHM_INCLUDE_ALGORITHM_HUFFMANA_APP_H_