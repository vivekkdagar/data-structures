//
// Created by vivekdagar on 6/7/24.
//
#include <cstdio>
#include <vector>

using namespace std;

int itr(int n) {
    if (n <= 1) return n;

    int t0{0}, t1{1}, s{0};

    for (int i{2}; i <= n; i++) {
        s = t0 + t1;
        t0 = t1;
        t1 = s;
    }

    return s;
}

// Recursive fibonacci series
int fib(int n) {
    if (n <= 1)
        return n;
    return fib(n - 2) + fib(n - 1);
}

// Using memoization
vector<int> F;

int fibMem(int n) {
    if (n <= 1) {
        F[n] = n;
        return n;
    } else {
        if (F[n - 2] == -1)
            F[n - 2] = fibMem(n - 2);
        if (F[n - 1] == -1)
            F[n - 1] = fibMem(n - 1);
        return F[n - 2] + F[n - 1];
    }
}

/*
int main() {
    F.resize(10);
    fill(F.begin(), F.end(), -1);
    printf("%d ", fibMem(6));
} */