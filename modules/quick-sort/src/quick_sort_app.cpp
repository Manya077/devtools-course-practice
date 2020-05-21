// Copyright 2020 Poletueva Anastasia

#include "include/quick_sort.h"
#include "../include/quick_sort_app.h"
#include <string>
#include <sstream>
#include <vector>

QuickSortApp::QuickSortApp() : message_("") {}

void QuickSortApp::Help(const char * appname, const char * message) {
  message_ =
    std::string(message) +
    "This is a quick sort application.\n\n" +
    "Please provide arguments in the following format:\n\n" +

    "  $ " + appname + " <integer numbers>" +
    "Where  <integer numbers> is a set of some integer numbers\n";
}

bool QuickSortApp::NumbersOfArguments(int argc, const char** argv) {
  if (argc == 1) {
    Help(argv[0]);
    return false;
  }
  return true;
}

std::vector<int> QuickSortApp::ParseVector(int argc, const char** argv) {
  std::vector<int> vec;
  for (int i = 1; i < argc; i++) {
    vec.push_back(std::stoi(argv[i]));
  }
  return vec;
}

std::vector<int> QuickSortApp::Sorting(const std::vector<int>& vec) {
  QuickSort qsort(vec);
  qsort.QSort(0, (vec.size() - 1));
  std::vector<int> res = qsort.GetVector();
  return res;
}

std::string  QuickSortApp::CreateMessage(const std::vector<int>& vec) {
  std::ostringstream stream;
  int sz = vec.size() - 1;
  for (int i = 0; i < sz; ++i) stream << vec[i] << " ";
  stream << vec[sz];
  return stream.str();
}

std::string  QuickSortApp::operator()(int argc, const char** argv) {
  std::vector<int> vec;
  if (!NumbersOfArguments(argc, argv)) {
    return message_;
  }
  try {
    vec = ParseVector(argc, argv);
  }
  catch (std::exception) {
    return std::string("Wrong number format!");
  }

  message_ = CreateMessage(Sorting(vec));

  return message_;
}
