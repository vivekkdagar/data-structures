//
// Created by vivekdagar on 6/10/24.
//

#include <iostream>
#include "CircularLL.h"

CircularLL::CircularLL(const std::vector<int> &arr) {
    first = new Node(arr.at(0));
    first->next = first;
    Node *last = first, *t;
    for (int i{1}; i < arr.size(); i++) {
        t = new Node(arr.at(i), last->next);
        last->next = t;
        last = t;
    }
}

std::ostream &operator<<(std::ostream &os, const CircularLL &ll) {
    Node *p = ll.first;
    do {
        os << p->data << " ";
        p = p->next;
    } while (p != ll.first);
    return os;
}

void CircularLL::print(Node *p) {
    static int flag{0};
    if(p not_eq first or flag == 0) {
        flag = 1;
        std::cout << p->data << " ";
        print(p->next);
    }
    flag = 0;
}

void CircularLL::insert(unsigned short pos, int val) {
    if (pos not_eq 0) {
        Node *t, *p = first;
        for (int i{0}; i < pos - 1; i++)
            p = p->next;
        t = new Node(val, p->next);
        p->next = t;
    } else {
        Node *p = first;
        Node *t = new Node(val, first);
        while (p->next != first)
            p = p->next;
        p->next = t;
        first = t;
    }
}

void CircularLL::remove(unsigned short pos) {
    Node *p = first;
    if(pos == 0) {
        while(p->next not_eq first)
            p = p->next;
        if(first == p) {
            delete first;
            first = nullptr;
        } else {
            p->next = first->next;
            delete first;
            first = p->next;
        }
    } else {
        for(int i{0}; i < pos - 2; i++)
            p = p->next;
        Node *q = p->next;          // actual node that we want to delete
        p->next = q->next;
        delete q;
    }
}

CircularLL::~CircularLL() {
    Node *temp = first;
    while (temp != nullptr) {
        Node *next = temp->next;
        delete temp;
        temp = next;
        if (temp == first) break; // stop when we reach head again
    }
}
