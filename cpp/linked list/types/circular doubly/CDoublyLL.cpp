//
// Created by vivekdagar on 6/10/24.
//

#include "CDoublyLL.h"

CDoublyLL::CDoublyLL(const std::vector<int> &arr) {
    first = new Node(first, arr.at(0), first);
    Node *last = first, *t;
    for (int i{1}; i < arr.size(); i++) {
        t = new Node(last, arr.at(i), first);
        last->next = t;
        last = t;
    }
    first->prev = last;
    len = arr.size();
}

std::ostream &operator<<(std::ostream &os, const CDoublyLL &ll) {
    Node *t = ll.first;
    os << "[ ";
    do {
        os << t->data << " ";
        t = t->next;
    } while (t != ll.first);
    os << "]" << std::endl;
    return os;
}

void CDoublyLL::insert(unsigned int index, int value) {
    if (index == 0) {
        Node *t = new Node(first->prev, value, nullptr);
        first->prev->next = t;
        t->next = first;
        first->prev = t;
        first = t;
    } else {
        Node *t = new Node(nullptr, value, nullptr), *p = first;
        for (int i{0}; i < index - 1; i++)
            p = p->next;
        t->next = p->next;
        p->next = t;
        t->next->prev = t;
        t->prev = p;
    }
    len++;
}

void CDoublyLL::append(int val) {
    Node *last = first->prev;
    Node *t = new Node(last, val, first);
    last->next = t;
    last = t;
    first->prev = last;
    len++;
}

void CDoublyLL::remove(unsigned int index) {
    if (index <= length()) {
        if (index == 1) {           // Problem
            Node *p = first->next;
            if (p == first) {
                delete p;
                first = nullptr;
            } else {
                p->prev = first->prev;
                first->prev->next = p;
                delete first;
                first = p;
            }
        } else {
            Node *q = first, *p = first;
            for (int i{0}; i < index - 1; i++) {
                q = p;
                p = p->next;
            }
            q->next = p->next;
            p->next->prev = q;
            delete p;
        }
        if(len > 0)
            len--;
    }
}

void CDoublyLL::SortedInsert(int x) {
    Node *t = new Node(nullptr, x, nullptr);
    Node *p = first;
    if (length() == 1) {
        t->next = p;
        t->prev = p;
        p->prev = t;
        p->next = t;
        if (p->data > x) {
            first = t;
        }
    } else {
        Node *q = nullptr;
        while (p->data < x and p->next not_eq first) {
            q = p;
            p = p->next;
        }

        // this is the condition when the element is inserted at last
        if (p->data < x) {
            t->next = p->next;
            t->prev = p;
            p->next = t;
            t->next->prev = t;
        }

            // condition when element is inserted at the begining
        else if (!q) {
            t->next = p;
            t->prev = p->prev;
            t->prev->next = t;
            p->prev = t;
            first = t;
        }

            // condition when element is inserted any position
            // neither at last nor at begin
        else {
            t->next = p;
            t->prev = q;
            p->prev = t;
            q->next = t;
        }

    }
}