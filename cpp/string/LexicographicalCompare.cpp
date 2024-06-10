//
// Created by vivekdagar on 6/7/24.
//

#include <bits/stdc++.h>

using std::string;

string compare(string a, string b) {
    if(a == b)
        return "Equal";

    int i{0}, j{0};
    while(i < a.length() && j < b.length()) {
        if(a[i] > b[j])
            return "Greater";
        else if(a[i] < b[j])
            return "Smaller";
        i++;
        j++;
    }

    if(a.length() > b.length())
        return "Greater";
    return "Smaller";
}