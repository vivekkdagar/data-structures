//
// Created by vivekdagar on 6/10/24.
//
#include <cstdio>

// Sum of first n numbers using recursion
int sum(int n) {
    if (n == 0)
        return 0;
    return sum(n - 1) + n;
}

// Sum of first n numbers using iteration
int sumItr(int n) {
    int s{0};
    for(int i{1}; i <= n; i++)
        s += i;
    return s;
}