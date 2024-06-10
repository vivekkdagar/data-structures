//
// Created by vivekdagar on 6/7/24.
//

#include <bits/stdc++.h>

#define RADIX 10

using namespace std;

int count_digits(int n) {
    int count{0};
    for (; n > 0; n /= 10)
        count++;
    return count;
}

int getBinIdx(int val, int idx) {
    return (int) (val / pow(10, idx)) % 10;
}

void radix_sort(vector<int> &A) {

    // Find max element and get the pass count from it. Total pass count would be equal to number of digits of the max element in the array
    int max = *max_element(A.begin(), A.end()), n = A.size();
    int nPass = count_digits(max);

    // Create a bins array of linked list having size = 10 (decimal has a base 10). List is the doubly linked list. I didn't use forward_list because I don't think it has to erase() method
    vector<list<int>> bins;
    bins.resize(RADIX);

    // Updating the bins array
    for (int pass{0}; pass < nPass; pass++) {

        // Filling the bins array
        for (int i{0}; i < n; i++) {
            bins[getBinIdx(A[i], pass)].push_back(A[i]);
        }

        // Update A with sorted elements from bin
        int x{0}, y{0};
        while (x < RADIX) {
            while (not bins[x].empty()) {
                A[y++] = bins[x].front();
                bins[x].pop_front();
            }
            x++;
        }

        // Initialize bins with nullptr again
        bins.resize(RADIX);
    }
}
