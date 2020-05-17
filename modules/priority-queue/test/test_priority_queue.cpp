// Copyright 2020 Egorov Danil

#include <gtest/gtest.h>

#include "include/priority_queue.h"

class PriorityQueueTest : public ::testing::Test {};

TEST_F(PriorityQueueTest, CanCreateDefaultNode) {
    // Act
    node n;

    // Assert
    EXPECT_EQ(0, n.key);
    EXPECT_EQ(0, n.data);
}

TEST_F(PriorityQueueTest, CanInsertNode) {
    // Arrange
    priority_queue pq;
    node n(1, 1342334);
    int* p_n;

    // Act
    pq.insert(n);
    p_n = pq.extract_minimum();

    // Assert
    EXPECT_EQ(n.data, *p_n);
}

TEST_F(PriorityQueueTest, CheckEmptyReturnTrueIfEmpty) {
    // Arrange
    priority_queue pq;

    // Act
    bool res = pq.is_empty();

    // Assert
    EXPECT_TRUE(res);
}

TEST_F(PriorityQueueTest, CheckEmptyReturnFalseIfEmpty) {
    // Arrange
    priority_queue pq;
    node n(1, 2);

    // Act
    pq.insert(n);
    bool res = pq.is_empty();

    // Assert
    EXPECT_FALSE(res);
}

TEST_F(PriorityQueueTest, CanExtractMinimum) {
    // Arrange
    priority_queue pq;
    node n1(4, 4);
    node n2(1, 1);
    node n3(3, 3);
    int* p_n;

    // Act
    pq.insert(n1);
    pq.insert(n2);
    pq.insert(n3);
    p_n = pq.extract_minimum();

    // Assert
    EXPECT_EQ(n2.data, *p_n);
}

TEST_F(PriorityQueueTest, CanExtractMaximum) {
    // Arrange
    priority_queue pq;
    node n1(2, 2);
    node n2(4, 4);
    node n3(3, 3);
    int* p_n;

    // Act
    pq.insert(n1);
    pq.insert(n2);
    pq.insert(n3);
    p_n = pq.extract_maximum();

    // Assert
    EXPECT_EQ(n2.data, *p_n);
}

TEST_F(PriorityQueueTest, CanDeleteMinimum) {
    // Arrange
    priority_queue pq;
    node n1(4, 4);
    node n2(3, 3);
    int* p_n;

    // Act
    pq.insert(n1);
    pq.insert(n2);
    bool res = pq.deleteMin();
    p_n = pq.extract_minimum();

    // Assert
    EXPECT_TRUE(res);
    EXPECT_EQ(n1.data, *p_n);
}

TEST_F(PriorityQueueTest, CanDeleteMaximum) {
    // Arrange
    priority_queue pq;
    node n1(4, 4);
    node n2(3, 3);
    int* p_n;

    // Act
    pq.insert(n1);
    pq.insert(n2);
    bool res = pq.deleteMax();
    p_n = pq.extract_maximum();

    // Assert
    EXPECT_TRUE(res);
    EXPECT_EQ(n2.data, *p_n);
}

TEST_F(PriorityQueueTest, ReturnNullptrWhileExtractMinFromEmpty) {
    // Arrange
    priority_queue pq;
    int* p_n;

    // Act
    p_n = pq.extract_minimum();

    // Assert
    EXPECT_EQ(nullptr, p_n);

    delete p_n;
}

TEST_F(PriorityQueueTest, ReturnNullptrWhileExtractMaxFromEmpty) {
    // Arrange
    priority_queue pq;
    int* p_n;

    // Act
    p_n = pq.extract_maximum();

    // Assert
    EXPECT_EQ(nullptr, p_n);
}

TEST_F(PriorityQueueTest, ReturnFalseWhileDeleteMinFromEmpty) {
    // Arrange
    priority_queue pq;

    // Act
    bool res = pq.deleteMin();

    // Assert
    EXPECT_FALSE(res);
}

TEST_F(PriorityQueueTest, ReturnFalseWhileDeleteMaxFromEmpty) {
    // Arrange
    priority_queue pq;

    // Act
    bool res = pq.deleteMax();

    // Assert
    EXPECT_FALSE(res);
}
