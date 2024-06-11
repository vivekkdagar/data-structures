//
// Created by vivekdagar on 6/10/24.
//

#ifndef CPP_DIAGONAL_H
#define CPP_DIAGONAL_H


#include <vector>
#include <ostream>

class Diagonal {
    const unsigned short n;         // dimension
    std::vector<int> array;
public:
    explicit Diagonal(unsigned short n);

    void set(unsigned short i, unsigned short j, int x);

    int get(unsigned short i, unsigned short j) const;

    friend std::ostream &operator<<(std::ostream &os, const Diagonal &matrix);
};

#endif //CPP_DIAGONAL_H
