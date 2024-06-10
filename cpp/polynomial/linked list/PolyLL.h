//
// Created by vivekdagar on 6/10/24.
//

#ifndef CPP_POLYLL_H
#define CPP_POLYLL_H


#include <ostream>

struct Term {
    int coeff;
    int exp;
    Term *next;

    Term(int coeff, int exp, Term *next) : coeff(coeff), exp(exp), next(next) {}

    Term() : Term(-1, -1, nullptr) {}

    Term(int coeff, int exp) : Term(coeff, exp, nullptr){}
};

class PolyLL {
    Term *poly;
public:
    PolyLL() : poly(nullptr) {}

    explicit PolyLL(unsigned int exponent, int coefficient) {
        poly = new Term(exponent, coefficient);
    }

    explicit PolyLL(Term *poly);

    void create();

    friend std::ostream &operator<<(std::ostream &os, const PolyLL &ll);

    void add_term(unsigned exponent, int coefficient);

    long double eval(int x);

    PolyLL add(PolyLL obj);           // Basically merge 2 linked lists.

    virtual ~PolyLL();
};


#endif //CPP_POLYLL_H
