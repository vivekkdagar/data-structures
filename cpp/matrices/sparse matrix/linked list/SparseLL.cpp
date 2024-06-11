//
// Created by vivek on 17-02-2023.
//

#include <iostream>
#include "SparseLL.h"

using namespace std;

SparseLL::SparseLL(int rows, int cols, int nums) : rows(rows), cols(cols), nonZeroCount(nums) {
    first = new Node;
    first->data = new Element(rows, cols, 0);
}

void SparseLL::append(int i, int j, int x) {
    Node *temp = new Node;
    temp->data = new Element(i, j, x);

    Node *last = first;
    while (last->next != nullptr)
        last = last->next;
    last->next = temp;
}

SparseLL SparseLL::operator+(SparseLL &s) {
    if (s.rows == rows && s.cols == cols) {

        auto *tr = new SparseLL(rows, cols, s.nonZeroCount + nonZeroCount);
        Node *p = first->next;
        Node *q = s.first->next;
        Node *r = tr->first;
        Node *temp;
        while (p && q) {
            temp = new Node;
            if (p->data->i < q->data->i) {
                temp->data = p->data;
                temp->next = nullptr;
                r->next = temp;
                r = r->next;
                p = p->next;
            } else if (p->data->i > q->data->i) {
                temp->data = q->data;
                temp->next = nullptr;
                r->next = temp;
                r = r->next;
                q = q->next;
            } else {
                if (p->data->j < q->data->j) {
                    temp->data = p->data;
                    temp->next = nullptr;
                    r->next = temp;
                    r = r->next;
                    p = p->next;
                } else if (p->data->j > q->data->j) {
                    temp->data = q->data;
                    temp->next = nullptr;
                    r->next = temp;
                    r = r->next;
                    q = q->next;
                } else {
                    temp->data = q->data;
                    temp->data->val += p->data->val;
                    temp->next = nullptr;
                    r->next = temp;
                    r = r->next;
                    q = q->next;
                    p = p->next;
                }
            }

        }

        if (p) {
            r->next = p;
            p = p->next;
        }
        if (q) {
            r->next = q;
            q = q->next;
        }

        return *tr;
    }
    return {0, 0, 0};
}

void SparseLL::display() {

    if (first) {
        Node *p = first->next;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (p->data->i == i && p->data->j == j) {
                    cout << p->data->val << " ";
                    if (p->next)
                        p = p->next;
                } else {
                    cout << 0 << " ";
                }
            }
            cout << endl;
        }
    }
}

Node *SparseLL::getFirst() const {
    return first;
}

SparseLL::~SparseLL() {
    auto *temp = first;
    while(temp) {
        first = first->next;
        delete temp;
        temp = first;
    }
}