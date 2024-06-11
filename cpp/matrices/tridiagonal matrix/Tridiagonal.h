//
// Created by vivekdagar on 6/10/24.
//

#ifndef CPP_TRIDIAGONAL_H
#define CPP_TRIDIAGONAL_H


#include <vector>
#include <ostream>

class Tridiagonal {
    unsigned short dimensions;
    std::vector<int> array;
public:
    explicit Tridiagonal(unsigned short dimensions);

    unsigned short getDimensions() const {
        return dimensions;
    }

    void set(unsigned short i, unsigned short j, int value);

    int get(unsigned short i, unsigned short j) const;

    friend std::ostream &operator<<(std::ostream &os, const Tridiagonal &matrix);

    virtual ~Tridiagonal();
};


#endif //CPP_TRIDIAGONAL_H
