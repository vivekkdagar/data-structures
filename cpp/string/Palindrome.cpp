//
// Created by vivekdagar on 6/7/24.
//
#include <iostream>

using std::string;

string reverse(string s) {
    int n = s.size();
    for(int i = 0, j = n-1; i <= j; i++, j--)
        std::swap(s[i], s[j]);
    return s;
}

bool palindrome(const string& s) {
    return s == reverse(s);
}