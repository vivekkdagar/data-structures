//
// Created by vivekdagar on 6/7/24.
//

#include <vector>

using std::swap, std::vector;

// Rearranges all -ve to right side
void rearrange(vector<int> &arr) {
    int i = 0, j = arr.size() - 1;
    while(i < j) {
        while(arr[i] < 0) i++;
        while(arr[j] >= 0) j--;
        if(i < j)
            std::swap(arr[i], arr[j]);
    }
}