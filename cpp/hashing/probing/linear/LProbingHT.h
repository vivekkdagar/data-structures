//
// Created by vivekdagar on 6/7/24.
//

#ifndef CPP_LPROBINGHT_H
#define CPP_LPROBINGHT_H

#define SIZE 10

#include <vector>

class LProbingHT {
    std::vector<int> HT;
public:
    LProbingHT() {
        HT.resize(SIZE);
    }

    void insert(int key);

    int indexOf(int key);

    bool belongs(int key);

    void remove(int key);

    double getLoadFactor();

    virtual ~LProbingHT();
private:
    static int hash(int key) {
        return key % SIZE;
    }

    int probe(int key);
};


#endif //CPP_LPROBINGHT_H
