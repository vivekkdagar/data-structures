//
// Created by vivekdagar on 6/10/24.
//

int fun(int n) {
    if(n > 100)
        return n-10;
    return fun(fun(n+11));
}
//int main() {
//    printf("%d ", fun(200));
//}