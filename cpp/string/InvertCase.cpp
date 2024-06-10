
// Invert case: change capital letters to small and vice versa
void invert(char A[]) {
    for (int i = 0; A[i] != '\0'; i++) {
        if (65 <= A[i] and A[i] <= 90)
            A[i] += 32;
        else if (97 <= A[i] and A[i] <= 122)
            A[i] -= 32;
    }
}