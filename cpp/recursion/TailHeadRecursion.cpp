//
// Created by vivekdagar on 6/10/24.
//

#include <cstdio>

// Tail recursion: recursive call is the last statement in the function
void tail(int n) {
    if (n > 0) {
        printf("%d ", n);
        tail(n - 1);
    }
}

// Head recursion: recursive call is the first statement in the function
void head(int n) {
    if (n > 0) {
        head(n - 1);
        printf("%d ", n);
    }
}

//int main() {
//    head(5);
//    printf("\n");
//    tail(5);
//}