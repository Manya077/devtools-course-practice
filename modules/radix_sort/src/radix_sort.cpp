// Copyright 2020 Guschin Alexander & Antipin Alexander

#include <time.h>
#include <vector>
#include <random>
#include <algorithm>
#include "../include/radix_sort.h"

void FillRandom(std::vector<std::int32_t>* vector_ptr) {
  std::mt19937 gen(static_cast<uint32_t>(time(0)));
  std::size_t size = vector_ptr->size();
  for (std::size_t i = 0; i < size; ++i) {
    std::int32_t tmp = static_cast<std::int32_t>(gen() % 1000);
    if (tmp == 0) ++tmp;
    (*vector_ptr)[i] = tmp;
  }
}

bool IsSorted(const std::vector<std::int32_t>& vector_ref) {
  std::size_t size = vector_ref.size();
  for (std::size_t i = 1; i < size; ++i)
    if (vector_ref[i] < vector_ref[i - 1]) return false;

  return true;
}

void RadixSort(std::vector<std::int32_t>* vector) {
  std::size_t size = vector->size();
  std::vector<std::int32_t> res_vector(size);
  std::uint8_t* ptr = reinterpret_cast<std::uint8_t*>(&(*vector)[0]);

  for (std::int32_t k = 0; k < 3; ++k) {
    std::int32_t count[256] = {0};
    for (std::size_t i = 0; i < size; ++i) count[*(ptr + k + i * 4)]++;

    std::int32_t sum = 0;
    for (std::int32_t i = 0; i < 256; ++i) {
      std::int32_t tmp = count[i];
      count[i] = sum;
      sum += tmp;
    }

    for (std::size_t i = 0; i < size; ++i) {
      res_vector[count[*(ptr + k + i * 4)]] = (*vector)[i];
      count[*(ptr + k + i * 4)]++;
    }

    *vector = res_vector;
  }

  std::int32_t count[256] = {0};
  for (std::size_t i = 0; i < size; ++i) count[*(ptr + 3 + i * 4)]++;

  std::int32_t shift = 0;
  for (std::int32_t i = 128; i < 256; ++i) shift += count[i];

  std::int32_t sum = 0;
  for (std::int32_t i = 0; i < 256; ++i) {
    std::int32_t tmp = count[i];
    count[i] = sum;
    sum += tmp;
  }

  for (std::size_t i = 0; i < size; ++i) {
    res_vector[(count[*(ptr + 3 + i * 4)] + shift) % size] = (*vector)[i];
    count[*(ptr + 3 + i * 4)]++;
  }

  *vector = res_vector;
}


SortArray::SortArray(const size_t size) : data(size) {}

SortArray::SortArray(const std::vector<int32_t>& vec) : data(vec) {
    RadixSort(&data);
}

int32_t SortArray::operator[](const size_t n) {
    return data[n];
}

size_t SortArray::size() {
    return data.size();
}

void SortArray::changeElement(const size_t index, const int32_t element) {
    size_t place = data.size() - 1;
    for (size_t i = 0; i < data.size() - 1; ++i)
        if (data[i + 1] >= element) {
            place = i;
            break;
        }

    if (place == index) {
        data[index] = element;
        return;
    } else if (place > index) {
        for (size_t i = index; i < place; ++i)
            data[i] = data[i + 1];
        data[place] = element;
    } else {
        data[place] = element;
        for (size_t i = place + 1; i < index + 1; ++i)
            data[i] = data[i + 1];
    }
}

void SortArray::push(const int32_t elem) {
    data.push_back(elem);
    RadixSort(&data);
}

void SortArray::pushVector(const std::vector<int32_t>& vector) {
    std::vector<int32_t> copy1(data);
    std::vector<int32_t> copy2(vector);
    RadixSort(&copy2);
    size_t newSize = data.size() + copy2.size();
    data.resize(newSize);

    size_t iter1 = 0, iter2 = 0;
    for (size_t i = 0; i < newSize; ++i) {
        if (iter1 == copy1.size()) {
            for (size_t j = i; j < newSize; ++j)
                data[j] = copy2[iter2++];
            break;
        }
        if (iter2 == copy2.size()) {
            for (size_t j = i; j < newSize; ++j)
                data[j] = copy1[iter1++];
            break;
        }
        if (copy1[iter1] < copy2[iter2])
            data[i] = copy1[iter1++];
        else
            data[i] = copy2[iter2++];
    }
}

void SortArray::resize(const size_t newSize) {
    data.resize(newSize);
}

void SortArray::remove(const size_t index) {
    data.erase(data.begin() + index);
}

size_t SortArray::search(const int32_t elem) {
    size_t left = 0, right = data.size() - 1;
    while (left <= right) {
        size_t rl = (right + left) / 2;
        if (elem == data[rl]) {
            return rl;
        } else if (elem < data[rl]) {
            right = rl;
        } else {
            left = rl == left ? rl + 1 : rl;
        }
    }
    return -1;
}

void SortArray::operator()(std::vector<int32_t>* vector) {
    RadixSort(vector);
}

bool SortArray::isEmpty() const {
    return data.empty();
}
