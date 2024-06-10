//
// Created by vivekdagar on 6/10/24.
//

#include "DoublyLL.h"

DoublyLL::DoublyLL(const std::vector<int> &n) {
    first = new Node(nullptr, n[0], nullptr);
    for(int i{1}; i < n.size(); i++)
        insert(i, n[i]);
}

std::ostream &operator<<(std::ostream &os, const DoublyLL &ll) {
    Node *current = ll.first;
    while (current != nullptr) {
        os << current->data << " ";
        current = current->next;
    }
    os << std::endl;
    return os;
}

void DoublyLL::insert(unsigned int index, int value) {
    Node *t;
    if (index == 0) {
        t = new Node(nullptr, value, first);
        first->prev = t;
        first = t;
    } else if (index <= this->length()) {
        Node *p = this->first;
        for (int i{0}; i < index - 1; i++)
            p = p->next;
        t = new Node(p, value, p->next);
        if (p->next)
            p->next->prev = t;
        p->next = t;
    } else {
        return;
    }
    len++;
}

void DoublyLL::remove(unsigned int index) {
    if (index <= this->length() and first) {
        Node *p = first;
        if (index == 1) {
            first = first->next;
            if (first)
                first->prev = nullptr;
        } else {
            for (int i{0}; i < index - 1; i++)
                p = p->next;
            p->prev->next = p->next;
            if (p->next)
                p->next->prev = p->prev;
        }
        delete p;
        len--;
        if(len < 0)
            len = 0;
    } else {
        std::cerr << "Error\n";
    }
}

void DoublyLL::reverse() {
    Node *p = first, *temp;
    while (p->next) {
        temp = p->next;         // store p's next
        p->next = p->prev;          // make p next point to p prev, this means make the node point backwards
        p->prev = temp;         // make backwards point to next
        p = p->prev;            // move using prev
        if (not p->next and p) {
            p->next = p->prev;
            p->prev = nullptr;
            first = p;
            break;
        }
    }
}

DoublyLL::~DoublyLL() {
    Node *p = first;
    while (first) {
        first = first->next;
        delete p;
        p = first;
    }
}
