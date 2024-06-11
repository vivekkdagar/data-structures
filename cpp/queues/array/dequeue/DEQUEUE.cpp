//
// Created by vivek on 17-02-2023.
//

#include <iostream>
#include "DEQUEUE.h"

DEQUEUE::DEQUEUE(int size) : size(size) {
    Q.resize(size);
    this->front = this->rear = -1;
}

//void DEQUEUE::enqueueFront(int x) {
//    if (front == -1)
//        std::cerr << "DEQUEUE is full!\n";
//    else {
//        Q[front] = x;
//        front--;
//    }
//}

void DEQUEUE::enqueueRear(int x) {
    if(full()) {
        std::cerr << "DEQUEUE is full!\n";
    } else {
        rear++;
        this->Q[rear] = x;
    }
}

int DEQUEUE::dequeueFront() {
    int x{-1};
    if(empty()) {
        std::cerr << "DEQUEUE is empty!\n";
    } else {
        x = Q[front];
        front++;
    }
    return x;
}

int DEQUEUE::dequeueRear() {
    int x{-1};
    if(rear == -1) {
        std::cerr << "DEQUEUE is empty!\n";
    } else {
        x = Q[rear];
        rear--;
    }
    return x;
}

std::ostream &operator<<(std::ostream &os, const DEQUEUE &dequeue) {
    os << "[";
    for(int i{dequeue.front+1}; i <= dequeue.rear; i++) {
        os << dequeue.Q[i];
        if(i not_eq dequeue.rear)
            os << ", ";
    }
    os << "]\n";
    return os;
}
