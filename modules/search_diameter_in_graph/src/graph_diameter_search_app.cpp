// Copyright 2020 Golubeva Anna

#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include "include/graph_diameter_search_app.h"

int GraphApp::parseValue(const std::string& data) {
  int value;
    try {
        value = std::stoi(data);
    }
    catch(...) {
        throw std::string("Wrong arguments");
    }

    return value;
}

std::string GraphApp::operator()(int argc, const char** argv) {
  if (!validateNumberOfArguments(argc, argv)) {
    return message_;
    }
  std::ostringstream stream;
  try {
      int n = parseValue(argv[1]);
      Graph graph(n);
      int edges = argc - 1;
      for (int i = 2; i < edges; i++) {
      graph.addEdge(parseValue(argv[i]), parseValue(argv[i+1]));
      }
      stream << graph.diameterSearch();
    }
    catch(std::string& str) {
        return str;
    }
  message_ = stream.str();

  return message_;
}

void GraphApp::help(const char* appname, const char* message) {
  message_ =
      std::string(message) +
      "This is a graph diameter search application.\n\n"+
      "Please provide arguments in the following format:\n\n"+
      "  $ " + appname + " <number of vertices> " + "<first vertex of edge>" +
      "<second vertex of edge>" + "..." +"\n\n" +
      "Where <number of vertices> is a natural number\n" +
      "<first vertex of edge> <first vertex of edge>, ... are natural numbers "+
      "which set the edges of the graph\n.";
}

bool GraphApp::validateNumberOfArguments(int argc, const char** argv) {
  if (argc == 1) {
    help(argv[0]);
    return false;
  }
  int n = parseValue(argv[1]);
  if (argc > n*(n - 1) + 2 || argc < 4) {
    help(argv[0], "Wrong arguments\n\n");
    return false;
  }
  return true;
}
