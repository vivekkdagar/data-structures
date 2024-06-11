//
// Created by vivekdagar on 6/11/24.
//

#ifndef CPP_AVL_H
#define CPP_AVL_H

struct Sprout {
    Sprout *left;
    int data;
    int height;
    Sprout *right;

    Sprout(Sprout *left, int data, int height, Sprout *right) : left(left), data(data), height(height), right(right) {}
};

class AVL {
    Sprout *root;
public:
    AVL() : root(nullptr) {}

    Sprout *insert(Sprout *p, int key);
    Sprout *remove(Sprout *p, int key);

    void InOrder() { this->InOrder(this->root); }

    virtual ~AVL();

private:
    static int NodeHeight(Sprout *p);
    static int BalanceFactor(Sprout *p);
    static Sprout *InPre(Sprout *p);
    static Sprout *InSucc(Sprout *p);

    void InOrder(Sprout *p);

    // Rotations
    Sprout *LLRotation(Sprout *p);
    Sprout *LRRotation(Sprout *p);
    Sprout *RLRotation(Sprout *p);
    Sprout *RRRotation(Sprout *p);

    void destroy(Sprout *p);
};


#endif //CPP_AVL_H
