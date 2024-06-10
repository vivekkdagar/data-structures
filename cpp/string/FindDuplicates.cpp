// The strings have to contain only lower case letters

#include <bits/stdc++.h>

using std::string, std::cout, std::vector;

// Using hash table
void hashing(string s) {
    vector<int> hash;
    hash.resize(26);

    // Filling hashtable
    for (int i{0}; i < s.length(); i++)
        hash[s[i] - 97] += 1;

    for (int i{0}; i < 26; i++)
        if (hash[i] > 1)
            cout << char(i + 97) << " is appearing " << hash[i] << " times\n";
}


// Using bitwise operations
void bitwise(string s) {
    long h{0}, x{0};
    for (int i{0}; i < s.length(); i++) {
        x = 1;
        x = x << (s[i] - 97);           // Left shift x by (s[i] - 97) times
        if ((x & h) > 0)            // if it gives a valid alphabet
            cout << s[i] << " is duplicate\n";
        else
            h = x | h;
    }
}