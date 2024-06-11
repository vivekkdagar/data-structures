//
// Created by vivekdagar on 6/10/24.
//

#include <iostream>
#include "LTMatrix.h"

LTMatrix::LTMatrix(unsigned short dimensions) : dimensions(dimensions){
    nonZeroElements = (dimensions * (dimensions - 1)) / 2;
    A.resize(nonZeroElements);
}

std::ostream &operator<<(std::ostream &os, const LTMatrix &matrix) {
    for (int i{1}; i <= matrix.dimensions; i++) {
        for (int j{1}; j <= matrix.dimensions; j++) {
            os << matrix.getRowMajor(i, j) << " ";
        }
        os << std::endl;
    }
    return os;
}

void LTMatrix::setRowMajor(unsigned short i, unsigned short j, int x) {
    if (i >= j) {
        int idx = (i * (i - 1) / 2) + (j - 1);
        this->A[idx] = x;
    }
}

int LTMatrix::getRowMajor(unsigned short i, unsigned short j) const {
    if (i >= j)
        return this->A[(i * (i - 1) / 2) + (j - 1)];
    return 0;
}

void LTMatrix::setColMajor(unsigned short i, unsigned short j, int x) {
    if (i >= j) {
        int index = (this->dimensions * (j - 1) - (((j - 2) * (j - 1)) / 2)) + (i - j);
        A[index] = x;
    }
}

int LTMatrix::getColMajor(unsigned short i, unsigned short j) const {
    if (i >= j)
        return A[(this->dimensions * (j - 1) - (((j - 2) * (j - 1)) / 2)) + (i - j)];
    return 0;
}

void LTMatrix::printColMajor() const {
    for (int i{1}; i <= this->dimensions; i++) {
        for (int j{1}; j <= this->dimensions; j++)
            std::cout << this->getColMajor(i, j) << " ";
        std::cout << std::endl;
    }
}
