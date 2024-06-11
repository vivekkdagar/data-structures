//
// Created by vivekdagar on 6/7/24.
//

#include "LProbingHT.h"

int LProbingHT::probe(int key) {
    int idx = hash(key), i{0};
    while (HT[(idx + i) % SIZE] not_eq 0)
        i++;
    return (idx + i) % SIZE;
}

void LProbingHT::insert(int key) {
    int idx{hash(key)};
    if (HT[idx] not_eq 0)
        idx = this->probe(key);
    HT[idx] = key;
}

int LProbingHT::indexOf(int key) {
    int idx = hash(key);
    int i{0};
    while (HT[(idx + i) % SIZE] != key) {
        i++;
        if (HT[(idx + i) % SIZE] == 0)
            return -1;
    }
    return (idx + i) % SIZE;
}

bool LProbingHT::belongs(int key) {
    if (indexOf(key) == -1)
        return false;
    return indexOf(key) == hash(key);
}

void LProbingHT::remove(int key) {
    std::vector<int> temp;

    // Take out elements from the HT
    for (auto i: HT)
        if (i not_eq key and i not_eq 0)
            temp.push_back(i);

    // Clear the hashtable and fill it with 0s as it was in the beginning
    this->HT.clear();
    this->HT.resize(SIZE);

    // Insert them back into the hashtable
    for (auto i: temp)
        this->insert(i);
}

double LProbingHT::getLoadFactor() {
    double count{0};
    for (auto i: HT)
        if (i not_eq 0)
            count++;
    return count / SIZE;
}

LProbingHT::~LProbingHT() = default;