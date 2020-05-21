// Copyright 2020 Tanskii Yurii & Okmyanskiy Andrey

#include <gtest/gtest.h>

#include "include/modify_stack.h"

TEST(Stack, Can_Create_With_Positive_Size) {
    // Arrange
    int size = 25;

    // Act
    Stack s(size);

    // Assert
    EXPECT_EQ(size, s.getSize());
}

TEST(Stack, Can_Create_With_No_Size) {
    // Arrange
    int ex_size = 50;

    // Act
    Stack s;

    // Assert
    EXPECT_EQ(ex_size, s.getSize());
}

TEST(Stack, Can_Assert_With_Zero_Size) {
    // Arrange
    int size;

    // Act
    size = 0;

    // Assert
    ASSERT_ANY_THROW(Stack s(size));
}

TEST(Stack, Can_Assert_With_Negative_Size) {
    // Arrange
    int size;

    // Act
    size = -1;

    // Assert
    ASSERT_ANY_THROW(Stack s(size));
}

TEST(Stack, Can_Copy_Stack) {
    // Arrange
    int size = 10;
    double value = 0;
    Stack s1(size);

    // Act
    for (int i = 0; i < size; i++) {
        s1.put(static_cast<double>(value++));
    }
    Stack s2(s1);

    // Assert
    EXPECT_EQ(s1, s2);
}

TEST(Stack, Do_Not_Equal) {
    // Arrange
    int size = 10;
    double value = 0;
    Stack s1(size);
    Stack s2(size);

    // Act
    for (int i = 0; i < size; i++) {
        s1.put(static_cast<double>(value++));
        s2.put(static_cast<double>(value));
    }

    // Assert
    EXPECT_TRUE(s1 != s2);
}

TEST(Stack, Can_Assign) {
    // Arrange
    int size = 10;
    double value = 0;
    Stack s1(size);
    Stack s2(size);

    // Act
    for (int i = 0; i < size; i++) {
        s1.put(static_cast<double>(value++));
    }
    s2 = s1;

    // Assert
    EXPECT_TRUE(s1 == s2);
}

TEST(Stack, Can_Assign_with_different_size) {
    // Arrange
    int size1 = 10;
    int size2 = 11;
    double value = 0;
    Stack s1(size1);
    Stack s2(size2);

    // Act
    for (int i = 0; i < size1; i++) {
        s1.put(static_cast<double>(value++));
    }
    s2 = s1;

    // Assert
    EXPECT_TRUE(s1 == s2);
}

TEST(Stack, Do_Get_Min) {
    // Arrange
    int size = 10;
    double exp_min = 0;
    Stack s(size);

    // Act
    for (int i = 0; i < size; i++) {
        s.put(static_cast<double>(i));
    }

    // Assert
    EXPECT_EQ(exp_min, s.getMin());
}

TEST(Stack, Do_Get_Upper) {
    // Arrange
    int size = 10;
    Stack s(size);
    double exp_top = 9;

    // Act
    for (int i = 0; i < size; i++) {
        s.put(static_cast<double>(i));
    }

    // Assert
    EXPECT_EQ(exp_top, s.getUpper());
}

TEST(Stack, Do_Pop) {
    // Arrange
    int size = 10;
    double value = 5;
    Stack s(size);

    // Act
    s.put(static_cast<double>(value));

    // Assert
    EXPECT_EQ(value, s.pop());
}

TEST(Stack, Check_Is_Empty) {
    // Arrange
    int size = 10;
    bool expect = true;

    // Act
    Stack s;

    // Assert
    EXPECT_TRUE(s.isEmpty() == expect);
}

TEST(Stack, Check_Is_Full) {
    // Arrange
    int size = 10;
    bool expect = true;
    Stack s(size);

    // Act
    for (int i = 0; i < size; i++) {
        s.put(static_cast<double>(i));
    }

    // Assert
    EXPECT_TRUE(expect == s.isFull());
}

TEST(Stack, Do_Get_Top) {
    // Arrange
    int size = 10;
    Stack s(size);
    double ex_top = 10;

    // Act
    for (int i = 0; i < size; i++) {
        s.put(static_cast<double>(i));
    }

    // Assert
    EXPECT_EQ(ex_top, s.getTop());
}

TEST(Stack, Another_test_for_review) {
    // Arrange
    int size = 4;
    Stack s(size);
    double ex_min = 1;

    // Act
    for (int i = 0; i < size; i++) {
        s.put(static_cast<double>(i+1));
    }

    // Assert
    EXPECT_EQ(ex_min, s.getMin());
}

TEST(Stack, Another_min_test) {
    // Arrange
    int size = 4;
    Stack s(size);
    double ex_min = 1;

    // Act
    for (int i = 0; i < size; i++) {
        s.put(static_cast<double>(size-i));
    }

    // Assert
    EXPECT_EQ(ex_min, s.getMin());
}
