// Copyright 2020 Egorov Danil

#ifndef MODULES_PRIORITY_QUEUE_INCLUDE_PRIORITY_QUEUE_H_
#define MODULES_PRIORITY_QUEUE_INCLUDE_PRIORITY_QUEUE_H_

#include <iostream>
#include <list>

class node {
 public:
    node();
    explicit node(int _key, int _data);
    int key;
    int data;
};

class priority_queue {
 private:
    std::list<node> queue;
    std::list<node>::iterator get_min_it();
    std::list<node>::iterator get_max_it();

 public:
    void insert(node _node);
    int* extract_minimum();
    int* extract_maximum();
    bool deleteMin();
    bool deleteMax();
    bool is_empty();
};

#endif  // MODULES_PRIORITY_QUEUE_INCLUDE_PRIORITY_QUEUE_H_
