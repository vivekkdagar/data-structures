//
// Created by vivek on 17-02-2023.
//

#ifndef DEQUEUE_DEQUEUE_H
#define DEQUEUE_DEQUEUE_H


#include <vector>
#include <ostream>

class DEQUEUE {
    int front;
    int rear;
    int size;
    std::vector<int> Q;
public:
    explicit DEQUEUE(int size);

    bool empty() const {
        return front == rear;
    }

    bool full() const {
        return rear == size - 1;
    }

    void enqueueRear(int x);

    int dequeueFront();

    int dequeueRear();

    friend std::ostream &operator<<(std::ostream &os, const DEQUEUE &dequeue);
};


#endif //DEQUEUE_DEQUEUE_H
