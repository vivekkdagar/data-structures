//
// Created by vivekdagar on 6/10/24.
//

#ifndef CPP_UTMATRIX_H
#define CPP_UTMATRIX_H


#include <ostream>

class UTMatrix {
    unsigned dimensions;
    int *array;
public:
    explicit UTMatrix(unsigned dimensions);

    void set(unsigned i, unsigned j, int value);

    int get(unsigned i, unsigned j) const;

    friend std::ostream &operator<<(std::ostream &os, const UTMatrix &triangular);

    unsigned getDimensions() const {
        return dimensions;
    }

    virtual ~UTMatrix();
};


#endif //CPP_UTMATRIX_H
