//
// Created by vivekdagar on 6/7/24.
//

#include <iostream>
#include <cmath>
#include "PolyArr.h"

PolyArr::PolyArr(int n) : n(n) {
    array = new Term[n];
}

void PolyArr::input() {
    int x, y;
    std::cout << "Enter coefficient and exponent of all terms: ";
    for (int i{0}; i < n; i++) {
        std::cin >> x >> y;
        array[i] = Term(x, y);
    }
}

std::ostream &operator<<(std::ostream &os, const PolyArr &arr) {
    for (int i{0}; i < arr.n; i++) {
        os << "(" << arr.array[i].coeff << "x)^" << arr.array[i].exp;
        if (i != arr.n - 1)
            os << " + ";
        else
            os << " ";
    }
    return os;
}

PolyArr PolyArr::add(const PolyArr &obj) {
    PolyArr sum(this->n + obj.n);

    int i{0}, j{0}, k{0};
    while (i < this->n && j < obj.n) {
        if (this->array[i].exp > obj.array[j].exp)
            sum.array[k++] = this->array[i++];
        else if (this->array[i].exp < obj.array[j].exp)
            sum.array[k++] = obj.array[j++];
        else {
            sum.array[k].exp = this->array[i].exp;
            sum.array[k++].coeff = this->array[i++].coeff + obj.array[j++].coeff;
        }
    }

    while (i < this->n)
        sum.array[k++] = this->array[i++];

    while (j < obj.n)
        sum.array[k++] = obj.array[j++];

    sum.n = k;
    return sum;
}

double PolyArr::eval(int x) {
    double res;
    for (int i{0}; i < this->n; i++)
        res += (this->array[i].coeff * pow(x, this->array[i].exp));
    return res;
}

PolyArr::~PolyArr() {
    delete[]array;
}