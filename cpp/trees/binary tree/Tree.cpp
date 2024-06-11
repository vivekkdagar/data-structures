//
// Created by vivekdagar on 6/11/24.
//

#include <iostream>
#include <stack>
#include "Tree.h"

void Tree::sprout() {
    int x;
    TreeNode *p, *t;

    // Creating root
    std::cout << "Enter root's value: ";
    std::cin >> x;
    root = new TreeNode(nullptr, nullptr, x);

    // Pushing it in queue
    Q.emplace(root);

    // Now the repeating steps start
    while (not Q.empty()) {
        p = Q.front();
        Q.pop();

        // Ask if the left child is there, -1 is used the marker to indicate left child isn't there
        std::cout << "Enter left child of " << p->key << ": ";
        std::cin >> x;
        if (x not_eq -1) {
            t = new TreeNode(nullptr, nullptr, x);
            p->left = t;
            Q.emplace(t);
        }

        // Ask if the right child is there, same marker is used
        std::cout << "Enter right child of " << p->key << ": ";;
        std::cin >> x;
        if (x not_eq -1) {
            t = new TreeNode(nullptr, nullptr, x);
            p->right = t;
            Q.emplace(t);
        }
    }
}

bool Tree::isStrictBinary() {
    return (countLeafs() + countD2nodes() == count());
}

Tree::~Tree() {
    destroy(root);
}

bool Tree::exists(TreeNode *p, int key) {
    if (p) {
        if (p->key == key)
            return true;

        /* then recur on left subtree */
        bool res1 = exists(p->left, key);
        // node found, no need to look further
        if (res1) return true;

        /* node is not found in left,
        so recur on right subtree */
        bool res2 = exists(p->right, key);

        return res2;
    }
    return false;
}

void Tree::PreOrderItr(TreeNode *p) {
    if (not p)           // In case root is nullptr
        return;

    // Create a stack and push root to it
    std::stack<TreeNode *> stk;
    stk.push(p);

    TreeNode *t;

    // While stack is not empty,
    while (not stk.empty()) {

        //  take an item out of stack and print it
        t = stk.top();
        std::cout << t->key << " ";
        stk.pop();

        // Push right and left child to stack
        if (t->right)
            stk.push(t->right);
        if (t->left)
            stk.push(t->left);
    }

    // Method 2
    /* void Tree::iterativePreorder(Node *p) {
        stack < Node * > stk;
        while (p != nullptr || !stk.empty()) {
            if (p != nullptr) {
                std::cout << p->data << ", ";
                stk.emplace(p);
                p = p->lchild;
            } else {
                p = stk.top();
                stk.pop();
                p = p->rchild;
            }
        }
        std::cout << std::endl;
    } */
}

void Tree::InOrderItr(TreeNode *p) {
    std::stack<TreeNode *> stk;
    while (p or not stk.empty()) {
        if (p) {
            stk.emplace(p);
            p = p->left;
        } else {
            p = stk.top();
            stk.pop();
            std::cout << p->key << " ";
            p = p->right;
        }
    }
    std::cout << std::endl;
}

void Tree::LevelOrder(TreeNode *p) {
    std::queue<TreeNode *> Q;
    TreeNode *t;

    // Print root's data and put it in queue
    std::cout << p->key << " ";
    Q.emplace(p);

    // While Q is not empty, take an element out of queue
    while (not Q.empty()) {
        t = Q.front();
        Q.pop();

        // If it has a left child, print its data and put it back in queue
        if (t->left) {
            std::cout << t->left->key << " ";
            Q.emplace(t->left);
        }

        // Same for right child
        if (t->right) {
            std::cout << t->right->key << " ";
            Q.emplace(t->right);
        }
    }
}

int Tree::count(TreeNode *p) {
    if (p)
        return count(p->left) + count(p->right) + 1;
    return 0;
}

int Tree::sum(TreeNode *p) {
    if (p)
        return sum(p->left) + sum(p->right) + p->key;
    return 0;
}

int Tree::countLeafs(TreeNode *p) {
    int x, y;
    if (p) {
        x = countLeafs(p->left);
        y = countLeafs(p->right);
        if (not p->left and not p->right)
            return x + y + 1;
        return x + y;
    }
    return 0;
}

unsigned short Tree::countD2nodes(TreeNode *p) {
    int x, y;
    if (p) {
        x = countD2nodes(p->left);
        y = countD2nodes(p->right);
        if (p->left and p->right)
            return x + y + 1;
        return x + y;
    }
    return 0;
}

void Tree::destroy(TreeNode *p) {
    if (p) {
        destroy(p->left);
        destroy(p->right);
        delete p;
    }
}
