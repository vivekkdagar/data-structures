//
// Created by vivekdagar on 6/10/24.
//
#include <cstdio>

int fact(int n) {
    if (n == 0) return 1;
    return fact(n - 1) * n;
}

// Using the factorial function; the simplest way
int nCr(int n, int r) {
    int num = fact(n);
    int den = fact(r) * fact(n - r);
    return num / den;
}

int NCR(int n, int r) {
    if (n == r or r == 0)
        return 1;
    return NCR(n - 1, r - 1) + NCR(n - 1, r);
}

//int main() {
//    printf("%d ", NCR(5, 3));
//}