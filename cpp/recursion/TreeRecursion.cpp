//
// Created by vivekdagar on 6/10/24.
//
#include <cstdio>

void tree(int n) {
    if(n > 0) {
        printf("%d ", n);
        tree(n-1);
        tree(n-1);
    }
}

//int main() {
//    tree(3);
//}