// Copyright 2020 Mityagina Daria

#ifndef MODULES_SEARCH_DIAMETER_IN_GRAPH_INCLUDE_GRAPH_DIAMETER_SEARCH_H_
#define MODULES_SEARCH_DIAMETER_IN_GRAPH_INCLUDE_GRAPH_DIAMETER_SEARCH_H_

#include <queue>
#include <utility>
#include <vector>
#include <cstdlib>
#include <list>
#include <set>

class Graph {
 public :
  std::vector< std::list<int> > adjList;
  int numberOfVert;
  int numberOfEdges;
  int x;

  explicit Graph(int n);

  void addEdge(int first, int second);
  void dfsHelper(int node, int count, std::vector<bool> visited, int *countMax);
  void dfs(int node, int *countMax);
  int diameterSearch();
};

#endif  // MODULES_SEARCH_DIAMETER_IN_GRAPH_INCLUDE_GRAPH_DIAMETER_SEARCH_H_
