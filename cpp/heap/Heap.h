//
// Created by vivekdagar on 6/10/24.
//

#ifndef CPP_HEAP_H
#define CPP_HEAP_H


#include <vector>
#include <ostream>

class Heap {
    std::vector<int> array;
public:
    explicit Heap(const std::vector<int> &t);

    Heap() = default;

    void fix(int i);

    static int parent(int i) { return (i - 1) / 2; }

    static int left(int i) { return (2 * i) + 1; }

    static int right(int i) { return (2 * i) + 2; }

    void heapify(int A[], int n);

    void insert(int x);

    friend std::ostream &operator<<(std::ostream &os, const Heap &heap);

    int remove();
private:
    void pop(int j);
};


#endif //CPP_HEAP_H
