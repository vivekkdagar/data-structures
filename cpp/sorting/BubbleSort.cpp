//
// Created by vivekdagar on 6/7/24.
//

#include <vector>
#include <iostream>

// This will be O(n) if the list is already sorted
void bubble_sort(std::vector<int> &array) {
    bool flag;
    unsigned short pass{0}, comp{0};
    for (unsigned lastUnsortedIndex = array.size() - 1; lastUnsortedIndex > 0; lastUnsortedIndex--) {
        flag = false;
        pass++;
        for (int i{0}; i < lastUnsortedIndex; i++)
            if (array[i] > array[i + 1]) {
                std::swap(array[i], array[i + 1]);
                flag = true;
                comp++;
            }
        if (not flag)
            break;
    }
    std::cout << "Passes: " << pass << "\nComparisons: " << comp << std::endl;
}