// Copyright 2020 Pauzin Leonid

#include <stdexcept>
#include <vector>
#include <string>
#include <sstream>
#include "include/avl_actions.h"

Operation* Operation::makeOperation(std::string op) {
    Operation* res = nullptr;
    if (op == "insert") {
        res = new InsertOperation;
    }
    if (op == "remove") {
        res = new RemoveOperation;
    }
    if (res == nullptr)
        throw std::invalid_argument("Bad arguments!");
    return res;
}


std::string InsertOperation::operator()(AVL_Tree* tree,
    const std::vector<int>& arg) {
    tree->Insert(arg[0]);
    return "";
}

std::string RemoveOperation::operator()(AVL_Tree* tree,
  const std::vector<int>& arg) {
  std::string res;
  try {
    tree->Remove(arg[0]);
    res = "";
  }
  catch (std::exception& ex) {
    res = "(" + std::string(ex.what()) + ")";
  }
  return res;
}

