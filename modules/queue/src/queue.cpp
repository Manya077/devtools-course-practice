// Copyright 2020 Sinitsina Maria & Yasakova Anastasia

#include <string>
#include "include/queue.h"

Queue::Queue(int s) {
    if (s < 0)
        throw std::string("Queue size < 0");
    tail_ = -1;
    head_ = -1;
    pq_.resize(s);
    size_ = s;
    count_ = 0;
}

Queue::Queue(const Queue &q) {
    tail_ = q.tail_;
    head_ = q.head_;
    size_ = q.size_;
    count_ = q.count_;
    pq_ = q.pq_;
}

bool Queue::IsEmpty() const {
    if (count_ == 0)
        return true;
    return false;
}

bool Queue::IsFull() const {
    if (count_ == size_)
        return true;
    return false;
}

void Queue::Put(int val) {
    if (IsFull())
        throw std::string("No space");
    tail_ = GetNextIndex(tail_);
    pq_.at(tail_) = val;
    count_++;
}

int Queue::Get() {
    if (IsEmpty())
        throw std::string("Queue is empty");
    head_ = GetNextIndex(head_);
    count_--;
    return pq_[head_];
}

int Queue::TopElem() const {
    if (count_ == 0)
        throw std::string("Queue is empty");
    int tempInd = GetNextIndex(head_);
    return pq_[tempInd];
}

int Queue::GetCount() const {
    return count_;
}

int Queue::GetNextIndex(int index) const {
    if (index == size_ - 1)
        return 0;
    return ++index;
}
