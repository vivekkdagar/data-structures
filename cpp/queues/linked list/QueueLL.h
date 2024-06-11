//
// Created by vivek on 17-02-2023.
//

#ifndef LINKED_LIST_QUEUE_H
#define LINKED_LIST_QUEUE_H

#include <ostream>

struct Node {
    int data;
    Node *next;

    Node(int data, Node *next) : data(data), next(next) {}

    Node() : Node(-1, nullptr) {}
};

class QueueLL {
    Node *front;
    Node *rear;
public:
    QueueLL();

    void enqueue(int x);

    bool empty() const {
        return front == nullptr;
    }

    void dequeue();

    int head();         // Return the first element

    friend std::ostream &operator<<(std::ostream &os, const QueueLL &q);

    virtual ~QueueLL();
};


#endif //LINKED_LIST_QUEUE_H
