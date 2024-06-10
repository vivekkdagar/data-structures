//
// Created by vivekdagar on 6/10/24.
//

#ifndef CPP_DOUBLYLL_H
#define CPP_DOUBLYLL_H

#include <vector>
#include <iostream>

struct Node {
    Node *prev;
    int data;
    Node *next;

    Node(Node *prev, int data, Node *next) : prev(prev), data(data), next(next) {}
};

class DoublyLL {
    Node *first;
    unsigned len;
public:
    explicit DoublyLL(const std::vector<int> &n);

    friend std::ostream &operator<<(std::ostream &os, const DoublyLL &ll);

    unsigned length() const {
        return len;
    }

    void insert(unsigned index, int value);

    void remove(unsigned index);

    void reverse();

    virtual ~DoublyLL();
};


#endif //CPP_DOUBLYLL_H
