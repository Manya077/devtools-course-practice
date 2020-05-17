// Copyright 2020 Kudryashov Nikita

#define UNSIGNED_CHAR_SIZE 8

#include "include/bitfield.h"
#include <string>
#include <vector>

Bitfield::Bitfield(unsigned int size) {
    bitfield_size = size;

    unsigned int quotient = size / UNSIGNED_CHAR_SIZE;
    unsigned int remainder = size % UNSIGNED_CHAR_SIZE;

    // Bitfield object creates empty (having 0 at all positions).
    if (remainder == 0) {
        // Resize vector to specified size and fill with elements.
        bitfield.resize(quotient, 0);
    } else {
        // Resize vector to specified size and fill with elements.
        bitfield.resize(quotient + 1, 0);
    }
}

void Bitfield::set(unsigned int position) {
    if (position > bitfield_size - 1) {
        throw(std::string)"Out of bounds setting";
    } else {
        bitfield[position / UNSIGNED_CHAR_SIZE] |=
        (1 << ((UNSIGNED_CHAR_SIZE - 1) - position % UNSIGNED_CHAR_SIZE));
    }
}

unsigned int Bitfield::get_size() const {
    return bitfield_size;
}

void Bitfield::unset(unsigned int position) {
    if (position > bitfield_size - 1) {
        throw(std::string)"Out of bounds unsetting";
    } else {
        bitfield[position / UNSIGNED_CHAR_SIZE] &=
        (~(1 << ((UNSIGNED_CHAR_SIZE - 1) - position % UNSIGNED_CHAR_SIZE)));
    }
}

int Bitfield::get(unsigned int position) const {
    if (position > bitfield_size - 1) {
        throw(std::string)"Out of bounds unsetting";
    } else {
        unsigned char temp = (bitfield[position / UNSIGNED_CHAR_SIZE] <<
                (position % UNSIGNED_CHAR_SIZE));
        return temp >> (UNSIGNED_CHAR_SIZE - 1);
    }
}

void Bitfield::fill() {
    for (unsigned int i = 0; i < bitfield.size(); ++i) {
        bitfield[i] = 255;
    }
}

void Bitfield::clear() {
    for (unsigned int i = 0; i < bitfield.size(); ++i) {
        bitfield[i] = 0;
    }
}

void Bitfield::set(const std::vector<unsigned int>& arr_of_positions) {
    for (unsigned int i = 0; i < arr_of_positions.size(); ++i) {
        if (arr_of_positions[i] > bitfield_size - 1) {
            throw(std::string)"Out of bounds setting";
        } else {
            set(arr_of_positions[i]);
        }
    }
}

void Bitfield::unset(const std::vector<unsigned int>& arr_of_positions) {
    for (unsigned int i = 0; i < arr_of_positions.size(); ++i) {
        if (arr_of_positions[i] > bitfield_size - 1) {
            throw(std::string)"Out of bounds unsetting";
        } else {
            unset(arr_of_positions[i]);
        }
    }
}

Bitfield& Bitfield::operator =(const Bitfield& arg) {
    if (this != &arg) {
        if (bitfield_size != arg.bitfield_size) {
            bitfield.resize(arg.bitfield.size());
            bitfield_size = arg.bitfield_size;
        }
        for (unsigned int i = 0; i < bitfield.size(); ++i) {
            bitfield[i] = arg.bitfield[i];
        }
    }

    return *this;
}

bool Bitfield::operator ==(const Bitfield& rhs) const {
    if (bitfield_size != rhs.bitfield_size) {
        return false;
    } else {
        for (unsigned int i = 0; i < rhs.bitfield.size(); ++i) {
            if (bitfield[i] != rhs.bitfield[i]) {
                return false;
            }
        }
        return true;
    }
}

bool Bitfield::operator !=(const Bitfield& rhs) const {
    return  !(*this == rhs);
}

int Bitfield::operator[](unsigned int position) const {
    if (position > bitfield_size - 1) {
        throw(std::string)"Out of bounds getting.";
    } else {
        return get(position);
    }
}
