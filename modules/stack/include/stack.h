// Copyright 2020 Okmyanskiy Andrey & Tanskii Yurii

#ifndef MODULES_STACK_INCLUDE_STACK_H_
#define MODULES_STACK_INCLUDE_STACK_H_

const int sizeDefault = 25;

class Stack {
 private:
    double *mas;
    int size;
    int top;
    void init(const Stack& stack, bool equal);
 public:
    explicit Stack(int size = sizeDefault);
    Stack(const Stack& stack);
    ~Stack();
    int getSize() const;
    int getTop() const;
    bool isEmpty() const;
    bool isFull() const;
    void put(const double value);
    double get();

    void operator = (const Stack& stack);
    bool operator == (const Stack& stack) const;
    bool operator != (const Stack& stack) const;
};

#endif  // MODULES_STACK_INCLUDE_STACK_H_
