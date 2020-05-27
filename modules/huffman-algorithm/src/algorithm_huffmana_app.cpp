// Copyright 2020 Golovanova Elena

#include <include/algorithm_huffmana.h>
#include <include/algorithm_huffmana_app.h>
#include <string>
#include <sstream>
#include <vector>

AlgorithmHuffmanaApp::AlgorithmHuffmanaApp() : message_("") {}

void AlgorithmHuffmanaApp::help(const char* appname, const char* message) {
  message_ =
    std::string(message) +"\n\n" +
    "This app encodes words using the Huffman algorithm\n\n" +
    "Please enter words separated by spaces\n\n" +

    "  $ " + appname + " <word1> <word2> ... <wordN>\n\n";
}

bool AlgorithmHuffmanaApp::validateNumberOfArguments(int argc, const char** argv) {
  if (argc == 1) {
    help(argv[0], "ERR0R: should be non-empty string");
    return false;
  }
  
  return true;
}

std::string AlgorithmHuffmanaApp:: convert(std::vector<std::string> _part_of_result) {
  std::string _result = "";
  for (unsigned int j = 0; j < _part_of_result.size(); j++)
    _result = _result + _part_of_result[j];
  return _result;
}

std::string AlgorithmHuffmanaApp:: operator()(int argc, const char** argv) {
  if (!validateNumberOfArguments(argc, argv))
    return message_;
  int number_arg = argc;
  std::vector<std::string> part_of_result;
  std::string result = ""; //Нулевая?
  for (int i = 1; i < number_arg; i++) {
    HuffmanTree Tree(argv[i]);
    Tree.CreateEncodingTable();
    part_of_result=Tree.Encode(argv[i]);
    result = result + convert(part_of_result);
  }
  return result;
}




//AlgorithmHuffmanaApp::AlgorithmHuffmanaApp(): message_{}
//
//void AlgorithmHuffmanaApp::Help(const char* appname, const char* message) {
//  message_=
//    std::string(message)+
//    "This is the Huffman algorithm\n\n" +
//    "Please provide arguments in the following format:\n\n" +
//    "  $ " + appname +
//}

