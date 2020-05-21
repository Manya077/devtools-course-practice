// Copyright 2020 Devlikamov Vladislav

#include <gtest/gtest.h>
#include <vector>

#include "include/segment-tree.h"

TEST(SegmentTreeTest, Can_Create_Segment_Tree) {
    // Arrange & Act & Assert
    EXPECT_NO_THROW(SegmentTree tree(5));
}

TEST(SegmentTreeTest, Can_Create_Segment_Tree_With_Vector) {
    // Arrange
    std::vector <int> test = {1, 2, 3};

    // Act & Assert
    EXPECT_NO_THROW(SegmentTree tree(test, "+"));
}

TEST(SegmentTreeTest, Can_Create_Segment_Tree_With_Negative_Size) {
    // Arrange & Act & Assert
    EXPECT_ANY_THROW(SegmentTree tree(-1));
}

TEST(SegmentTreeTest, Can_Create_Segment_Tree_With_Zero_Vector) {
    // Arrange
    std::vector <int> test;

    // Act & Assert
    EXPECT_ANY_THROW(SegmentTree tree(test, "+"));
}

TEST(SegmentTreeTest, Test_Function_Build_With_3_elements) {
    // Arrange
    std::vector <int> test = {1, 2, 3};

    // Act
    SegmentTree tree(test, "+");
    std::vector <int> expected = {0, 6, 3, 3, 1, 2, 0, 0, 0, 0, 0, 0};
    std::vector <int> v = tree.Get();

    // Assert
    EXPECT_EQ(expected, v);
}

TEST(SegmentTreeTest, Test_Function_Build_With_4_elements) {
    // Arrange
    std::vector <int> test = {1, 2, 3, 4};

    // Act
    SegmentTree tree(test, "+");
    std::vector <int> expected = {0, 10, 3, 7, 1, 2, 3, 4, 0, 0, 0,
                                  0, 0, 0, 0, 0};
    std::vector <int> v = tree.Get();

    // Assert
    EXPECT_EQ(expected, v);
}

TEST(SegmentTreeTest, Test_Function_Build_With_50_zero_elements) {
    // Arrange
    int size = 50;
    std::vector <int> test(size, 0);

    // Act
    SegmentTree tree(test, "+");
    std::vector <int> expected(4*size, 0);

    // Assert
    EXPECT_EQ(expected, tree.Get());
}

TEST(SegmentTreeTest, Test_Range_Sum_Query_With_5_elements) {
    // Arrange
    std::vector <int> test = {1, 2, 3, 4, 5};

    // Act
    SegmentTree tree(test, "+");

    // Arrange
    EXPECT_EQ(tree.query(0, 2), 6);
}

TEST(SegmentTreeTest, Test_Range_Sum_Query_With_4_elements) {
    // Arrange
    std::vector <int> test = {1, 2, 3, 4};

    // Act
    SegmentTree tree(test, "+");

    // Arrange
    EXPECT_EQ(tree.query(2, 3), 7);
}

TEST(SegmentTreeTest, Test_Range_Sum_Query_With_6_elements) {
    // Arrange
    std::vector <int> test = {1, 2, 3, 4, 5, 6};

    // Act
    SegmentTree tree(test, "+");

    // Arrange
    EXPECT_EQ(tree.query(1, 4), 14);
}

TEST(SegmentTreeTest, Test_Range_Sum_Query_With_7_elements) {
    // Arrange
    std::vector <int> test = {1, 2, 3, 4, 5, 6, 7};

    // Act
    SegmentTree tree(test, "+");

    // Arrange
    EXPECT_EQ(tree.query(4, 5), 11);
}

TEST(SegmentTreeTest, Test_Range_Sum_Query_With_2_elements) {
    // Arrange
    std::vector <int> test = {1, 2};

    // Act
    SegmentTree tree(test, "+");

    // Arrange
    EXPECT_ANY_THROW(tree.query(-1, 1));
}

TEST(SegmentTreeTest, Test_Range_Sum_Query_With_2_elements_1) {
    // Arrange
    std::vector <int> test = {1, 2};

    // Act
    SegmentTree tree(test, "+");

    // Arrange
    EXPECT_ANY_THROW(tree.query(0, -1));
}

TEST(SegmentTreeTest, Test_Range_Sum_Query_With_2_elements_2) {
    // Arrange
    std::vector <int> test = {1, 2};

    // Act
    SegmentTree tree(test, "+");

    // Arrange
    EXPECT_ANY_THROW(tree.query(1, 0));
}

TEST(SegmentTreeTest, Test_Range_Sum_Query_With_2_elements_3) {
    // Arrange
    std::vector <int> test = {1, 2};

    // Act
    SegmentTree tree(test, "+");

    // Arrange
    EXPECT_ANY_THROW(tree.query(1, 3));
}

TEST(SegmentTreeTest, Test_Range_Sum_Query_With_7_elements_and_update) {
    // Arrange
    std::vector <int> test = {1, 2, 3, 4, 5, 6, 7};

    // Act
    SegmentTree tree(test, "+");
    tree.update(3, -5);

    // Arrange
    EXPECT_EQ(tree.query(3, 4), 0);
}


TEST(SegmentTreeTest, Test_Range_Sum_Query_With_5_elements_and_update) {
    // Arrange
    std::vector <int> test = {1, 2, 3, 4, 5};

    // Act
    SegmentTree tree(test, "+");
    tree.update(1, 0);

    // Arrange
    EXPECT_EQ(tree.query(0, 2), 4);
}

TEST(SegmentTreeTest, Test_Range_Sum_Query_With_6_elements_and_2_update) {
    // Arrange
    std::vector <int> test = {1, 2, 3, 4, 5, 6};

    // Act
    SegmentTree tree(test, "+");
    tree.update(1, 0);
    tree.update(1, -1);

    // Arrange
    EXPECT_EQ(tree.query(0, 2), 3);
}

TEST(SegmentTreeTest, Test_Range_Sum_Query_With_2_elements_update) {
    // Arrange
    std::vector <int> test = {1, 2};

    // Act
    SegmentTree tree(test, "+");

    // Arrange
    EXPECT_ANY_THROW(tree.update(-1, 1));
}

TEST(SegmentTreeTest, Test_Range_Sum_Query_With_3_elements_update) {
    // Arrange
    std::vector <int> test = {1, 2, 3};

    // Act
    SegmentTree tree(test, "+");

    // Arrange
    EXPECT_ANY_THROW(tree.update(3, 1));
}

TEST(SegmentTreeTest, Test_Range_Max_Query_With_5_elements) {
    // Arrange
    std::vector <int> test = {1, 2, 3, 4, 5};

    // Act
    SegmentTree tree(test, "max");

    // Arrange
    EXPECT_EQ(tree.query(0, 2), 3);
}


TEST(SegmentTreeTest, Test_Range_Min_Query_With_4_elements) {
    // Arrange
    std::vector <int> test = {1, 2, 3, 4};

    // Act
    SegmentTree tree(test, "min");

    // Arrange
    EXPECT_EQ(tree.query(2, 3), 3);
}

TEST(SegmentTreeTest, Test_Range_Gcd_Query_With_6_elements) {
    // Arrange
    std::vector <int> test = {1, 2, 3, 4, 5, 6};

    // Act
    SegmentTree tree(test, "gcd");

    // Arrange
    EXPECT_EQ(tree.query(2, 4), 1);
}

TEST(SegmentTreeTest, Test_Range_Maximum_Query_With_7_elements) {
    // Arrange
    std::vector <int> test = {2, 2, 3, 4, 8, 6, 12};

    // Act
    SegmentTree tree(test, "max");

    // Arrange
    EXPECT_EQ(tree.query(1, 5), 8);
}

TEST(SegmentTreeTest, Test_Range_Maximum_Query_With_7_elements_and_update) {
    // Arrange
    std::vector <int> test = {2, 2, 3, 4, 8, 6, 12};

    // Act
    SegmentTree tree(test, "max");
    tree.update(1, 100);

    // Arrange
    EXPECT_EQ(tree.query(1, 5), 100);
}

TEST(SegmentTreeTest, Test_Range_Minimum_Query_With_7_elements_and_update) {
    // Arrange
    std::vector <int> test = {2, 2, 3, 4, 8, 6, 12};

    // Act
    SegmentTree tree(test, "min");
    tree.update(1, -100);

    // Arrange
    EXPECT_EQ(tree.query(1, 5), -100);
}

TEST(SegmentTreeTest, Test_Range_Gcd_Query_With_6_elements_and_update) {
    // Arrange
    std::vector <int> test = {1, 2, 3, 4, 5, 6};

    // Act
    SegmentTree tree(test, "gcd");
    tree.update(2, 2);

    // Arrange
    EXPECT_EQ(tree.query(1, 3), 2);
}

TEST(SegmentTreeTest, Test_Segment_tree_with_operation_minus) {
    // Arrange
    std::vector <int> test = {1, 2, 3};

    // Act & Assert
    EXPECT_ANY_THROW(SegmentTree tree(test, "-"));
}
