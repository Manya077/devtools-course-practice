// Copyright 2020 Guschin Alexander

#include <time.h>
#include <vector>
#include <random>
#include "include/radix_sort.h"

void FillRandom(std::vector<std::int32_t>* vector_ptr) {
  std::mt19937 gen(time(0));
  std::size_t size = vector_ptr->size();
  for (std::size_t i = 0; i < size; ++i) {
    std::int32_t tmp = static_cast<std::int32_t>(gen());
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

std::vector<std::int32_t> RadixSort(std::vector<std::int32_t> vector) {
  std::size_t size = vector.size();
  std::vector<std::int32_t> res_vector(size);
  std::uint8_t* ptr = reinterpret_cast<std::uint8_t*>(&vector[0]);

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
      res_vector[count[*(ptr + k + i * 4)]] = vector[i];
      count[*(ptr + k + i * 4)]++;
    }

    vector = res_vector;
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
    res_vector[(count[*(ptr + 3 + i * 4)] + shift) % size] = vector[i];
    count[*(ptr + 3 + i * 4)]++;
  }

  return res_vector;
}
