//
// Created by vivekdagar on 6/7/24.
//

#ifndef CPP_CHAINHASHING_H
#define CPP_CHAINHASHING_H

#define SIZE 10

#include <vector>

struct Node {
    int data;
    Node *next;

    explicit Node(int data) : data(data), next(nullptr) {}
};

class ChainHashing {
    std::vector<Node *> HT;
public:
    ChainHashing();

    static int hash(int key) {
        return key % SIZE;
    }

    void insert(int key);

    int search(int key);

    int remove(int key);

    virtual ~ChainHashing();

private:
    int indexOf(int key);
};


#endif //CPP_CHAINHASHING_H
