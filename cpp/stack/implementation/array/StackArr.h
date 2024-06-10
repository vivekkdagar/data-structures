//
// Created by vivekdagar on 6/10/24.
//

#ifndef CPP_STACKARR_H
#define CPP_STACKARR_H


class StackArr {
    int* elements;
    int capacity;
    int topIndex;
public:
    explicit StackArr(int capacity);

    virtual ~StackArr();

    void push(int value);

    int pop();

    int peek();

    bool empty() const {
        return topIndex == -1;
    }
};


#endif //CPP_STACKARR_H
