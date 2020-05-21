// Copyright 2020 Guschin Alexander & Antipin Alexander

#ifndef MODULES_RADIX_SORT_INCLUDE_RADIX_SORT_H_
#define MODULES_RADIX_SORT_INCLUDE_RADIX_SORT_H_

#include <vector>

void FillRandom(std::vector<std::int32_t>* vector_ptr);
bool IsSorted(const std::vector<std::int32_t>& vector_ref);
void RadixSort(std::vector<std::int32_t>* vector);

class SortArray {
 public:
    SortArray() = default;
    explicit SortArray(const size_t size);
    SortArray(const SortArray& copy) = default;
    explicit SortArray(const std::vector<int32_t>& vec);
    ~SortArray() = default;
    int32_t operator[](const size_t n);
    size_t size();
    void changeElement(const size_t index, const int32_t element);
    void push(const int32_t elem);
    void pushVector(const std::vector<int32_t>& vector);
    void resize(const size_t newSize);
    void remove(const size_t index);
    size_t search(const int32_t elem);
    bool isEmpty() const;
    void operator()(std::vector<int32_t>* vector);
 private:
    std::vector<int32_t> data;
};

#endif  // MODULES_RADIX_SORT_INCLUDE_RADIX_SORT_H_
