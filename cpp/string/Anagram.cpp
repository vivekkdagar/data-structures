// We won't take strings containing duplicates or any capital letters in this program

#include <iostream>
#include <vector>

using std::string, std::vector;

bool anagram(string a, string b) {
    int m = a.length();
    int n = b.length();
    if (m not_eq n) return false;

    vector<int> hash;
    hash.resize(26);

    // Filling it
    for (int i{0}; i < m; i++)
        hash[a[i] - 97] += 1;

    // Checking for anagram
    for (int i{0}; i < n; i++) {
        hash[b[i] - 97] -= 1;
        if (hash[b[i] - 97] < 0)
            return false;
    }

    return true;
}