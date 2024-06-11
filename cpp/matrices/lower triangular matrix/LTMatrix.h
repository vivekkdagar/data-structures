//
// Created by vivekdagar on 6/10/24.
//

#ifndef CPP_LTMATRIX_H
#define CPP_LTMATRIX_H


#include <vector>
#include <ostream>

class LTMatrix {
    int nonZeroElements;
    std::vector<int> A;
    unsigned short dimensions;
public:
    explicit LTMatrix(unsigned short dimensions);

    void setRowMajor(unsigned short i, unsigned short j, int x);

    int getRowMajor(unsigned short i, unsigned short j) const;

    friend std::ostream &operator<<(std::ostream &os, const LTMatrix &matrix);

    void setColMajor(unsigned short i, unsigned short j, int x);

    int getColMajor(unsigned short i, unsigned short j) const;

    void printColMajor() const;
};


#endif //CPP_LTMATRIX_H
