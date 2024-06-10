//
// Created by vivekdagar on 6/7/24.
//

// Q: Find maximum and minimum in a single scan

#include <bits/stdc++.h>

using namespace std;

pair<int, int> find(vector<int> array) {
    if (array.empty())
        return pair{0, 0};

    int max = array[0];
    int min = array[0];

    for (int i{1}; i < array.size(); i++) {
        if (max < array[i])
            max = array[i];
        else if (min > array[i])
            min = array[i];
    }

    return pair{min, max};
}

void print(pair<int, int> h) {
    cout << "Minimum element is: " << h.first << endl;
    cout << "Maximum element is: " << h.second << endl;
}