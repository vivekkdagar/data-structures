//
// Created by vivekdagar on 6/7/24.
//
#include <vector>
#include <algorithm>

using std::vector;

void count_sort(vector<int> &array) {

    // Find the max element
    int max = *max_element(array.begin(), array.end());

    // Make an array of size max + 1, indices will be the elements and the value they contain will be the frequency at which they appear in the original array
    vector<int> count;
    count.resize(max + 1);

    // Mark the frequency of each element of main array in the count array
    for (int i: array)
        count[i]++;

    // Start overwriting the main array
    int j{0}, i{0};
    while (i <= max) {
        if (count[i] > 0) {
            array.at(j++) = i;
            count.at(i)--;
        } else i++;
    }
}