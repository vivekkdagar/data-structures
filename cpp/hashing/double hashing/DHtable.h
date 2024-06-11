//
// Created by vivekdagar on 6/7/24.
//

#ifndef CPP_DHTABLE_H
#define CPP_DHTABLE_H

#include <vector>

#define SIZE 10
#define PRIME 7

class DHtable {
    std::vector<int> HT;
public:
    DHtable();

    static int hash(int key);

    static int prime_hash(int key);

    int double_hash(int key);

    void insert(int key);

    double getLoadFactor();
};


#endif //CPP_DHTABLE_H
