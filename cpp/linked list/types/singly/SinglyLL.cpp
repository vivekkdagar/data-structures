//
// Created by vivekdagar on 6/10/24.
//

#include <iostream>
#include <cstdint>
#include "SinglyLL.h"

SinglyLL::SinglyLL(const std::vector<int> &array) {
    head = new Node(array[0]);
    Node *last = head, *t;

    for (int i{1}; i < array.size(); i++) {
        t = new Node(array[i]);
        last->next = t;
        last = t;
    }
}

std::ostream &operator<<(std::ostream &os, const SinglyLL &ll) {
    Node *t = ll.head;
    os << "[";
    while (t) {
        os << t->data;
        if (t->next not_eq nullptr)
            os << ", ";
        t = t->next;
    }
    os << "]";
    return os;
}

void SinglyLL::display(Node *p) {
    if (p) {
        std::cout << p->data << " ";
        display(p->next);
    }
}

int SinglyLL::count(Node *p) {
    if (p)
        return count(p->next) + 1;
    return 0;
}

int SinglyLL::count() {
    int len{0};
    for (Node *t{head}; t != nullptr; t = t->next)
        len++;
    return len;
}

int SinglyLL::max(Node *p) {
    if (not p)
        return INT32_MIN;

    int x = max(p->next);
    return x > p->data ? x : p->data;
}

int SinglyLL::search(Node *p, int key) {
    if (p) {
        if (p->data == key)
            return key;
        return search(p->next, key);
    }
    return -1;
}

void SinglyLL::insert(unsigned int index, int val) {
    if (index > count())
        throw std::out_of_range("List is full");

    if (index == 0) {
        // If head is nullptr, insert into head first, else below
        Node *t = new Node(val, head);
        head = t;
    } else if (index == count())
        append(val);
    else {
        Node *t = head;
        for (int i{0}; i < index - 1; i++)
            t = t->next;
        Node *n = new Node(val, t->next);
        t->next = n;
    }
}

void SinglyLL::append(int val) {
    // If head is nullptr, insert into it and exit, else below
    Node *last = head;
    while (last->next)
        last = last->next;
    Node *t = new Node(val);
    last->next = t;
}

void SinglyLL::remove(unsigned int index) {
    if (index > count())
        return;

    if (index == 0) {
        Node *p = head;
        head = head->next ? head->next : nullptr;
        delete p;
    } else {
        Node *p{head}, *q{nullptr};
        for (int i{0}; i < index - 1; i++) {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        delete p;
    }
}

bool SinglyLL::sorted() {
    int x = head->data;
    Node *p = head->next;
    while (p) {
        if (x > p->data)
            return false;
        x = p->data;
        p = p->next;
    }
    return true;
}

void SinglyLL::reverse() {
    Node *p = head, *q = nullptr, *r = nullptr;
    while (p) {
        // Sliding the pointers
        r = q;
        q = p;
        p = p->next;

        // Modifying the links
        q->next = r;
    }
    head = q;
}

void SinglyLL::concat(Node *h2) const {
    Node *p = this->getHead();
    while (p->next)
        p = p->next;
    p->next = h2;
}

bool SinglyLL::hasLoop() {
    Node *p, *q;
    p = q = head;
    do {
        p = p->next;
        q = q ? q->next : nullptr;
        q = q ? q->next : nullptr;
    } while (p and q);
    return p == q;
}

SinglyLL::~SinglyLL() {
    Node *p = head;
    while (p) {
        head = head->next;
        delete p;
        p = head;
    }
}
