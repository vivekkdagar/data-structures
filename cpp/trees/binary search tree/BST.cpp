//
// Created by vivekdagar on 6/11/24.
//

#include <algorithm>
#include <stack>
#include <iostream>
#include "BST.h"

BST::BST(const std::vector<int> &pre) {
    // Create root;
    root = new TreeNode(nullptr, nullptr, pre.front());

    TreeNode *t, *p = this->root;
    std::stack<TreeNode *> stk;

    for (int i{1}; i < pre.size(); i++) {
        if (pre.at(i) < p->key) {
            t = new TreeNode(nullptr, nullptr, pre.at(i));
            p->left = t;
            stk.push(p);
            p = t;
        } else {
            if (pre.at(i) > p->key and pre.at(i) < stk.empty() ? 32767 : stk.top()->key) {
                t = new TreeNode(nullptr, nullptr, pre.at(i));
                p->right = t;
                p = t;
            } else {
                p = stk.top();
                stk.pop();
            }
        }
    }
}

void BST::insertItr(int key) {
    TreeNode *t = this->root, *r, *p = new TreeNode(nullptr, nullptr, key);

    if (not root)
        root = p;

    while (t) {
        r = t;
        if (key == t->key)
            return;
        else if (key < t->key)
            t = t->left;
        else
            t = t->right;
    }

    if (key < r->key)
        r->left = p;
    else
        r->right = p;
}

TreeNode *BST::remove(TreeNode *p, int key) {
    TreeNode *Q;

    if (not p)
        return nullptr;

    if (not p->left and not p->right and (p->key == key)) {
        if (p == this->root)
            root = nullptr;
        delete p;
        return nullptr;
    }

    if (key < p->key)
        p->left = remove(p->left, key);
    else if (key > p->key)
        p->right = remove(p->right, key);
    else if (height(p->left) > height(p->right)) {
        Q = InPre(p->left);
        p->key = Q->key;
        p->left = remove(p->left, Q->key);
    } else {
        Q = InSucc(p->right);
        p->key = Q->key;
        p->right = remove(p->right, Q->key);
    }
    return p;
}

void BST::destroy(TreeNode *p) {
    if(p) {
        destroy(p->left);
        destroy(p->right);
        delete p;
    }
}

TreeNode *BST::InSucc(TreeNode *p) {
    while (p and p->left)
        p = p->left;
    return p;
}

TreeNode *BST::InPre(TreeNode *p) {
    while (p and p->right)
        p = p->right;
    return p;
}

int BST::CountLeafs(TreeNode *p) {
    int x, y;
    if (p) {
        x = CountLeafs(p->left);
        y = CountLeafs(p->right);
        if (not p->left and not p->right)
            return x + y + 1;
        return x + y;
    }
    return 0;
}

int BST::CountNodes(TreeNode *p) {
    if (p)
        return CountNodes(p->left) + CountNodes(p->right) + 1;          // for sum of all nodes, replace 1 with -> sum
    return 0;
}

int BST::height(TreeNode *p) {
    int x, y;
    if (not p)
        return 0;
    x = height(p->left);
    y = height(p->right);
    return std::max(x, y) + 1;
}

std::vector<int> BST::toArray() {
    std::stack<TreeNode *> stk;
    std::vector<int> s;
    TreeNode *p = this->root;
    while (p or not stk.empty()) {
        if (p) {
            stk.emplace(p);
            p = p->left;
        } else {
            p = stk.top();
            stk.pop();
            s.push_back(p->key);
            p = p->right;
        }
    }
    return s;
}

TreeNode *BST::search(TreeNode *p, int key) {
    if (p) {
        if (p->key == key)
            return p;
        else if (key < p->key)
            return search(p->left, key);
        return search(p->right, key);
    }
    return nullptr;
}

TreeNode *BST::searchItr(int key) {
    TreeNode *t = root;
    while (t) {
        if (key == t->key)
            return t;
        else if (key < t->key)
            t = t->left;
        else
            t = t->right;
    }
    return nullptr;
}

TreeNode *BST::insert(TreeNode *p, int key) {
    TreeNode *t = nullptr;
    if (not p) {
        t = new TreeNode(nullptr, nullptr, key);
        return t;
    }
    if (key < p->key) {
        p->left = insert(p->left, key);
    } else if (key > p->key) {
        p->right = insert(p->right, key);
    }
    return p;
}

static int temp{0};

TreeNode *BST::insert(int key) {
    if (temp < 1) {
        this->root = this->insert(root, key);
    }
    this->insert(root, key);
    temp++;
}

void BST::PreOrder(TreeNode *p) {
    if (p) {
        std::cout << p->key << " ";
        PreOrder(p->left);
        PreOrder(p->right);
    }
}

void BST::InOrder(TreeNode *p) {
    if (p) {
        InOrder(p->left);
        std::cout << p->key << " ";
        InOrder(p->right);
    }
}

void BST::PostOrder(TreeNode *p) {
    if (p) {
        PostOrder(p->left);
        PostOrder(p->right);
        std::cout << p->key << " ";
    }
}

void BST::PreOrderItr(TreeNode *p) {
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

void BST::InOrderItr(TreeNode *p) {
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

void BST::PostOrderItr(TreeNode *p) {
    // Method 1
    /*{ stack<long int> stk;
        long int temp;
        while (p != nullptr || ! stk.empty()){
            if (p != nullptr){
                stk.emplace((long int)p);
                p = p->lchild;
            } else {
                temp = stk.top();
                stk.pop();
                if (temp > 0){
                    stk.emplace(-temp);
                    p = ((Node*)temp)->rchild;
                } else {
                    cout << ((Node*)(-1 * temp))->data << ", " << flush;
                    p = nullptr;
                }
            }
        }
        cout << endl;
    }*/

    // Method 2
    if (not p)
        return;

    // Create 2 stacks
    std::stack<TreeNode *> stk1, stk2;
    TreeNode *t;

    // push root to first stack
    stk1.push(p);

    // while first stack is not empty
    while (not stk1.empty()) {

        // Pop the top of stk1 and push it to stk2
        t = stk1.top();
        stk1.pop();
        stk2.push(t);

        // Push left and right children of removed item to stk1
        if (t->left)
            stk1.push(t->left);
        if (t->right)
            stk2.push(t->right);
    }

    // While second stack is not empty
    while (not stk2.empty()) {
        t = stk2.top();
        stk2.pop();
        std::cout << t->key << " ";
    }
}

void BST::LevelOrder(TreeNode *p) {
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
