// Copyright 2020 Tanskii Yurii & Okmyanskiy Andrey

#include "include/modify_stack.h"

Stack::Stack(int size) {
    if (size <= 0) {
        throw "Size must be above zero";
    } else {
        this->size = size;
    }
    src = new double[this->size];
    min_items = new double[this->size];
    top = 0;
}

void Stack::init(const Stack& stack, bool equal) {
    this->size = stack.size;
    if (!equal) {
        this->src = new double[size];
        this->min_items = new double[size];
    }
    this->top = stack.top;
    for (int i = 0; i < top; i++) {
        this->src[i] = stack.src[i];
        this->min_items[i] = stack.min_items[i];
    }
}

Stack::Stack(const Stack& stack) {
    init(stack, false);
}

Stack::~Stack() {
    delete[] src;
    delete[] min_items;
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

void Stack::put(const double elem) {
    src[top] = elem;
    int tmp = top;
    tmp--;
    if (tmp >= 0) {
        if (min_items[tmp] > elem)
            min_items[top] = elem;
        else
            min_items[top] = min_items[tmp];
    } else {
        min_items[top] = elem;
    }
    top++;
}

double Stack::pop() {
    top--;
    return src[top];
}

double Stack::getUpper() const {
    return src[top-1];
}

double Stack::getMin() const {
    return min_items[top-1];
}

void Stack::operator = (const Stack& stack) {
    if (*this != stack) {
        bool equal = false;
        if (this->size != stack.size) {
            delete[] this->src;
            delete[] this->min_items;
        } else {
            equal = true;
        }
        init(stack, equal);
    }
}

bool Stack::operator == (const Stack& stack) const {
    bool equal = false;
    if (this->size == stack.size) {
        if (this->top == stack.top) {
            equal = true;
            for (int i = 0; i < size; i++) {
                if (this->src[i] != stack.src[i]) {
                    equal = false;
                    break;
                }
            }
        }
    }
    return equal;
}

bool Stack::operator != (const Stack& stack) const {
    return !(*this == stack);
}
