// Copyright 2020 Kudryashov Nikita

#include <gtest/gtest.h>
#include <vector>
#include "include/bitfield.h"

TEST(Kudryashov_Nikita_BitfieldTest, Can_Create_Bitfield_Without_Arguments) {
    // Arrange & Act & Assert
    EXPECT_NO_THROW(Bitfield a);
}

TEST(Kudryashov_Nikita_BitfieldTest, Can_Create_Bitfield_With_Arguments) {
    // Arrange
    unsigned int size = 10;

    // Act & Assert
    EXPECT_NO_THROW(Bitfield a(size));
}

TEST(Kudryashov_Nikita_BitfieldTest, Can_Set_Position) {
    // Arrange
    unsigned int size = 10;
    Bitfield a(size);

    // Act & Assert
    EXPECT_NO_THROW(a.set(0));
}

TEST(Kudryashov_Nikita_BitfieldTest, Throw_Set_Out_of_Bounds) {
    // Arrange
    unsigned int size = 10;
    unsigned int out_of_bounds = 11;
    Bitfield a(size);

    // Act & Assert
    EXPECT_ANY_THROW(a.set(out_of_bounds));
}

TEST(Kudryashov_Nikita_BitfieldTest, Set_Test) {
    // Arrange
    unsigned int size = 100;
    bool check = true;
    Bitfield a(size);

    // Act
    a.set(91);
    a.set(11);
    a.set(0);

    if (a.get(91) != 1) {
        check = false;
    }

    if (a.get(11) != 1) {
        check = false;
    }

    if (a.get(0) != 1) {
        check = false;
    }

    // Assert
    EXPECT_EQ(true, check);
}

TEST(Kudryashov_Nikita_BitfieldTest, Set_Stay_One_At_Its_Place) {
    // Arrange
    unsigned int size = 10;
    unsigned int expected_value = 1;
    Bitfield a(size);
    a.set(1);

    // Act
    a.set(1);

    // Assert
    EXPECT_EQ(expected_value, a.get(1));
}

TEST(Kudryashov_Nikita_BitfieldTest, Can_Unset_Position) {
    // Arrange
    unsigned int size = 10;
    Bitfield a(size);

    // Act & Assert
    EXPECT_NO_THROW(a.unset(3));
}

TEST(Kudryashov_Nikita_BitfieldTest, Throw_Unset_Out_of_Bounds) {
    // Arrange
    unsigned int size = 10;
    unsigned int out_of_bounds = 12;
    Bitfield a(size);

    // Act & Assert
    EXPECT_ANY_THROW(a.unset(out_of_bounds));
}

TEST(Kudryashov_Nikita_BitfieldTest, Unset_Test) {
    // Arrange
    unsigned int size = 100;
    bool check = true;
    Bitfield a(size);
    a.set(0);
    a.set(1);
    a.set(2);

    // Act
    a.unset(1);
    a.unset(2);

    if (a.get(0) != 1) {
        check = false;
    }

    if (a.get(1) != 0) {
        check = false;
    }

    if (a.get(2) != 0) {
        check = false;
    }

    // Assert
    EXPECT_EQ(true, check);
}

TEST(Kudryashov_Nikita_BitfieldTest, Unset_Stay_Zero_At_Its_Place) {
    // Arrange
    unsigned int size = 10;
    unsigned int expected_value = 0;
    Bitfield a(size);
    a.set(1);
    a.unset(1);

    // Act
    a.unset(1);

    // Assert
    EXPECT_EQ(expected_value, a.get(1));
}

TEST(Kudryashov_Nikita_BitfieldTest, Throw_Get_Out_of_Bounds) {
    // Arrange
    unsigned int size = 10;
    unsigned int out_of_bounds = 12;
    Bitfield a(size);

    // Act & Assert
    EXPECT_ANY_THROW(a.get(out_of_bounds));
}

TEST(Kudryashov_Nikita_BitfieldTest, Can_Get_Size) {
    // Arrange
    unsigned int size = 10;
    unsigned int expected_value = 10;
    Bitfield a(size);

    // Act & Assert
    EXPECT_EQ(expected_value, a.get_size());
}

TEST(Kudryashov_Nikita_BitfieldTest, Can_Get_Position_Value) {
    // Arrange
    unsigned int size = 10;
    Bitfield a(size);

    // Act & Assert
    EXPECT_NO_THROW(a.get(0));
}

TEST(Kudryashov_Nikita_BitfieldTest, Get_Returns_Right_Value) {
    // Arrange
    unsigned int size = 10;
    int expected_value = 1;
    Bitfield a(size);
    a.set(5);

    // Act & Assert
    EXPECT_EQ(expected_value, a.get(5));
}

TEST(Kudryashov_Nikita_BitfieldTest, Get_Returns_Only_One_Or_Zero) {
    // Arrange
    bool check = true;
    unsigned int size = 16;
    Bitfield a(size);
    a.set(1);
    a.set(5);
    a.set(7);

    // Act
    for (unsigned int i = 0; i < a.get_size(); ++i) {
        if (a.get(i) != 1 && a.get(i) != 0) {
            check = false;
            break;
        }
    }

    // Assert
    EXPECT_EQ(true, check);
}

TEST(Kudryashov_Nikita_BitfieldTest, Bitfield_Creates_Empty) {
    // Arrange
    bool check = true;
    unsigned int size = 50;
    Bitfield a(size);

    // Act
    for (unsigned int i = 0; i < a.get_size(); ++i) {
        if (a.get(i) != 0) {
            check = false;
            break;
        }
    }

    // Assert
    EXPECT_EQ(true, check);
}

TEST(Kudryashov_Nikita_BitfieldTest, Fill_Test) {
    // Arrange
    bool check = true;
    unsigned int size = 50;
    Bitfield a(size);

    // Act
    a.fill();

    // Like this (**)
    for (unsigned int i = 0; i < a.get_size(); ++i) {
        if (a.get(i) != 1) {
            check = false;
            break;
        }
    }

    // Assert
    EXPECT_EQ(true, check);
}

TEST(Kudryashov_Nikita_BitfieldTest, Clear_Test) {
    // Arrange
    bool check = true;
    unsigned int size = 50;
    Bitfield a(size);
    a.set(45);
    a.set(32);
    a.set(9);

    // Act
    a.clear();

    for (unsigned int i = 0; i < a.get_size(); ++i) {
        if (a.get(i) != 0) {
            check = false;
            break;
        }
    }

    // Assert
    EXPECT_EQ(true, check);
}

TEST(Kudryashov_Nikita_BitfieldTest, Set_Vector_Arguments) {
    // Arrange
    bool check = true;
    unsigned int size = 50;
    std::vector<unsigned int> temp = {4, 0, 1};
    Bitfield a(size);

    // Act
    a.set(temp);

    if (a.get(0) != 1) {
        check = false;
    }

    if (a.get(1) != 1) {
        check = false;
    }

    if (a.get(4) != 1) {
        check = false;
    }

    // Assert
    EXPECT_EQ(true, check);
}

TEST(Kudryashov_Nikita_BitfieldTest, Set_With_Empty_Vector) {
    // Arrange
    unsigned int size = 50;
    Bitfield a(size);
    std::vector<unsigned int> temp;

    // Act & Assert
    EXPECT_NO_THROW(a.set(temp));
}

TEST(Kudryashov_Nikita_BitfieldTest, Vector_Set_Throw_Out_Of_Bounds) {
    // Arrange
    unsigned int size = 50;
    Bitfield a(size);
    std::vector<unsigned int> temp = {0, 51};

    // Act & Assert
    EXPECT_ANY_THROW(a.set(temp));
}

TEST(Kudryashov_Nikita_BitfieldTest, Unset_Vector_Arguments) {
    // Arrange
    bool check = true;
    unsigned int size = 50;
    std::vector<unsigned int> temp = {4, 0, 1};
    Bitfield a(size);
    a.fill();

    // Act
    a.unset(temp);

    if (a.get(0) != 0) {
        check = false;
    }

    if (a.get(1) != 0) {
        check = false;
    }

    if (a.get(4) != 0) {
        check = false;
    }

    // Assert
    EXPECT_EQ(true, check);
}

TEST(Kudryashov_Nikita_BitfieldTest, Unset_With_Empty_Vector) {
    // Arrange
    unsigned int size = 50;
    Bitfield a(size);
    a.set(12);
    std::vector<unsigned int> temp;

    // Act & Assert
    EXPECT_NO_THROW(a.unset(temp));
}

TEST(Kudryashov_Nikita_BitfieldTest, Vector_Unset_Throw_Out_Of_Bounds) {
    // Arrange
    unsigned int size = 50;
    Bitfield a(size);
    a.set(0);
    std::vector<unsigned int> temp = {0, 51};

    // Act & Assert
    EXPECT_ANY_THROW(a.unset(temp));
}

TEST(Kudryashov_Nikita_BitfieldTest, Can_Copy_Bitfield) {
    // Arrange
    unsigned int size = 12;
    Bitfield a(size);
    Bitfield b;

    // Act & Assert
    EXPECT_NO_THROW(b = a);
}

TEST(Kudryashov_Nikita_BitfieldTest, Can_Copy_Object_Itself) {
    // Arrange
    bool check = true;
    unsigned int size = 12;
    Bitfield a(size);
    Bitfield b;
    b = a;

    // Act
    a = a;

    for (unsigned int i = 0; i < a.get_size(); ++i) {
        if (b.get(i) != a.get(i)) {
            check = false;
        }
    }

    // Assert
    EXPECT_EQ(true, check);
}

TEST(Kudryashov_Nikita_BitfieldTest, Copy_Constructor_Test) {
    // Arrange
    bool check = true;
    unsigned int size = 50;
    Bitfield a(size);
    Bitfield b;
    a.fill();

    // Act
    b = a;

    for (unsigned int i = 0; i < b.get_size(); ++i) {
        if (b.get(i) != a.get(i)) {
            check = false;
        }
    }

    // Assert
    EXPECT_EQ(true, check);
}

TEST(Kudryashov_Nikita_BitfieldTest, Equality_Operator_Test) {
    // Arrange
    unsigned int size = 50;
    Bitfield a(size);
    Bitfield b(size);
    a.fill();
    b.fill();

    // Act & Assert
    EXPECT_EQ(true, a == b);
}

TEST(Kudryashov_Nikita_BitfieldTest, Unequality_Operator_Test) {
    // Arrange
    unsigned int size = 50;
    Bitfield a(size);
    Bitfield b(size);
    a.fill();
    b.clear();

    // Act & Assert
    EXPECT_EQ(true, a != b);
}

TEST(Kudryashov_Nikita_BitfieldTest, Bitfields_Of_Unequal_Size_Are_Unequal) {
    // Arrange
    unsigned int size = 50;
    Bitfield a(size);
    Bitfield b(size - 1);
    a.fill();
    b.fill();

    // Act & Assert
    EXPECT_EQ(true, a != b);
}

TEST(Kudryashov_Nikita_BitfieldTest, Can_Use_Index_Value_Operator_Test) {
    // Arrange
    unsigned int size = 50;
    unsigned int pos = 0;
    Bitfield a(size);

    // Act & Assert
    EXPECT_NO_THROW(a[pos]);
}

TEST(Kudryashov_Nikita_BitfieldTest, Index_Value_Operator_Throw_Out_Of_Bounds) {
    // Arrange
    unsigned int size = 50;
    unsigned int pos = 50;
    Bitfield a(size);

    // Act & Assert
    EXPECT_ANY_THROW(a[pos]);
}

TEST(Kudryashov_Nikita_BitfieldTest, Equality_Operator_Sets_Size) {
    // Arrange
    unsigned int size = 5;
    Bitfield a(size), b;

    // Act
    b = a;

    // Assert
    EXPECT_EQ(size, b.get_size());
}
