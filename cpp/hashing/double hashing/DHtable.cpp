//
// Created by vivekdagar on 6/7/24.
//

#include "DHtable.h"

int DHtable::hash(int key) {
    return key % SIZE;
}

DHtable::DHtable() {
    HT.resize(SIZE);
}

int DHtable::prime_hash(int key) {
    return PRIME - (key % PRIME);
}

int DHtable::double_hash(int key) {
    int idx = hash(key), i = 0;
    while (this->HT[(idx + (i * prime_hash(key))) % SIZE] not_eq 0)
        i++;
    return (idx + i * prime_hash(key)) % SIZE;
}

void DHtable::insert(int key) {
    int idx = hash(key);
    if (HT[idx] not_eq 0)
        idx = this->double_hash(key);
    HT[idx] = key;
}

double DHtable::getLoadFactor() {
    double count{0};
    for (auto i: HT)
        if (i not_eq 0)
            count++;
    return count / SIZE;
}
