// Copyright 2020 Yasakova Anastasia & Sinitsina Maria

#include "include/trees.h"
#include <queue>

TreeNode::TreeNode(int data_, TreeNode* left_, TreeNode* right_,
    TreeNode* parent_) : data(data_), left(left_),
    right(right_), parent(parent_) {}

int TreeNode::GetData() const {
    return data;
}

TreeNode* TreeNode::GetLeft() const {
    return left;
}

TreeNode* TreeNode::GetRight() const {
    return right;
}

TreeNode* TreeNode::GetParent() const {
    return parent;
}

void TreeNode::SetLeft(TreeNode* tmp) {
    left = tmp;
}

void TreeNode::SetRight(TreeNode* tmp) {
    right = tmp;
}

void TreeNode::SetParent(TreeNode* tmp) {
    parent = tmp;
}


Tree::Tree(int data_) {
    root = new TreeNode(data_);
    amount = 1;
}

Tree::Tree(std::initializer_list<int> l) {
    root = nullptr;
    amount = 0;
    for (auto& val : l) {
        TreeNode* tmp = new TreeNode(val, nullptr, nullptr, nullptr);
        AddElem(tmp);
    }
}

Tree::Tree(const Tree& tree) {
    TreeNode* j = tree.root;
    root = new TreeNode(j->GetData(), nullptr, nullptr, nullptr);
    amount = 1;
    TreeNode* i = root;
    std::queue<TreeNode*> t1, t2;
    t1.push(i);
    t2.push(j);
    while (t1.empty() != true) {
        i = t1.front();
        t1.pop();
        j = t2.front();
        t2.pop();
        if (j->GetLeft() != nullptr) {
            TreeNode* tmp = new TreeNode((j->GetLeft())->GetData(),
                nullptr, nullptr, i);
            i->SetLeft(tmp);
            amount++;
            t1.push(tmp);
            t2.push(j->GetLeft());
        }
        if (j->GetRight() != nullptr) {
            TreeNode* tmp = new TreeNode((j->GetRight())->GetData(),
                nullptr, nullptr, i);
            i->SetRight(tmp);
            amount++;
            t1.push(tmp);
            t2.push(j->GetRight());
        }
    }
}

Tree::~Tree() {
    TreeNode* i = root;
    while (amount > 1) {
        while (true) {
            if (i->GetLeft() != nullptr)
                i = i->GetLeft();
            else if (i->GetRight() != nullptr)
                i = i->GetRight();
            else
                break;
        }
        TreeNode* j = i;
        i = j->GetParent();
        if (i->GetLeft() == j) {
            i->SetLeft(nullptr);
        } else {
            i->SetRight(nullptr);
        }
        delete j;
        amount--;
    }
    delete root;
}

bool Tree::operator==(const Tree& tree) {
    bool res = true;
    if (amount == tree.amount) {
        std::queue<TreeNode*> t1, t2;
        TreeNode* i = root;
        TreeNode* j = tree.root;
        t1.push(i);
        t2.push(j);
        while (t1.empty() != true) {
            i = t1.front();
            t1.pop();
            j = t2.front();
            t2.pop();
            if (i->GetData() != j->GetData()) {
                res = false;
                break;
            }
            if (i->GetLeft() != nullptr) {
                if (j->GetLeft() != nullptr) {
                    t1.push(i->GetLeft());
                    t2.push(j->GetLeft());
               } else {
                    res = false;
                    break;
                }
            }
            if (i->GetRight() != nullptr) {
                if (j->GetRight() != nullptr) {
                    t1.push(i->GetRight());
                    t2.push(j->GetRight());
                } else {
                    res = false;
                    break;
                }
            }
        }
    } else {
        res = false;
    }
    return res;
}

int Tree::GetDataRoot() const {
    return root->GetData();
}

int Tree::GetAmount() const {
    return amount;
}

void Tree::AddElem(int data_) {
    TreeNode* i = root;
    while (true) {
        if (data_ > i->GetData() && i->GetRight() != nullptr)
            i = i->GetRight();
        else if (data_ < i->GetData() && i->GetLeft() != nullptr)
            i = i->GetLeft();
        else
            break;
    }
    if (data_ > i->GetData()) {
        TreeNode* tmp = new TreeNode(data_, nullptr, nullptr, i);
        i->SetRight(tmp);
        amount++;
    } else if (data_ < i->GetData()) {
        TreeNode* tmp = new TreeNode(data_, nullptr, nullptr, i);
        i->SetLeft(tmp);
        amount++;
    } else {
        throw "Adding an existing element.";
    }
}

void Tree::AddElem(TreeNode* tmp) {
    if (amount == 0) {
        root = tmp;
        amount++;
    } else {
        TreeNode* i = root;
        while (true) {
            if (tmp->GetData() > i->GetData() && i->GetRight() != nullptr)
                i = i->GetRight();
            else if (tmp->GetData() < i->GetData() && i->GetLeft() != nullptr)
                i = i->GetLeft();
            else
                break;
        }
        if (tmp->GetData() > i->GetData()) {
            i->SetRight(tmp);
            tmp->SetParent(i);
            amount++;
        } else if (tmp->GetData() < i->GetData()) {
            i->SetLeft(tmp);
            tmp->SetParent(i);
            amount++;
        } else {
            throw "Adding an existing element.";
        }
    }
}

bool Tree::FindElemData(int data_) const {
    bool res = false;
    TreeNode* i = root;
    while (i != nullptr) {
        if (i->GetData() == data_) {
            res = true;
            break;
        } else if (data_ > i->GetData()) {
            i = i->GetRight();
        } else {
            i = i->GetLeft();
        }
    }
    return res;
}

TreeNode* Tree::FindElemNode(int data_) const {
    TreeNode* res = nullptr;
    TreeNode* i = root;
    while (i != nullptr) {
        if (i->GetData() == data_) {
            res = i;
            break;
        } else if (data_ > i->GetData()) {
            i = i->GetRight();
        } else {
            i = i->GetLeft();
        }
    }
    return res;
}

void Tree::DelElem(int data_) {
    TreeNode* i = FindElemNode(data_);
    if (i != nullptr) {
        if (i->GetLeft() == nullptr && i->GetRight() == nullptr) {
            TreeNode* tmp = i;
            i = i->GetParent();
            if (i->GetLeft() == tmp) {
                i->SetLeft(nullptr);
            } else {
                i->SetRight(nullptr);
            }
            delete tmp;
            amount--;
        } else if (i->GetLeft() == nullptr) {
            TreeNode* tmp1 = i;
            TreeNode* tmp2 = i->GetRight();
            i = i->GetParent();
            tmp2->SetParent(i);
            if (i->GetLeft() == tmp1) {
                i->SetLeft(tmp2);
            } else {
                i->SetRight(tmp2);
            }
            delete tmp1;
            amount--;
        } else if (i->GetRight() == nullptr) {
            TreeNode* tmp1 = i;
            TreeNode* tmp2 = i->GetLeft();
            i = i->GetParent();
            tmp2->SetParent(i);
            if (i->GetLeft() == tmp1) {
                i->SetLeft(tmp2);
            } else {
                i->SetRight(tmp2);
            }
            delete tmp1;
            amount--;
        } else {
            bool f = false;
            TreeNode* tmp1 = i;
            TreeNode* tmp2 = i;
            tmp2 = tmp2->GetLeft();
            while (tmp2->GetRight() != nullptr) {
                tmp2 = tmp2->GetRight();
                f = true;
            }
            if (f == true) {
                (tmp2->GetParent())->SetRight(tmp2->GetLeft());
            } else {
                (tmp2->GetParent())->SetLeft(tmp2->GetLeft());
            }
            if (tmp2->GetLeft() != nullptr) {
                (tmp2->GetLeft())->SetParent(tmp2->GetParent());
            }
            if (i != root) {
                i = i->GetParent();
                if (i->GetLeft() == tmp1) {
                    i->SetLeft(tmp2);
                } else {
                    i->SetRight(tmp2);
                }
                tmp2->SetParent(i);
            } else {
                tmp2->SetParent(nullptr);
                root = tmp2;
            }
            tmp2->SetRight(tmp1->GetRight());
            tmp2->SetLeft(tmp1->GetLeft());
            (tmp1->GetRight())->SetParent(tmp2);
            (tmp1->GetLeft())->SetParent(tmp2);
            delete tmp1;
            amount--;
        }
    }
}
