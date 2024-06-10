//
// Created by vivekdagar on 6/7/24.
//

#include "USet.h"
#include <algorithm>

using std::find;

USet::USet(const std::vector<int> &array) : array(array) {}

USet::USet() = default;

void USet::Union(USet src) {
    for (int i{0}; i < src.array.size(); i++)
        if (find(this->array.begin(), this->array.end(), src.array.at(i)) == array.end())
            this->array.push_back(src.array.at(i));
}

void USet::Intersection(USet src) {
    std::vector<int> v3;
    for (int i{0}; i < this->array.size(); i++)
        if (find(src.array.begin(), src.array.end(), this->array[i]) != src.array.end())
            v3.push_back(this->array.at(i));
    this->array = v3;
}

void USet::Difference(USet src) {
    std::vector<int> v3;
    for (int i{0}; i < this->array.size(); i++)
        if (find(src.array.begin(), src.array.end(), this->array[i]) == src.array.end())
            v3.push_back(this->array.at(i));
    this->array = v3;
}

std::ostream &operator<<(std::ostream &os, const USet &set) {
    os << '[';
    int t = set.array.size();
    for (int i = 0; i < t; ++i) {
        os << set.array.at(i);
        if (i != t - 1) {
            os << ", ";
        }
    }
    os << ']';
    return os;
}