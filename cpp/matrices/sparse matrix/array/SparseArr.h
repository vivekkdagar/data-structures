//
// Created by vivekdagar on 6/10/24.
//

#ifndef CPP_SPARSEARR_H
#define CPP_SPARSEARR_H


#include <iostream>

struct Element {
    int row{};
    int col{};
    int val{};

    Element(int row, int col, int val) : row(row), col(col), val(val) {}

    Element() = default;
};

class SparseArr {
    int m;          // Dimensions of matrix: mxn where m is row and n is col
    int n;
    int nonZeroCount;           // Stores the number of non-zero elements
    Element *array;
public:
    SparseArr(int m, int n, int nonZeroCount);

    friend std::istream &operator>>(std::istream &is, const SparseArr &m);         // Input

    friend std::ostream &operator<<(std::ostream &os, const SparseArr &matrix);            // Printing

    SparseArr add(SparseArr &s);          // addition

    virtual ~SparseArr();
};


#endif //CPP_SPARSEARR_H
