// Copyright 2020 Mityagina Daria

#include "include/graph_diameter_search.h"
#include <limits.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

Graph::Graph(int n) {
  if (n <= 0) {
    throw "Invalid number of vertices!";
  }
  numberOfVert = n;
  numberOfEdges = 0;
  adjList = std::vector< std::list<int> >(n + 1);
}

void Graph::addEdge(int first, int second) {
  if (first <= 0 || second <= 0) {
    throw "Can't add this edge. Vertices indexes should be > 0.";
  }
  numberOfEdges++;
  if (numberOfEdges > numberOfVert * ((numberOfVert - 1) / 2)) {
    throw "Can't add this edge. Complete graph.";
  }
  auto it = std::find(adjList[first].begin(), adjList[first].end(), second);
  if (it != adjList[first].end())
    throw "Can't add existing edge.";

  adjList[first].push_back(second);
  adjList[second].push_back(first);
}

void Graph::dfsHelper(int node, int count, std::vector<bool> vis, int *cMax) {
  if (node <= 0) {
    throw "Invalid node index!";
  } else if (count <= 0) {
    throw "Invalid count!";
  }

  vis[node] = true;
  count++;
  for (auto i = adjList[node].begin(); i != adjList[node].end(); ++i) {
    if (!vis[*i]) {
      if (count >= *cMax) {
          *cMax = count;
          x = *i;
      }
      dfsHelper(*i, count, vis, cMax);
    }
  }
}

void Graph::dfs(int node, int *countMax) {
  if (node <= 0) {
    throw "Invalid node index!";
  }

  std::vector<bool> visited(numberOfVert + 1);
  int count = 0;

  for (int i = 1; i <= numberOfVert; ++i) {
    visited[i] = false;
  }

  dfsHelper(node, count + 1, visited, countMax);
}

int Graph::diameterSearch() {
  int countMax = INT_MIN;

  // farthest node X from random node
  dfs(1, &countMax);

  // check the farthest node from X
  dfs(x, &countMax);

  return (countMax - 1);
}
