// Copyright 2020 Poletueva Anastasia

#include <gtest/gtest.h>
#include <string>
#include <vector>
#include "include/algorithm_huffmana.h"

TEST(AlgorithmHuffmanaTest, Can_Create_Histoghram_1) {
  // Arrange
  std::string text = "AAASREESR";
  std::vector<int> expected = { 3, 2, 2, 2};

  // Act
  std::vector<int> v = HuffmanTree().CreateHistogram(text);
  std::vector<int> res = { v['A'], v['S'], v['R'], v['E'] };

  // Assert
  EXPECT_EQ(expected, res);
}

TEST(AlgorithmHuffmanaTest, Can_Create_Histoghram_2) {
  // Arrange
  std::string text = "AAARAARRREREESRR";
  std::vector<int> expected = { 5, 1, 7, 3};

  // Act
  std::vector<int> v = HuffmanTree().CreateHistogram(text);
  std::vector<int> res = { v['A'], v['S'], v['R'], v['E']};

  // Assert
  EXPECT_EQ(expected, res);
}



TEST(AlgorithmHuffmanaTest, Can_Create_Encoding_Table_1) {
  // Arrange
  std::string text = "AAASAAAAREEAAAAAAAAAAASR";
  std::string expect = "1";

  // Act
  HuffmanTree Tree(text);
  Tree.CreateEncodingTable();

  // Assert
  EXPECT_EQ(expect, Tree.getSimbolCode('A'));
}

TEST(AlgorithmHuffmanaTest, Can_Create_Encoding_Table_2) {
  // Arrange
  std::string text = "AASRRR";
  std::string expect = "1";

  // Act
  HuffmanTree Tree(text);
  Tree.CreateEncodingTable();

  // Assert
  EXPECT_EQ(expect, Tree.getSimbolCode('R'));
}

TEST(AlgorithmHuffmanaTest, Huffman_Coding_Test_1) {
  // Arrange
  std::string text = "AAASRERASR";
  std::vector<std::string> vec = { "1", "1", "1",
    "001", "01", "0001", "01", "1", "001", "01"};

  // Act
  HuffmanTree Tree(text);
  Tree.CreateEncodingTable();

  // Assert
  EXPECT_EQ(vec, Tree.Encode(text));
}

TEST(AlgorithmHuffmanaTest, Huffman_Coding_Test_2) {
  // Arrange
  std::string text = "AAASRERTWTASR";
  std::vector<std::string> vec = { "01", "01", "01",
    "000", "10", "111", "10", "001", "1101", "001",
    "01", "000", "10" };

  // Act
  HuffmanTree Tree(text);
  Tree.CreateEncodingTable();

  // Assert
  EXPECT_EQ(vec, Tree.Encode(text));
}
