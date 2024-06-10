//
// Created by vivekdagar on 6/7/24.
//

#include <vector>

void sort(std::vector<int> &A) {
    int n = A.size(), temp, i;
    for (int gap{n / 2}; gap >= 1; gap /= 2) {
        for (int j{gap}; j < n; j++) {
            temp = A.at(j);
            for (i = j - gap; i >= 0 and A[i] > temp; i -= gap)
                A[i + gap] = A[i];
            A[i + gap] = temp;
        }
    }
}