//
// Created by vivekdagar on 6/10/24.
//

#ifndef CPP_CDOUBLYLL_H
#define CPP_CDOUBLYLL_H

#include <vector>
#include <ostream>
#include "../doubly/DoublyLL.h"

class CDoublyLL {
    Node *first;
    int len;
public:
    explicit CDoublyLL(const std::vector<int> &arr);

    friend std::ostream &operator<<(std::ostream &os, const CDoublyLL &ll);

    void insert(unsigned index, int value);

    void append(int val);

    void remove(unsigned index);

    unsigned length() const {
        return len;
    }

    void SortedInsert(int x);
};


#endif //CPP_CDOUBLYLL_H
