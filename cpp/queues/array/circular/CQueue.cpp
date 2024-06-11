//
// Created by vivekdagar on 04/05/24.
//

#include <stdexcept>
#include "Cqueuee.h"

Cqueuee::Cqueuee(int size) : size(size) {
    Q = new int[size];
    front = rear = 0;
}

void Cqueuee::enqueue(int x) {
    if(full())
        throw std::runtime_error("Queue overflow!");
    rear = (rear + 1) % size;
    Q[rear] = x;
}

bool Cqueuee::full() const {
    return (rear + 1) % size == front;
}

void Cqueuee::dequeue() {
    if(empty())
        throw std::runtime_error("Queue underflow!");
    front = (front + 1) % size;
}

bool Cqueuee::empty() const {
    return front == rear and not full();
}

std::ostream &operator<<(std::ostream &os, const Cqueuee &queue) {
    if (queue.empty()) {
        os << "Queue is empty" << std::endl;
        return os;
    }

    auto ptr = &queue.Q;
    int* front_ptr = *ptr + queue.front;
    int* rear_ptr = *ptr + queue.rear;

    do {
        front_ptr = (*ptr + (front_ptr - *ptr + 1) % queue.size);
        os << *front_ptr << " ";
    } while (front_ptr != rear_ptr);

    os << std::endl;
    return os;
}
