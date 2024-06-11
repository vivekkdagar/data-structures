//
// Created by vivek on 20-02-2023.
//

#include "Symmetric.h"

#include <iostream>
#include "Symmetric.h"

Symmetric::Symmetric(unsigned int dimensions) : dimensions(dimensions) {
    array.resize(
            dimensions * (dimensions + 1) / 2);        // n * (n+1)/2 non-zero elements are in a upper triangular matrix
}

void Symmetric::set(unsigned int i, unsigned int j, int value) {
    if (i >= j)
        array[i * (i - 1) / 2 + (j - 1)] = value;         // row major mapping formula
}

int Symmetric::get(unsigned int i, unsigned int j) const {
    if (i >= j) {
        return array[i * (i - 1) / 2 + (j - 1)];
    }
    return array[j * (j - 1) / 2 + (i - 1)];
}

std::ostream &operator<<(std::ostream &os, const Symmetric &triangular) {
    for (int i{1}; i <= triangular.dimensions; i++) {
        for (int j{1}; j <= triangular.dimensions; j++) {
            if (i >= j)
                std::cout << triangular.array[i * (i - 1) / 2 + (j - 1)] << " ";
            else
                std::cout << triangular.array[j * (j - 1) / 2 + (i - 1)] << " ";
        }
        std::cout << std::endl;
    }
}

unsigned int Symmetric::getDimensions() const {
    return dimensions;
}

Symmetric::~Symmetric() {
    array.clear();
}