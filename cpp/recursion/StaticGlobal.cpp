//
// Created by vivekdagar on 6/10/24.
//

// Function with static variable
int stFun(int n) {
    static int x{0};
    if (n > 0) {
        x++;
        return stFun(n - 1) + x;
    }
    return 0;
}

int y{0};

// Function with global variable
int glFun(int n) {
    if (n > 0) {
        y++;
        return glFun(n - 1) + y;
    }
    return 0;
}

//int main() {
//    printf("%d\n", stFun(5));
//    printf("%d", glFun(5));
//}