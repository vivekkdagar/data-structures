//
// Created by vivek on 17-02-2023.
//

#ifndef TWO_POINTERS_QUEUE_H
#define TWO_POINTERS_QUEUE_H

#include <ostream>
#include <vector>

class Queue {
    int front;
    int rear;
    int size;
    std::vector<int> A;
public:
    explicit Queue(int size);

    bool empty() const {
        return front == rear;
    }

    bool full() const {
        return this->rear == size - 1;
    }

    void enqueue(int x);

    void dequeue();

    int head();

    friend std::ostream &operator<<(std::ostream &os, const Queue &queue);

    virtual ~Queue();
};


#endif //TWO_POINTERS_QUEUE_H
