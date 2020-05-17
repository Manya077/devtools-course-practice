// Copyright 2020 Sinitsina Maria

#include <gtest/gtest.h>

#include "include/queue.h"

TEST(Queue, Can_Create_Queue_With_Positive_Length) {
    // Arrange & Act & Assert
    EXPECT_NO_THROW(Queue q(5));
}

TEST(Queue, Can_Copy_Queue) {
    // Arrange
    Queue q1(5);
    // Act & Assert
    EXPECT_NO_THROW(Queue q2(q1));
}

TEST(Queue, Cant_Create_Queue_With_Negative_Length) {
    // Arrange & Act & Assert
    EXPECT_ANY_THROW(Queue q(-5));
}

TEST(Queue, Can_Put_Element) {
    // Arrange
    Queue q(5);

    // Act & Assert
    EXPECT_NO_THROW(q.Put(1));
}

TEST(Queue, Queue_Is_Empty) {
    // Arrange
    Queue q(5);

    // Act & Assert
    ASSERT_TRUE(q.IsEmpty());
}

TEST(Queue, Queue_Is_Full) {
    // Arrange
    Queue q(2);
    q.Put(1);
    q.Put(1);

    // Act & Assert
    ASSERT_TRUE(q.IsFull());
}

TEST(Queue, Cant_Put_Element_In_Full) {
    // Arrange
    Queue q(3);
    q.Put(1);
    q.Put(2);
    q.Put(3);

    // Act & Assert
    EXPECT_ANY_THROW(q.Put(4));
}

TEST(Queue, Can_Get_Element) {
    // Arrange
    Queue q(5);
    q.Put(1);

    // Act & Assert
    EXPECT_NO_THROW(q.Get());
}

TEST(Queue, Cant_Get_Element_In_Empty) {
    // Arrange
    Queue q(3);

    // Act & Assert
    EXPECT_ANY_THROW(q.Get());
}

TEST(Queue, Get_Element_Is_Correct) {
    // Arrange
    Queue q(3);
    q.Put(1);
    q.Put(2);
    q.Put(3);
    q.Get();
    q.Put(4);

    // Act & Assert
    EXPECT_EQ(2, q.Get());
}


TEST(Queue, Top_Element_Is_Different_After_Get) {
    // Arrange
    Queue q(5);
    q.Put(1);
    q.Put(2);
    q.Get();

    // Act & Assert
    EXPECT_EQ(2, q.TopElem());
}

TEST(Queue, Top_Elem_Function_Doesnt_Delete_Top_Element) {
    // Arrange
    Queue q(3);
    q.Put(2);
    q.Put(3);
    q.TopElem();

    // Act & Assert
    EXPECT_EQ(2, q.TopElem());
}

TEST(Queue, Cant_Call_Top_Elem_In_Empty_Queue) {
    // Arrange
    Queue q(3);

    // Act & Assert
    EXPECT_ANY_THROW(q.TopElem());
}

TEST(Queue, Get_Count_Is_Correct) {
    // Arrange
    Queue q(3);
    q.Put(1);
    q.Put(2);

    // Act & Assert
    EXPECT_EQ(2, q.GetCount());
}
