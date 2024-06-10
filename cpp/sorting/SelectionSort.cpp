//
// Created by vivekdagar on 6/7/24.
//

#include <iostream>
#include <vector>

using std::swap, std::vector, std::cout, std::endl;

void selection_sort(vector<int> &arr) {
    int comparisons{0}, swaps{0};
    for (unsigned lastUnsortedIndex = arr.size() - 1; lastUnsortedIndex > 0; lastUnsortedIndex--) {
        int max = 0;
        for (int i{1}; i <= lastUnsortedIndex; i++) {
            comparisons++;
            if (arr.at(i) > arr.at(max))
                max = i;
        }
        swap(arr.at(lastUnsortedIndex), arr.at(max));
        swaps++;
    }
    cout << "Comparisons: " << comparisons << "\nSwaps: " << swaps << endl;
}