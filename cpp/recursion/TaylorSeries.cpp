//
// Created by vivekdagar on 6/7/24.
//

double e(int x, int n) {
    static double p{1}, f{1};
    double r;

    if (n == 0)
        return 1;
    r = e(x, n - 1);
    p *= x;
    f *= n;
    return r + p / f;
}

// Using horner's rule
double horner(int x, int n) {
    static double s;
    if (n == 0)
        return s;
    s = 1 + x * s / n;
    return horner(x, n - 1);
}

// Iterative method
double itr(int x, int n) {
    double s{1}, num{1}, den{1};

    for(int i{1}; i <=n; i++) {
        num *= x;
        den *= i;
        s += num/den;
    }

    return s;
}

/*
int main() {
    printf("%lf ", e(2, 15));
}*/