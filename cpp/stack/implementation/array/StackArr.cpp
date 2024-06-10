//
// Created by vivekdagar on 6/10/24.
//

#include <iostream>
#include "StackArr.h"

StackArr::StackArr(int capacity) : capacity(capacity) {
    topIndex = -1;
    elements = new int[capacity];
}

StackArr::~StackArr() {
    delete []elements;
}

void StackArr::push(int value) {
    if (topIndex == capacity - 1) {
        std::cerr << "Stack overflow!" << std::endl;
        return;
    }
    elements[++topIndex] = value;
}

int StackArr::pop() {
    if (topIndex == -1) {
        std::cerr << "Stack underflow!" << std::endl;
        return -1; // You might want to handle underflow condition differently
    }
    return elements[topIndex--];
}

int StackArr::peek() {
    if (topIndex == -1) {
        std::cerr << "Stack underflow!" << std::endl;
        return -1; // You might want to handle underflow condition differently
    }
    return elements[topIndex];
}
