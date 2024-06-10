//
// Created by vivek on 17-02-2023.
//

#include <iostream>
#include "PolyLL.h"
#include <cmath>

PolyLL::PolyLL(Term *poly) : poly(poly) {}

void PolyLL::create() {
    // Necessary variables
    int n;
    Term *t, *last;

    // Number of terms
    std::cout << "Enter the number of terms: ";
    std::cin >> n;

    std::cout << "Enter each term with coeff and exp: ";
    for (int i{0}; i < n; i++) {

        // Enter data and create a new node
        int a, b;
        std::cin >> a >> b;
        t = new Term(a, b, nullptr);

        // If not a single node is there, this is the first and the last node
        if (not poly)
            poly = last = t;

            // else this is the last node
        else {
            last->next = t;
            last = t;
        }
    }
}

std::ostream &operator<<(std::ostream &os, const PolyLL &ll) {
    for (Term *t = ll.poly; t not_eq nullptr; t = t->next) {
        os << "(" << t->coeff << "x)^" << t->exp;
        if (t->next)
            os << " + ";
        else
            os << " ";
    }
    os << std::endl;
    return os;
}

long double PolyLL::eval(int x) {
    long double val{0};

    for (Term *t = poly; t not_eq nullptr; t = t->next)
        val += t->coeff * pow(x, t->exp);
    return val;
}

PolyLL::~PolyLL() {
    Term *t = poly;
    while(t) {
        poly = poly->next;
        delete t;
        t = poly;
    }
}

void PolyLL::add_term(unsigned int exponent, int coefficient) {
    if (poly == nullptr) {
        poly = new Term(exponent, coefficient);
    } else {
        Term *head = new Term(exponent, coefficient);
        head->next = poly;
        poly = head;
    }
}

