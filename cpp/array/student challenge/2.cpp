//
// Created by vivekdagar on 6/7/24.
//

// Q: Finding Duplicates in a Sorted Array

#include <bits/stdc++.h>

using namespace std;

void findDupInSortedArr(vector<int> v1) {
    sort(v1.begin(), v1.end());
    for (int i{0}; i < v1.size() - 1; i++) {
        if (v1.at(i) == v1.at(i + 1)) {
            int j = i + 1;
            while (v1[j] == v1[i]) j++;
            cout << v1.at(i) << " is occurring " << (j-i) << " times\n";
            i+=1;
        }
    }
}