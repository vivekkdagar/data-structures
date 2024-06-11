//
// Created by vivekdagar on 6/10/24.
//

#ifndef CPP_SPARSELL_H
#define CPP_SPARSELL_H


struct Element {
    int i{};
    int j{};
    int val{};

    Element() = default;

    Element(int i, int j, int val) : i(i), j(j), val(val) {}
};

struct Node {
    Element *data{};
    Node *next{};

    explicit Node(Element *ele) : data(ele) {
        next = nullptr;
    }

    Node() = default;
};

class SparseLL {
    int rows;
    int cols;
    int nonZeroCount;
    Node *first;
public:
    SparseLL(int rows, int cols, int nums);

    SparseLL operator+(SparseLL &s);

    void append(int i, int j, int x);

    void display();

    Node *getFirst() const;

    virtual ~SparseLL();
};


#endif //CPP_SPARSELL_H
