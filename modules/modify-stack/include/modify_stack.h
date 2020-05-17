// Copyright 2020 Tanskii Yurii & Okmyanskiy Andrey

#ifndef MODULES_MODIFY_STACK_INCLUDE_MODIFY_STACK_H_
#define MODULES_MODIFY_STACK_INCLUDE_MODIFY_STACK_H_


class Stack {
 private:
    double* src;
    double* min_items;
    int size;
    int top;
    void init(const Stack&, bool equal);
 public:
    explicit Stack(int size = 50);
    Stack(const Stack& stack);
    ~Stack();
    int getSize() const;
    int getTop() const;
    bool isEmpty() const;
    bool isFull() const;
    void put(const double value);
    double getUpper() const;
    double pop();
    double getMin() const;
    void operator = (const Stack& stack);
    bool operator == (const Stack& stack) const;
    bool operator != (const Stack& stack) const;
};

#endif  // MODULES_MODIFY_STACK_INCLUDE_MODIFY_STACK_H_
