//
// Created by vivekdagar on 6/7/24.
//

// Q: Find a pair of elements with sum K in a sorted and unsorted array

#include <bits/stdc++.h>

using namespace std;

// For sorted array
void find1(vector<int> v1, int k) {

    int i{0}, j = v1.size() - 1;
    while (i < j) {
        if (v1.at(i) + v1.at(j) == k) {
            cout << "Pair found: " << "[" << v1[i] << ", " << v1[j] << "]\n";
            i++;
            j--;
        } else if (v1.at(i) + v1.at(j) < k)
            i++;
        else
            j--;
    }
}

// For unsorted array, method 1:
void find2(vector<int> arr, int k) {
    for (int i{0}; i < arr.size() - 1; i++) {
        for (int j = i + 1; j < arr.size(); j++)
            if (arr[i] + arr[j] == k)
                cout << "Pair found: " << "[" << arr[i] << ", " << arr[j] << "]\n";
    }
}

// For unsorted array, method 2:
void find3(vector<int> arr, int k) {
    vector<int> hashTable;
    hashTable.resize(*std::max_element(arr.begin(), arr.end()) + 1);

    for (int i{0}; i < arr.size(); i++) {
        int t = arr[i];
        if ((k - t) >= 0 && hashTable[k - t] != 0) {
            cout << "Pair found: " << "[" << arr[i] << ", " << k - arr[i] << "]\n";
        }
        hashTable[t]++;
    }
}