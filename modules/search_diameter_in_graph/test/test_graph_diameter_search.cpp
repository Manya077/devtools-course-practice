// Copyright 2020 Mityagina Daria

#include <gtest/gtest.h>
#include <vector>
#include <list>
#include "include/graph_diameter_search.h"

class MityaginaGraphDiameterSearch : public ::testing::Test {
};

TEST_F(MityaginaGraphDiameterSearch, Simple_example) {
  int numberOfVert = 6;
  Graph g(numberOfVert);
  /*
         1 
        / \ 
        2   3 
       / \   \
      4   5   6
  */

  g.adjList = std::vector< std::list<int> >(g.numberOfVert + 1);

  g.adjList[1].push_back(2);
  g.adjList[2].push_back(1);
  g.adjList[1].push_back(3);
  g.adjList[3].push_back(1);
  g.adjList[2].push_back(4);
  g.adjList[4].push_back(2);
  g.adjList[2].push_back(5);
  g.adjList[5].push_back(2);
  g.adjList[3].push_back(6);
  g.adjList[6].push_back(3);

  EXPECT_EQ(4, g.diameterSearch());
}

TEST_F(MityaginaGraphDiameterSearch, Can_handle_invalid_number_of_ver) {
  // Arrange
  int number = -3;

  // Act & Assert
  ASSERT_ANY_THROW(Graph graph(number));
}

TEST_F(MityaginaGraphDiameterSearch, Can_create_graph) {
  // Arrange
  int number = 5;

  // Act & Assert
  ASSERT_NO_THROW(Graph graph(number));
}

TEST_F(MityaginaGraphDiameterSearch, Can_addEdge) {
  // Arrange
  int number = 5;

  // Act
  Graph graph(number);

  // Assert
  ASSERT_NO_THROW(graph.addEdge(1, 3));
}

TEST_F(MityaginaGraphDiameterSearch, Adding_wrong_edge) {
  // Arrange
  int number = 5;

  // Act
  Graph graph(number);

  // Assert
  ASSERT_ANY_THROW(graph.addEdge(-2, -3));
}

TEST_F(MityaginaGraphDiameterSearch, Can_handle_wrong_num_of_edges) {
  // Arrange
  int number = 1;
  Graph graph(number);

  // Act && Assert
  ASSERT_ANY_THROW(graph.addEdge(1, 2));
}

TEST_F(MityaginaGraphDiameterSearch, Wrong_num_of_edges_to_full_graph) {
  // Arrange
  int number = 2;
  Graph graph(number);

  // Act
  graph.adjList[1].push_back(2);
  graph.adjList[2].push_back(1);

  // Assert
  ASSERT_ANY_THROW(graph.addEdge(2, 3));
}

TEST_F(MityaginaGraphDiameterSearch, Adding_existing_edge) {
  // Arrange
  int number = 3;
  Graph graph(number);

  // Act
  graph.adjList[1].push_back(2);
  graph.adjList[2].push_back(1);

  // Assert
  ASSERT_ANY_THROW(graph.addEdge(2, 1));
}


TEST_F(MityaginaGraphDiameterSearch, Dfs_with_invalid_parameters) {
  // Arrange
  int number = 5;
  int maxCount = 0;

  // Act
  Graph graph(number);

  // Assert
  ASSERT_ANY_THROW(graph.dfs(-1, &maxCount));
}

TEST_F(MityaginaGraphDiameterSearch, Case_with_500_vertices) {
  // Arrange
  int number = 500;
  Graph graph(number);

  // Act
  for (int i = 0; i < number; i++) {
    if (i + 2 < number && graph.numberOfEdges < number * ((number - 1) / 2)) {
      graph.addEdge(i + 1, i + 2);
    }
  }

  // Assert
  ASSERT_NO_THROW(graph.diameterSearch());
}

TEST_F(MityaginaGraphDiameterSearch, Case_with_100_vertices) {
  // Arrange
  int number = 100;
  Graph graph(number);

  // Act
  for (int i = 0; i < number; i++) {
    if (i + 2 < number && graph.numberOfEdges < number * ((number - 1) / 2)) {
      graph.addEdge(i + 1, i + 2);
    }
  }

  // Assert
  ASSERT_NO_THROW(graph.diameterSearch());
}

TEST_F(MityaginaGraphDiameterSearch, dfsHelper_with_invalid_parameters) {
  // Arrange
  int number = 5;
  int maxCount = 0;

  // Act
  Graph graph(number);
  std::vector<bool> visited(number + 1);

  for (int i = 1; i <= number; ++i) {
    visited[i] = false;
  }

  // Assert
  ASSERT_ANY_THROW(graph.dfsHelper(-1, 2, visited, &maxCount));
}

TEST_F(MityaginaGraphDiameterSearch, dfsHelper_with_invalid_parameters_2) {
  // Arrange
  int number = 5;
  int maxCount = 0;

  // Act
  Graph graph(number);
  std::vector<bool> visited(number + 1);

  for (int i = 1; i <= number; ++i) {
    visited[i] = false;
  }

  // Assert
  ASSERT_ANY_THROW(graph.dfsHelper(1, -2, visited, &maxCount));
}
