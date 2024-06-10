//
// Created by vivekdagar on 6/10/24.
//
#include <cstdio>

int power1(int m, int n) {
    if (n == 0)
        return 1;
    return power1(m, n - 1) * m;
}

int power2(int m, int n) {
    if (n == 0)
        return 1;
    if (not (n & 1))           // if even
        return power2(m * m, n / 2);
    return m * power2(m * m, (n - 1) / 2);
}

//int main() {
//    printf("%d ", power1(9, 3));
//}