//
// Created by vivekdagar on 6/10/24.
//

#ifndef CPP_POLYARR_H
#define CPP_POLYARR_H


#include <ostream>

struct Term {
    int coeff;
    int exp;

    Term(int coeff, int exp) : coeff(coeff) , exp(exp) {}

    Term() = default;
};

class PolyArr {
    int n;          // number of terms
    Term *array;
public:
    explicit PolyArr(int n);

    void input();

    friend std::ostream &operator<<(std::ostream &os, const PolyArr &arr);

    PolyArr add(const PolyArr &obj);

    double eval(int x);

    virtual ~PolyArr();
};


#endif //CPP_POLYARR_H
