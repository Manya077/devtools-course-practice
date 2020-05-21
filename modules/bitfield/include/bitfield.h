// Copyright 2020 Kudryashov Nikita

#ifndef MODULES_BITFIELD_INCLUDE_BITFIELD_H_
#define MODULES_BITFIELD_INCLUDE_BITFIELD_H_

#include <vector>

class Bitfield {
 private:
  // Holds the set of bits counted from 0 to (size - 1) from left to right.
  std::vector<unsigned char> bitfield;

  unsigned int bitfield_size;

 public:
  explicit Bitfield(unsigned int size = 0);

  // Set specified position in Bitfield object to 1.
  void set(unsigned int position);

  // Set specified positions from arr_of_positions in Bitfield object to 1.
  void set(const std::vector<unsigned int>& arr_of_positions);

  // Unset specified position in Bitfield object to 0.
  void unset(unsigned int position);

  // Unset specified positions from arr_of_positions in Bitfield object to 0.
  void unset(const std::vector<unsigned int>& arr_of_positions);

  // Return the value of specified position in Bitfield object.
  int get(unsigned int position) const;

  // Return the size of Bitfield object.
  unsigned int get_size() const;

  // Set value to 1 in all positions of Bitfield object.
  void fill();

  // Set value to 0 in all positions of Bitfield object.
  void clear();

  Bitfield& operator =(const Bitfield& arg);
  bool operator==(const Bitfield& rhs) const;
  bool operator!=(const Bitfield& rhs) const;
  int operator[](unsigned int position) const;
};

#endif  // MODULES_BITFIELD_INCLUDE_BITFIELD_H_

