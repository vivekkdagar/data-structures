//
// Created by vivekdagar on 6/11/24.
//

#include <algorithm>
#include <iostream>
#include "AVL.h"

int AVL::NodeHeight(Sprout *p) {
    int hL, hR;
    hL = p and p->left ? p->left->height : 0;
    hR = p and p->right ? p->right->height : 0;

    return std::max(hL, hR) + 1;
}

int AVL::BalanceFactor(Sprout *p) {
    int hL, hR;
    hL = p and p->left ? p->left->height : 0;
    hR = p and p->right ? p->right->height : 0;

    return hL - hR;
}

Sprout *AVL::LLRotation(Sprout *p) {
    Sprout *pl = p->left;
    Sprout *plR = pl->right;

    pl->right = p;
    p->left = plR;

    // Update height
    p->height = NodeHeight(p);
    pl->height = NodeHeight(pl);

    // Update root
    if (this->root == p)
        root = pl;

    return pl;
}

Sprout *AVL::LRRotation(Sprout *p) {
    Sprout *pl = p->left;
    Sprout *plR = pl->right;

    pl->right = plR->left;
    p->left = plR->right;

    plR->left = pl;
    plR->right = p;

    pl->height = NodeHeight(pl);
    p->height = NodeHeight(p);
    plR->height = NodeHeight(plR);

    if (p == root)
        root = plR;
    return plR;
}

Sprout *AVL::RLRotation(Sprout *p) {
    int LBF, RBF;
    Sprout *pr = p->right;
    Sprout *prl = pr->left;
    prl->height = 0;

    p->right = prl->left;
    pr->left = prl->right;
    prl->right = pr;
    prl->left = p;
    LBF = NodeHeight(p->left) + 1;
    RBF = NodeHeight(p->right) + 1;
    p->height = LBF - RBF;

    LBF = NodeHeight(pr->left) + 1;
    RBF = NodeHeight(pr->right) + 1;
    pr->height = LBF - RBF;
    if (p == root)
        root = prl;

    return prl;
}

Sprout *AVL::RRRotation(Sprout *p) {
    Sprout *pr = p->right;
    Sprout *prl = pr->left;

    pr->left = p;
    p->right = prl;

    // Update height
    p->height = NodeHeight(p);
    pr->height = NodeHeight(pr);

    // Update root
    if (root == p) {
        root = pr;
    }
    return pr;
}

Sprout *AVL::insert(Sprout *p, int key) {
    if (not p) {
        return new Sprout(nullptr, key, 1, nullptr);         // Starting height from 1 onward
    }

    if (key < p->data)
        p->left = insert(p->left, key);
    else if (key > p->data)
        p->right = insert(p->right, key);

    // Update height
    p->height = NodeHeight(p);

    switch (BalanceFactor(p)) {
        case 2: {
            if (BalanceFactor(p->left) == 1)
                return LLRotation(p);
            else if (BalanceFactor(p->left) == -1)
                return LRRotation(p);
        }
            break;
        case -2: {
            if (BalanceFactor(p->right) == 1)
                return RRRotation(p);
            else if (BalanceFactor(p->right) == -1)
                return RLRotation(p);
        }
            break;
    }

    return p;
}

void AVL::InOrder(Sprout *p) {
    if (p) {
        InOrder(p->left);
        std::cout << p->data << " ";
        InOrder(p->right);
    }
}

Sprout *AVL::InPre(Sprout *p) {
    while (p and p->right)
        p = p->right;
    return p;
}

Sprout *AVL::InSucc(Sprout *p) {
    while (p and p->left)
        p = p->left;
    return p;
}

void AVL::destroy(Sprout *p) {
    if(p) {
        destroy(p->left);
        destroy(p->right);
        delete p;
    }
}

AVL::~AVL() {
    destroy(root);
}

Sprout *AVL::remove(Sprout *p, int key) {
    if(not p)
        return nullptr;

    if(not p->left and not p->right) {
        if(p == root)
            root = nullptr;
        delete p;
        return nullptr;
    }

    if (key < p->data)
        p->left = remove(p->left, key);
    else if (key > p->data)
        p->right = remove(p->right, key);
    else {
        Sprout *q;
        if (NodeHeight(p->left) > NodeHeight(p->right)) {
            q = InPre(p->left);
            p->data = q->data;
            p->left = remove(p->left, q->data);
        } else {
            q = InSucc(p->right);
            p->data = q->data;
            p->right = remove(p->right, q->data);
        }
    }

    p->height = NodeHeight(p);


    // Balance Factor and Rotation
    switch (BalanceFactor(p)) {
        case 2: {
            switch (BalanceFactor(p->left)) {
                case 1:
                    return LLRotation(p);        // L1 Rotation
                case 0:
                    return LLRotation(p);       // L0 Rotation
                case -1:
                    return LRRotation(p);      // L-1 Rotation
            }
        }
            break;
        case -2: {
            switch (BalanceFactor(p->right)) {
                case -1:
                    return RRRotation(p);      // R-1 Rotation
                case 1:
                    return RLRotation(p);       // R1 Rotation
                case 0:
                    return RRRotation(p);       // R0 Rotation
            }
        }
            break;
    }
    return p;
}
