//
// Created by vivekdagar on 6/10/24.
//

#include "UTMatrix.h"

std::ostream &operator<<(std::ostream &os, const UTMatrix &triangular) {
    for (int i{1}; i <= triangular.getDimensions(); i++) {
        for (int j{1}; j <= triangular.getDimensions(); j++)
            os << triangular.get(i, j) << " ";
        os << "\n";
    }
    return os;
}

UTMatrix::~UTMatrix() {
    delete[]array;
}

int UTMatrix::get(unsigned int i, unsigned int j) const {
    if (i <= j)
        return array[((i - 1) * dimensions - (i - 2) * (i - 1) / 2) + (j - i)];
    return 0;
}

void UTMatrix::set(unsigned int i, unsigned int j, int value) {
    if (i <= j)
        array[((i - 1) * dimensions - (i - 2) * (i - 1) / 2) + (j - i)] = value;         // row major mapping formula
}

UTMatrix::UTMatrix(unsigned int dimensions) : dimensions(dimensions) {
    array = new int[dimensions * (dimensions + 1) /
                    2];         // n * (n+1)/2 non 0 elements are in a upper or lower triangular matrix
}
