//
// Created by vivekdagar on 6/8/24.
//

#include <ostream>
#include "Diagonal.h"

Diagonal::Diagonal(const unsigned short n) : n(n) {
    array.resize(n);
}

void Diagonal::set(unsigned short i, unsigned short j, int x) {
    if (i == j)
        array[i - 1] = x;
}

int Diagonal::get(unsigned short i, unsigned short j) const {
    return (i == j) ? array[i - 1] : 0;
}

std::ostream &operator<<(std::ostream &os, const Diagonal &matrix) {
    for (int i{1}; i <= matrix.n; i++) {
        for (int j{1}; j <= matrix.n; j++)
            os << matrix.get(i, j) << " ";
        os << std::endl;
    }
    return os;
}
