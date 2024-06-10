//
// Created by vivekdagar on 6/7/24.
//
#include <vector>

using std::vector;

void merge(vector<int> &A, int l, int mid, int h) {
    // Auxiliary array to store the merged array
    vector<int> B;
    B.resize(100);

    int i{l}, j{mid + 1}, k{l};

    // Start of merging process
    while (i <= mid and j <= h)
        B[k++] = (A[i] < A[j]) ? A[i++] : A[j++];

    // Copying over the leftover elements from first half of array
    while (i <= mid)
        B[k++] = A[i++];

    // Copying over the leftover elements from second half of array
    while (j <= h)
        B[k++] = A[j++];

    for (int t{l}; t <= h; t++)
        A[t] = B[t];
}

void mergesort_I(vector<int> &A, int n) {
    int p, l, h, mid;

    // The variable p is for passes.
    for (p = 2; p <= n; p *= 2) {

        // Since i is incremented by passes, we check if i+p-1 is less than size or not, this is to prevent us from going out of bounds.
        for (int i{0}; i + p - 1 < n; i += p) {
            l = i;
            h = i + p - 1;
            mid = (l + h) / 2;
            merge(A, l, mid, h);
        }
    }

    if (p / 2 < n)
        merge(A, 0, (p / 2) - 1, n - 1);
}

void mergesort_R(vector<int> &A, int l, int h) {
    int mid;
    if (l < h) {
        mid = (l + h) / 2;
        mergesort_R(A, l, mid);
        mergesort_R(A, mid + 1, h);
        merge(A, l, mid, h);
    }
}