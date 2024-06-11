//
// Created by vivek on 17-02-2023.
//

#include <iostream>
#include "Queue.h"

Queue::Queue(int size) : size(size) {
    this->front = this->rear = -1;

    // Prevent going out of bounds
    A.resize(size);
}

void Queue::enqueue(int x) {
    if (not full()) {
        this->rear++;
        this->A[this->rear] = x;
    } else {
        std::cerr << "Queue is full!\n";
    }
}

void Queue::dequeue() {
    if (not empty())
        this->front++;
    else
        std::cerr << "Queue is empty!\n";
}

int Queue::head() {         // Returns the first element if it's there
    return this->empty() ? -1 : A.at(front+1);
}

std::ostream &operator<<(std::ostream &os, const Queue &queue) {
    os << "[";
    for (int i{queue.front + 1}; i <= queue.rear; i++) {
        os << queue.A.at(i);

        // Pretty printing
        if (i not_eq queue.rear)
            os << ", ";
    }
    os << "]";
    return os;
}

Queue::~Queue() {
    A.clear();
}


