// Copyright 2020 Okmyanskiy Andrey & Tanskii Yurii

#include "include/stack.h"

Stack::Stack(int size) {
    if (size <= 0) {
        throw "The size must be greater than zero";
    } else {
        this->size = size;
    }
    mas = new double[this->size];
    top = 0;
}

void Stack::init(const Stack& stack, bool equal) {
    this->size = stack.size;
    if (!equal) {
        this->mas = new double[size];
    }
    this->top = stack.top;
    for (int i = 0; i < top; i++) {
        this->mas[i] = stack.mas[i];
    }
}

Stack::Stack(const Stack& stack) {
    init(stack, false);
}

Stack::~Stack() {
    delete[] mas;
}

int Stack::getSize() const {
    return size;
}

int Stack::getTop() const {
    return top;
}

bool Stack::isEmpty() const {
    return (top == 0);
}

bool Stack::isFull() const {
    return (top == size);
}

void Stack::put(const double value) {
    mas[top++] = value;
}

double Stack::get() {
    top--;
    return mas[top];
}

void Stack::operator = (const Stack& stack) {
    if (*this != stack) {
        bool equal = false;
        if (this->size != stack.size) {
            delete[] this->mas;
        } else {
            equal = true;
        }
        init(stack, equal);
    }
}

bool Stack::operator == (const Stack& stack) const {
    bool check = false;
    if (size == stack.size) {
        if (top == stack.top) {
            check = true;
            for (int i = 0; i < size; i++) {
                if (mas[i] != stack.mas[i]) {
                    check = false;
                    break;
                }
            }
        }
    }
    return check;
}

bool Stack::operator != (const Stack& stack) const {
    return !(*this == stack);
}
