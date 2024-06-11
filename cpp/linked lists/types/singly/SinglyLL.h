//
// Created by vivekdagar on 6/10/24.
//

#ifndef CPP_SINGLYLL_H
#define CPP_SINGLYLL_H

#include <vector>
#include <ostream>

struct Node {
    int data;
    Node *next;

    Node(int data, Node *next) : data(data), next(next) {}

    explicit Node(int data) : Node(data, nullptr) {}

    Node() : Node(0, nullptr) {}
};

class SinglyLL {
    Node *head;
public:
    explicit SinglyLL(int x) {
        head = new Node(x);
    }

    // Constructors
    explicit SinglyLL(Node *head) : head(head) {}
    explicit SinglyLL(const std::vector<int> &array);

    friend std::ostream &operator<<(std::ostream &os, const SinglyLL &ll);
    int count();
    void insert(unsigned index, int val);
    void append(int val);
    void remove(unsigned index);
    bool sorted();
    void reverse();
    void concat(Node *h2) const;
    bool hasLoop();

    // Getters and setters
    Node *getHead() const {
        return head;
    }

    void setHead(Node *h1) {
        SinglyLL::head = h1;
    }

    std::vector<int> list() {
        std::vector<int> l2;
        for (Node *t{head}; t != nullptr; t = t->next)
            l2.push_back(t->data);
        return l2;
    }

    // Recursive functions
    void display(Node *p);
    int count(Node *p);
    int max(Node *p);
    int search(Node *p, int key);

    virtual ~SinglyLL();
};


#endif //CPP_SINGLYLL_H
