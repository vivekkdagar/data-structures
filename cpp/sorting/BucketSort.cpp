//
// Created by vivekdagar on 6/7/24.
//

#include <bits/stdc++.h>

using namespace std;

void bucket_sort(vector<int> &A) {

    // Find max element
    int max = *max_element(A.begin(), A.end());

    // Create a bins array of linked list having max+1 size. List is the doubly linked list. I didn't use forward_list because I don't think it has the erase() method
    vector<list<int>> bins;
    bins.resize(max+1);

    // Filing the array of linked list. For example: index 3 would contain all the 3s present in the main array and so forth.
    for(int i : A)
        bins[i].push_front(i);

    int j{0}, i{0};
    while(i <= max) {

        // Keep filling the main array by the elements present in the linked list.
        while(not bins[i].empty()) {
            A[j++] = bins[i].front();
            bins[i].erase(bins[i].begin());
        }
        i++;
    }
}