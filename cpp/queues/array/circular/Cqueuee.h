//
// Created by vivekdagar on 04/05/24.
//

#ifndef CIRCULAR_QUEUE_H
#define CIRCULAR_QUEUE_H


#include <ostream>

class Cqueuee {
    int front;
    int rear;
    int size;
    int *Q;
public:
    explicit Cqueuee(int size);

    void enqueue(int x);

    bool full() const;

    void dequeue();

    bool empty() const;

    friend std::ostream &operator<<(std::ostream &os, const Cqueuee &queue);
};


#endif //CIRCULAR_QUEUE_H
