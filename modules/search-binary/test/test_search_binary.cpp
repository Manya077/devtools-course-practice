// Copyright 2020 Tihomirova Mariya

#include <gtest/gtest.h>

#include "include/search_binary.h"

TEST(SearchBinaryTest, SearchInNullSizeArray) {
    SearchBinary search_engine;
    int *array = NULL;
    int size = 0;
    int key = 1;
    int res;
    res = search_engine.Search(key, array, size);
    EXPECT_EQ(-1, res);
}

TEST(SearchBinaryTest, CanSearch) {
    SearchBinary search_engine;
    int array[4] = {1, 3, 5, 7};
    int size = 4;
    int key = 5;
    int res;
    res = search_engine.Search(key, array, size);
    EXPECT_EQ(2, res);
}

TEST(SearchBinaryTest, CanSearchLessThenAll) {
    SearchBinary search_engine;
    int array[4] = {1, 3, 5, 7};
    int size = 4;
    int key = -10;
    int res;
    res = search_engine.Search(key, array, size);
    EXPECT_EQ(-1, res);
}

TEST(SearchBinaryTest, CanSearchMoreThenAll) {
    SearchBinary search_engine;
    int array[4] = {1, 3, 5, 7};
    int size = 4;
    int key = 10;
    int res;
    res = search_engine.Search(key, array, size);
    EXPECT_EQ(-1, res);
}

TEST(SearchBinaryTest, CanSearchInMiddle) {
    SearchBinary search_engine;
    int array[3] = {1, 3, 5};
    int size = 3;
    int key = 3;
    int res;
    res = search_engine.Search(key, array, size);
    EXPECT_EQ(1, res);
}

TEST(SearchBinaryTest, CanSearchInRightBoard) {
    SearchBinary search_engine;
    int array[3] = {1, 3, 5};
    int size = 3;
    int key = 5;
    int res;
    res = search_engine.Search(key, array, size);
    EXPECT_EQ(2, res);
}

TEST(SearchBinaryTest, CanSearchMissingElement) {
    SearchBinary search_engine;
    int array[4] = {1, 3, 5, 7};
    int size = 4;
    int key = 2;
    int res;
    res = search_engine.Search(key, array, size);
    EXPECT_EQ(-1, res);
}
