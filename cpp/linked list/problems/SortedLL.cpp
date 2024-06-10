//
// Created by vivekdagar on 6/10/24.
// Insert and remove from a sorted linked list

#include <iostream>
#include "../types/singly/SinglyLL.h"

class SortedLL {
    Node *head;
public:
    explicit SortedLL(int x) {
        head = new Node(x);
    }

    explicit SortedLL(const std::vector<int> &array) {
        head = new Node(array.at(0));
        Node *last = head, *t;

        for (int i{1}; i < array.size(); i++) {
            t = new Node(array.at(i));
            last->next = t;
            last = t;
        }
    }

    friend std::ostream &operator<<(std::ostream &os, const SortedLL &ll) {
        Node *t = ll.head;
        os << "[";
        while (t) {
            os << t->data;
            if (t->next != nullptr)
                os << ", ";
            t = t->next;
        }
        os << "]";
        return os;
    }

    void SortedInsert(int val) {
        Node *t = new Node(val);

        // Assuming head is never nullptr, if it is, do head = t, else is given below
        Node *s{head}, *q;
        while (s and s->data < val) {
            q = s;
            s = s->next;
        }

        if (s == head) {
            t->next = head;
            head = t;
        } else {
            t->next = q->next;
            q->next = t;
        }
    }

    // Remove duplicates from sorted linked list
    void SortedRemove() {
        Node *p{head};
        Node *q = p->next;      // head->next

        while (q) {
            if (p->data not_eq q->data) {
                p = q;
                q = p->next;
            } else {
                p->next = q->next;
                delete q;
                q = p->next;
            }
        }
    }

    virtual ~SortedLL() {
        Node *p = this->head;
        while (p) {
            head = head->next;
            delete p;
            p = head;
        }
    }
};