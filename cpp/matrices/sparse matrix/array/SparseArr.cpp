//
// Created by vivek on 27-01-2023.
//

#include "SparseArr.h"

SparseArr::SparseArr(int m, int n, int nonZeroCount) : m(m), n(n), nonZeroCount(nonZeroCount) {
    array = new Element[nonZeroCount];
}

std::istream &operator>>(std::istream &is, const SparseArr &m) {
    std::cout << "Enter non zero elements along with their respective dimensions: ";
    for (int i{0}; i < m.nonZeroCount; i++)
        is >> m.array[i].val >> m.array[i].row >> m.array[i].col;
    return is;
}

std::ostream &operator<<(std::ostream &os, const SparseArr &matrix) {
    int k{0};
    for (int i{0}; i < matrix.m; i++) {
        for (int j{0}; j < matrix.n; j++) {
            if (matrix.array[k].row == i && matrix.array[k].col == j)
                os << matrix.array[k++].val << " ";
            else
                os << "0 ";
        }
        os << std::endl;
    }
    return os;
}

SparseArr SparseArr::add(SparseArr &s) {
    // In case the dimensions don't match
    if (this->m != s.m || this->n != s.n)
        return {0, 0, 0};

    // This will store the result
    SparseArr sum(this->m, this->n, this->nonZeroCount + s.nonZeroCount);

    // Starting the addition
    int i{0}, j{0}, k{0};
    while (i < this->nonZeroCount && j < s.nonZeroCount) {
        if (this->array[i].row < s.array[j].row)
            sum.array[k++] = this->array[i++];
        else if (this->array[i].row > s.array[j].row)
            sum.array[k++] = s.array[j++];
        else {
            if (this->array[i].col > s.array[j].col)
                sum.array[k++] = s.array[j++];
            else if (this->array[i].col < s.array[j].col)
                sum.array[k++] = this->array[i++];
            else {
                sum.array[k] = this->array[i];
                sum.array[k++].val = this->array[i++].val + s.array[j++].val;
            }
        }
    }

    // Copy over remaining elements from matrix 1 and matrix 2
    while (i < this->nonZeroCount)
        sum.array[k++] = this->array[i++];

    while (j < s.nonZeroCount)
        sum.array[k++] = s.array[j++];

    sum.nonZeroCount = k;
    return sum;
}

SparseArr::~SparseArr() {
    delete[]array;
}





