//
// Created by vivekdagar on 6/10/24.
//

#ifndef CPP_SYMMETRIC_H
#define CPP_SYMMETRIC_H


#include <vector>
#include <ostream>

class Symmetric {
    unsigned dimensions;
    std::vector<int> array;
public:
    explicit Symmetric(unsigned int dimensions);

    void set(unsigned i, unsigned j, int value);

    int get(unsigned i, unsigned j) const;

    friend std::ostream &operator<<(std::ostream &os, const Symmetric &triangular);

    unsigned int getDimensions() const;

    virtual ~Symmetric();
};



#endif //CPP_SYMMETRIC_H
