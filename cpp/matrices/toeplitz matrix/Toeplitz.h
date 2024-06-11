//
// Created by vivekdagar on 6/10/24.
//

#ifndef CPP_TOEPLITZ_H
#define CPP_TOEPLITZ_H


#include <vector>
#include <ostream>

class Toeplitz {
    std::vector<int> array;
    unsigned short dimensions;
public:
    explicit Toeplitz(unsigned short dimensions);
    void set(unsigned i, unsigned j, int val);
    int get(unsigned i, unsigned j) const;

    friend std::ostream &operator<<(std::ostream &os, const Toeplitz &toeplitz);

    unsigned short getDimensions() const;
};


#endif //CPP_TOEPLITZ_H
