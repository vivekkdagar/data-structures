//
// Created by vivekdagar on 6/7/24.
//

// Q: Finding Single (and multiple) Missing Element in an Array

#include <bits/stdc++.h>

using namespace std;

int find(const vector<int> &array) {
    for (int i{0}; i < array.size() - 1; i++)
        if (array[i] + 1 != array[i + 1]) {
            cout << "Missing Element at " << (i+1) << ": " << (array[i] + 1) << endl;
        }
    return -1;
}