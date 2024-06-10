//
// Created by vivekdagar on 6/7/24.
//

#ifndef CPP_ARRAY_H
#define CPP_ARRAY_H


#include <ostream>

class Array {
    int *A;
    unsigned size;
    unsigned length;
public:
    explicit Array(unsigned int size);

    bool full() const;

    void insert(unsigned index, int value);

    // To append values
    void insert(int value);

    int get(unsigned index);

    void set(unsigned index, int value);

    void remove(unsigned index);

    bool empty() const;

    // Searching algorithms
    // For optimization of linear search: Swap that element with first element if found.
    // Binary search implemented below
    unsigned BSearch(int key);

    unsigned BSearch_R(int low, int high, int key);

    int max();

    bool isSorted();

    friend std::istream &operator>>(std::istream &is, Array &array);

    friend std::ostream &operator<<(std::ostream &os, const Array &array);

    virtual ~Array();
};


#endif //CPP_ARRAY_H
