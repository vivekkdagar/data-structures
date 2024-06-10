//
// Created by vivekdagar on 6/7/24.
//

#include <iostream>
#include <vector>

using std::vector, std::cout, std::endl;

void insertion_sort(vector<int> &array) {
    int firstUnsortedIdx, newElement, shifts{0};           // passes will be n-1 where n is the size of the array
    for (firstUnsortedIdx = 1; firstUnsortedIdx < array.size(); firstUnsortedIdx++) {
        newElement = array.at(firstUnsortedIdx);            // to be inserted
        int sortedIdx;
        for (sortedIdx = firstUnsortedIdx; sortedIdx > 0 and array.at(sortedIdx - 1) > newElement; sortedIdx--) {
            array.at(sortedIdx) = array.at(sortedIdx - 1);
            shifts++;
        }
        array.at(sortedIdx) = newElement;
    }
    cout << "Passes are: " << firstUnsortedIdx << "\nShifts are: " << shifts << "\n";
}