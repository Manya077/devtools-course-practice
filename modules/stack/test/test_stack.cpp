// Copyright 2020 Okmyanskiy Andrey & Tanskii Yurii

#include <gtest/gtest.h>

#include "include/stack.h"

TEST(Stack, wrongSizeInConstructor) {
    // Arrange
    int size;

    // Act
    size = -5;

    // Assert
    EXPECT_ANY_THROW(Stack stack(size));
}

TEST(Stack, getSizeWorks) {
    // Arrange
    int size = 10;

    // Act
    Stack stack(size);

    // Assert
    EXPECT_EQ(size, stack.getSize());
}

TEST(Stack, getTopWorks) {
    // Arrange
    int size = 10;
    int top = 5;
    Stack stack(size);

    // Act
    for (int i = 0; i < top; i++) {
        stack.put(i);
    }

    // Assert
    EXPECT_EQ(top, stack.getTop());
}

TEST(Stack, copyConstructorWorks) {
    // Arrange
    int size = 10;
    Stack stack(size);

    // Act
    for (int i = 0; i < stack.getSize(); i++) {
        stack.put(static_cast<double>(i));
    }
    Stack stack2(stack);

    // Assert
    EXPECT_EQ(stack, stack2);
}

TEST(Stack, equalOperatorWorks) {
    // Arrange
    int size = 10;
    Stack stack(size);
    Stack stack2;

    // Act
    for (int i = 0; i < stack.getSize(); i++) {
        stack.put(static_cast<double>(i));
    }
    stack2 = stack;

    // Assert
    EXPECT_EQ(stack, stack2);
}

TEST(Stack, comparisonOperatorWorks) {
    // Arrange
    int size = 10;
    Stack stack(size);

    // Act
    for (int i = 0; i < stack.getSize(); i++) {
        stack.put(static_cast<double>(i));
    }
    Stack stack2(stack);

    // Assert
    EXPECT_EQ(true, stack == stack2);
}

TEST(Stack, notEqualComparisonOperatorWorks) {
    // Arrange
    int size = 10;
    Stack stack2(size);
    Stack stack(size);

    // Act
    for (int i = 0; i < stack.getSize(); i++) {
        stack.put(static_cast<double>(i));
    }
    for (int i = 0; i < stack2.getSize(); i++) {
        stack2.put(static_cast<double>(i+1));
    }

    // Assert
    EXPECT_EQ(true, stack != stack2);
}

TEST(Stack, stackIsEmpty) {
    // Arrange
    int size = 10;

    // Act
    Stack stack(size);

    // Assert
    EXPECT_EQ(true, stack.isEmpty());
}

TEST(Stack, stackIsNotEmpty) {
    // Arrange
    int size = 10;
    Stack stack(size);

    // Act
    for (int i = 0; i < stack.getSize()/2; i++) {
        stack.put(static_cast<double>(i));
    }

    // Assert
    EXPECT_EQ(true, !stack.isEmpty());
}

TEST(Stack, stackIsFull) {
    // Arrange
    int size = 10;
    Stack stack(size);

    // Act
    for (int i = 0; i < stack.getSize(); i++) {
        stack.put(static_cast<double>(i));
    }

    // Assert
    EXPECT_EQ(true, stack.isFull());
}

TEST(Stack, stackIsNotFull) {
    // Arrange
    int size = 10;
    Stack stack(size);

    // Act
    for (int i = 0; i < stack.getSize()/2; i++) {
        stack.put(static_cast<double>(i));
    }

    // Assert
    EXPECT_EQ(true, !stack.isFull());
}

TEST(Stack, getAndPutWorks) {
    // Arrange
    int size = 1;
    double value = 14;
    Stack stack(size);

    // Act
    stack.put(value);

    // Assert
    EXPECT_EQ(value, stack.get());
}
