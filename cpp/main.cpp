#include <iostream>
#include "polynomial/array/PolyArr.h"

using std::cin, std::cout;

// for remove, indices start from 1 onwards

int main() {
    PolyArr p(2);
    p.input();
    PolyArr p1(2);
    p1.input();
    cout << p.eval(1);
}
