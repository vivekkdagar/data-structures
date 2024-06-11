//
// Created by vivekdagar on 6/8/24.
//

#ifndef CPP_QPROBINGHT_H
#define CPP_QPROBINGHT_H
#define SIZE 10

#include <vector>

class QProbingHT {
    std::vector<int> HT;
public:
    QProbingHT() {
        HT.resize(SIZE);
    }

    void insert(int key);

    bool belongs(int key);

    void remove(int key);

    int indexOf(int key);

    virtual ~QProbingHT();

private:
    static int hash(int key);

    int probe(int key);
};


#endif //CPP_QPROBINGHT_H
