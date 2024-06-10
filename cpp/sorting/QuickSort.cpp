//
// Created by vivekdagar on 6/7/24.
//
#include <vector>

using std::swap, std::vector;

int partition(vector<int> &array, int l, int h) {
    int pivot = array.at(l), i{l}, j{h};

    do {
        // Using i, find an element less than equal to pivot.
        do { i++; } while (array.at(i) <= pivot);

        // Using j, find an element strictly greater than pivot
        do { j--; } while (array.at(j) > pivot);

        // Swap them once found
        if (i < j) swap(array.at(i), array.at(j));
    } while (i < j);

    // swap pivot element with position j... the point at which pivot belongs
    swap(array.at(l), array.at(j));

    /* Since j is the point at which the pivot element belongs, we can say that the elements to the left of this point are smaller than the pivot
     * element and elements to the right of this point are greater than the pivot element, so this is the partitioning point */
    return j;
}

void quick_sort(vector<int> &array, int l, int h) {
    int j;
    if (l < h) {
        j = partition(array, l, h);
        quick_sort(array, l, j);
        quick_sort(array, j + 1, h);
    }
}