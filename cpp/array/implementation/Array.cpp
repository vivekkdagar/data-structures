//
// Created by vivekdagar on 6/7/24.
//

#include <iostream>
#include "Array.h"

Array::Array(unsigned int size) : size(size), length(0) {
    A = new int[this->size];
}

bool Array::full() const {
    return length == size;
}

bool Array::empty() const {
    return length == 0;
}

void Array::insert(unsigned int index, int value) {
    if(not full() and index <= length) {
        for (unsigned i{length}; i > index; i--)
            A[i] = A[i - 1];
        A[index] = value;
        length++;
        return;
    }

    std::cerr << "Value not inserted!";
}

void Array::insert(int value) {
    if (not full())
        A[length++] = value;
}

int Array::get(unsigned int index) {
    if (index < length)
        return A[index];
    return -1;
}

void Array::set(unsigned int index, int value) {
    if (index < length) {
        A[index] = value;
        return;
    }

    std::cerr << "Invalid index\n";
}

std::ostream &operator<<(std::ostream &os, const Array &array) {
    os << "[";
    for (int i{0}; i < array.length; i++) {
        os << array.A[i];
        if (i != array.length - 1)
            os << ", ";
    }
    os << "]";
    return os;
}

void Array::remove(unsigned index) {
    if (index < length) {
        for (unsigned i{index}; i < length - 1; i++)
            A[i] = A[i + 1];
        length--;
        return;
    }

    std::cerr << "Invalid index\n";
}

unsigned Array::BSearch(int key) {
    unsigned low = 0, high = length - 1, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (this->A[mid] == key)
            return mid;
        if (this->A[mid] > key)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

unsigned Array::BSearch_R(int low, int high, int key) {
    int mid;
    if (low <= high) {
        mid = (low + high) / 2;
        if (this->A[mid] == key)
            return mid;
        else if (this->A[mid] > key)
            return this->BSearch_R(low, mid - 1, key);
        return this->BSearch_R(mid + 1, high, key);
    }
    return -1;
}

int Array::max() {
    int max = this->A[0];
    for (int i{1}; i < this->length; i++) {

        // For min element just switch < to >
        if (max < this->A[i])
            max = this->A[i];
    }
    return max;
}

std::istream &operator>>(std::istream &is, Array &array) {
    int value;
    while (is >> value) {
        if (array.full()) {
            throw std::overflow_error("Array is full");
        }
        array.insert(value);
    }
    return is;
}

bool Array::isSorted() {
    for(int i{0}; i < length-1; i++)
        if(A[i] > A[i+1])
            return false;
    return true;
}

Array::~Array() {
    delete[]A;
}


