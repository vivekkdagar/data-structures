//
// Created by vivekdagar on 6/10/24.
//

#ifndef CPP_CIRCULARLL_H
#define CPP_CIRCULARLL_H

#include <ostream>
#include "../singly/SinglyLL.h"

class CircularLL {
    Node *first;
public:
    explicit CircularLL(const std::vector<int>& arr);

    friend std::ostream &operator<<(std::ostream &os, const CircularLL &ll);

    void insert(unsigned short pos, int val);

    void remove(unsigned short pos);

    void print(Node *p);        // Recursive print

    Node *head() const {
        return first;
    }

    virtual ~CircularLL();
};


#endif //CPP_CIRCULARLL_H
