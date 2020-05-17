// Copyright 2020 Zinkov Artem

#include <gtest/gtest.h>
#include <vector>
#include <random>
#include <algorithm>
#include <ctime>
#include "include/odd_even_batcher_merge.h"

TEST(Even_Odd_Batcher_Merge_Test, Merge_Zero_Size_Vector) {
    // Arrange
    std::vector<int> vec1;
    std::vector<int> vec2{ 1, 4, 10 };

    // Act
    std::vector<int> vec3 = merge_batcher(vec1, vec2);

    // Assert
    ASSERT_EQ(vec2, vec3);
}

TEST(Even_Odd_Batcher_Merge_Test, Merge_Ordered_Vector) {
    // Arrange
    std::vector<int> vec1{ 1, 2, 3, 4, 5, 6, 7, 8 };
    std::vector<int> vec2{ 9, 10, 11 };
    std::vector<int> vec3{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };

    // Act
    std::vector<int> res = merge_batcher(vec1, vec2);

    // Assert
    ASSERT_EQ(vec3, res);
}

TEST(Even_Odd_Batcher_Merge_Test, Merge_Vector_One_Size_Element) {
    // Arrange
    std::vector<int> vec1{ 1 };
    std::vector<int> vec2{ 2 };
    std::vector<int> vec3{ 1, 2};

    // Act
    std::vector<int> res = merge_batcher(vec1, vec2);

    // Assert
    ASSERT_EQ(vec3, res);
}

TEST(Even_Odd_Batcher_Merge_Test, Merge_Vector_With_Negative_Elements) {
    // Arrange
    std::vector<int> vec1{ -17, -3, 5, 2 };
    std::vector<int> vec2{ -11, 3, 5, 23, 51 };
    std::vector<int> vec3{ -17, -11, -3, 2, 5, 3, 5, 23, 51 };

    // Act
    std::vector<int> res = merge_batcher(vec1, vec2);

    // Assert
    ASSERT_EQ(vec3, res);
}

TEST(Even_Odd_Batcher_Merge_Test, Merge_Vector_With_Repeating_Elements) {
    // Arrange
    std::vector<int> vec1{ 1, 1, 1, 1 };
    std::vector<int> vec2{ 2, 2, 2, 2, 2 };
    std::vector<int> vec3{ 1, 1, 1, 1, 2, 2, 2, 2, 2 };

    // Act
    std::vector<int> res = merge_batcher(vec1, vec2);

    // Assert
    ASSERT_EQ(vec3, res);
}


TEST(Even_Odd_Batcher_Merge_Test, Merge_Vector_Same_Length) {
    // Arrange
    std::mt19937 gen;
    gen.seed(static_cast<unsigned int>(time(0)));

    std::size_t length = 20;
    std::vector<int> vec1(length);
    std::vector<int> vec2(length);

    for (auto& val : vec1) {
        val = gen() % 100;
    }
    for (auto& val : vec2) {
        val = gen() % 100;
    }

    std::vector<int> vec3(length * 2);
    std::copy(vec1.begin(), vec1.end(), vec3.begin());
    std::copy(vec2.begin(), vec2.end(), vec3.begin() + length);
    std::sort(vec1.begin(), vec1.end());
    std::sort(vec2.begin(), vec2.end());
    std::sort(vec3.begin(), vec3.end());

    // Act
    std::vector<int> res = merge_batcher(vec1, vec2);

    // Assert
    ASSERT_EQ(vec3, res);
}

TEST(Even_Odd_Batcher_Merge_Test, Merge_Vector_Odd_Length) {
    // Arrange
    std::mt19937 gen;
    gen.seed(static_cast<unsigned int>(time(0)));

    std::size_t length1 = 7;
    std::size_t length2 = 21;
    std::vector<int> vec1(length1);
    std::vector<int> vec2(length2);

    for (auto& val : vec1) {
        val = gen() % 100;
    }
    for (auto& val : vec2) {
        val = gen() % 100;
    }

    std::vector<int> vec3(length1 + length2);
    std::copy(vec1.begin(), vec1.end(), vec3.begin());
    std::copy(vec2.begin(), vec2.end(), vec3.begin() + length1);
    std::sort(vec1.begin(), vec1.end());
    std::sort(vec2.begin(), vec2.end());
    std::sort(vec3.begin(), vec3.end());

    // Act
    std::vector<int> res = merge_batcher(vec1, vec2);

    // Assert
    ASSERT_EQ(vec3, res);
}

TEST(Even_Odd_Batcher_Merge_Test, Merge_Vector_Even_Length) {
    // Arrange
    std::mt19937 gen;
    gen.seed(static_cast<unsigned int>(time(0)));

    std::size_t length1 = 8;
    std::size_t length2 = 16;
    std::vector<int> vec1(length1);
    std::vector<int> vec2(length2);

    for (auto& val : vec1) {
        val = gen() % 100;
    }
    for (auto& val : vec2) {
        val = gen() % 100;
    }

    std::vector<int> vec3(length1 + length2);
    std::copy(vec1.begin(), vec1.end(), vec3.begin());
    std::copy(vec2.begin(), vec2.end(), vec3.begin() + length1);
    std::sort(vec1.begin(), vec1.end());
    std::sort(vec2.begin(), vec2.end());
    std::sort(vec3.begin(), vec3.end());

    // Act
    std::vector<int> res = merge_batcher(vec1, vec2);

    // Assert
    ASSERT_EQ(vec3, res);
}

TEST(Even_Odd_Batcher_Merge_Test, Merge_Vector_Odd_Even_Length) {
    // Arrange
    std::mt19937 gen;
    gen.seed(static_cast<unsigned int>(time(0)));

    std::size_t length1 = 25;
    std::size_t length2 = 34;
    std::vector<int> vec1(length1);
    std::vector<int> vec2(length2);

    for (auto& val : vec1) {
        val = gen() % 100;
    }
    for (auto& val : vec2) {
        val = gen() % 100;
    }

    std::vector<int> vec3(length1 + length2);
    std::copy(vec1.begin(), vec1.end(), vec3.begin());
    std::copy(vec2.begin(), vec2.end(), vec3.begin() + length1);
    std::sort(vec1.begin(), vec1.end());
    std::sort(vec2.begin(), vec2.end());
    std::sort(vec3.begin(), vec3.end());

    // Act
    std::vector<int> res = merge_batcher(vec1, vec2);

    // Assert
    ASSERT_EQ(vec3, res);
}

TEST(Even_Odd_Batcher_Merge_Test, Merge_Big_Vector) {
    // Arrange
    std::mt19937 gen;
    gen.seed(static_cast<unsigned int>(time(0)));

    std::size_t length1 = 500;
    std::size_t length2 = 500;
    std::vector<int> vec1(length1);
    std::vector<int> vec2(length2);

    for (auto& val : vec1) {
        val = gen() % 1000;
    }
    for (auto& val : vec2) {
        val = gen() % 1000;
    }

    std::vector<int> vec3(length1 + length2);
    std::copy(vec1.begin(), vec1.end(), vec3.begin());
    std::copy(vec2.begin(), vec2.end(), vec3.begin() + length1);
    std::sort(vec1.begin(), vec1.end());
    std::sort(vec2.begin(), vec2.end());
    std::sort(vec3.begin(), vec3.end());

    // Act
    std::vector<int> res = merge_batcher(vec1, vec2);
    // Assert
    ASSERT_EQ(vec3, res);
}
