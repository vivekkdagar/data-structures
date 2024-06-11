//
// Created by vivek on 17-02-2023.
//

#include <iostream>
#include "QueueLL.h"

QueueLL::QueueLL() : front(nullptr), rear(nullptr) {}

void QueueLL::enqueue(int x) {
    Node *t = new Node(x, nullptr);
    if(not t)           // Heap memory is full
        std::cerr << "QueueLL overflow!\n";
    else {
        if(not front)
            front = t;
        else
            rear->next = t;
        rear = t;
    }
}

void QueueLL::dequeue() {
    if(empty())
        std::cerr << "QueueLL underflow!\n";
    else {
        Node *p = front;
        front = front->next ? front->next : nullptr;
        delete p;
    }
}

int QueueLL::head() {
    return front == nullptr ? -1 : front->data;
}

std::ostream &operator<<(std::ostream &os, const QueueLL &q) {
    Node* p = q.front;
    os << "[";
    while (p){
        os << p->data;
        if(p->next) {
            os << ", ";
        }
        p = p->next;
    }
    os << "]\n";
    return os;
}

QueueLL::~QueueLL() {
    Node* p = front;
    while (front){
        front = front->next;
        delete p;
        p = front;
    }
}
