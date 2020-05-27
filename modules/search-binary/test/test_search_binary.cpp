// Copyright 2020 Tihomirova Mariya

#include <gtest/gtest.h>

#include "include/search_binary.h"

TEST(SearchBinaryTest, SearchInNullSizeArray) {
    // Arrange
    SearchBinary search_engine;
    int* array = NULL;
    int size = 0;
    int key = 1;
    int res;
    // Act
    res = search_engine.Search(key, array, size);
    // Assert
    EXPECT_EQ(-1, res);
}

TEST(SearchBinaryTest, CanSearch) {
    // Arrange
    SearchBinary search_engine;
    int array[4] = { 1, 3, 5, 7 };
    int size = 4;
    int key = 5;
    int res;
    // Act
    res = search_engine.Search(key, array, size);
    // Assert
    EXPECT_EQ(2, res);
}

TEST(SearchBinaryTest, CanSearchLessThenAll) {
    // Arrange
    SearchBinary search_engine;
    int array[4] = { 1, 3, 5, 7 };
    int size = 4;
    int key = -10;
    int res;
    // Act
    res = search_engine.Search(key, array, size);
    // Assert
    EXPECT_EQ(-1, res);
}

TEST(SearchBinaryTest, CanSearchMoreThenAll) {
    // Arrange
    SearchBinary search_engine;
    int array[4] = { 1, 3, 5, 7 };
    int size = 4;
    int key = 10;
    int res;
    // Act
    res = search_engine.Search(key, array, size);
    // Assert
    EXPECT_EQ(-1, res);
}

TEST(SearchBinaryTest, CanSearchInMiddle) {
    // Arrange
    SearchBinary search_engine;
    int array[3] = { 1, 3, 5 };
    int size = 3;
    int key = 3;
    int res;
    // Act
    res = search_engine.Search(key, array, size);
    // Assert
    EXPECT_EQ(1, res);
}

TEST(SearchBinaryTest, CanSearchInRightBoard) {
    // Arrange
    SearchBinary search_engine;
    int array[3] = { 1, 3, 5 };
    int size = 3;
    int key = 5;
    int res;
    // Act
    res = search_engine.Search(key, array, size);
    // Assert
    EXPECT_EQ(2, res);
}

TEST(SearchBinaryTest, CanSearchMissingElement) {
    // Arrange
    SearchBinary search_engine;
    int array[4] = { 1, 3, 5, 7 };
    int size = 4;
    int key = 2;
    int res;
    // Act
    res = search_engine.Search(key, array, size);
    // Assert
    EXPECT_EQ(-1, res);
}

TEST(SearchBinaryTest, SearchInNullSizeArray_Vector) {
    // Arrange
    SearchBinary search_engine;
    std::vector<int> array;
    int key = 1;
    int res;
    // Act
    res = search_engine.Search(key, array);
    // Assert
    EXPECT_EQ(-1, res);
}

TEST(SearchBinaryTest, CanSearch_Vector) {
    // Arrange
    SearchBinary search_engine;
    std::vector<int> array = { 1, 3, 5, 7 };
    int key = 5;
    int res;
    // Act
    res = search_engine.Search(key, array);
    // Assert
    EXPECT_EQ(2, res);
}

TEST(SearchBinaryTest, CanSearchLessThenAll_Vector) {
    // Arrange
    SearchBinary search_engine;
    std::vector<int> array = { 1, 3, 5, 7 };
    int key = -10;
    int res;
    // Act
    res = search_engine.Search(key, array);
    // Assert
    EXPECT_EQ(-1, res);
}

TEST(SearchBinaryTest, CanSearchMoreThenAll_Vector) {
    // Arrange
    SearchBinary search_engine;
    std::vector<int> array = { 1, 3, 5, 7 };
    int key = 10;
    int res;
    // Act
    res = search_engine.Search(key, array);
    // Assert
    EXPECT_EQ(-1, res);
}

TEST(SearchBinaryTest, CanSearchInMiddle_Vector) {
    // Arrange
    SearchBinary search_engine;
    std::vector<int> array = { 1, 3, 5 };
    int key = 3;
    int res;
    // Act
    res = search_engine.Search(key, array);
    // Assert
    EXPECT_EQ(1, res);
}

TEST(SearchBinaryTest, CanSearchInRightBoard_Vector) {
    // Arrange
    SearchBinary search_engine;
    std::vector<int> array = { 1, 3, 5 };
    int key = 5;
    int res;
    // Act
    res = search_engine.Search(key, array);
    // Assert
    EXPECT_EQ(2, res);
}

TEST(SearchBinaryTest, CanSearchMissingElement_Vector) {
    // Arrange
    SearchBinary search_engine;
    std::vector<int> array = { 1, 3, 5, 7 };
    int key = 2;
    int res;
    // Act
    res = search_engine.Search(key, array);
    // Assert
    EXPECT_EQ(-1, res);
}
