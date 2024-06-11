//
// Created by vivekdagar on 6/10/24.
//

#include "Tridiagonal.h"

Tridiagonal::Tridiagonal(unsigned short dimensions) : dimensions(dimensions) {
    unsigned size = 3 * dimensions - 2;
    array.resize(size);
}

std::ostream &operator<<(std::ostream &os, const Tridiagonal &matrix) {
    for (int i{1}; i <= matrix.dimensions; i++) {
        for (int j{1}; j <= matrix.dimensions; j++) {
            if (i - j == 1)
                os << matrix.array[i - 2] << " ";
            else if (i - j == 0)
                os << matrix.array[matrix.dimensions + i - 2] << " ";
            else if (i - j == -1)
                os << matrix.array[2 * matrix.dimensions + i - 2] << " ";
            else
                os << 0 << " ";
        }
        os << std::endl;
    }
    return os;
}

int Tridiagonal::get(unsigned short i, unsigned short j) const {
    int t = i - j;
    switch (t) {
        case 1:
            return this->array[i - 2];
        case 0:
            return this->array[dimensions + i - 2];
        case -1:
            return this->array[2 * dimensions + i - 2];
        default:
            return 0;
    }
}

void Tridiagonal::set(unsigned short i, unsigned short j, int value) {
    if (i - j == 1)
        this->array[i - 2] = value;
    else if (i - j == 0)
        this->array[dimensions + i - 2] = value;
    else if (i - j == -1)
        this->array[2 * dimensions + i - 2] = value;
}

Tridiagonal::~Tridiagonal() = default;
