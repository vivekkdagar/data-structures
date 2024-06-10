//
// Created by vivekdagar on 6/10/24.
//
#include <cstdio>

void TOH(int n, int A, int B, int C) {
    if(n > 0) {
        TOH(n-1,A,C,B);
        printf("Move a disc from %d to %d\n",A,C);
        TOH(n-1,B,A,C);
    }
}
/*
 * int main() {
    TOH(2,1,2,3);
}
 */