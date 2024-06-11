//
// Created by vivekdagar on 6/11/24.
//

#ifndef CPP_TREE_H
#define CPP_TREE_H
#include "../binary search tree/BST.h"

class Tree {
    TreeNode *root;
public:
    Tree() : root(nullptr) {}

    void sprout();          // Make the tree grow

    // Traversals
    void PreOrderItr() { this->PreOrderItr(this->root); }
    void LevelOrder() { this->LevelOrder(this->root); }
    void InOrderItr() { this->InOrderItr(this->root); }

    int count() { return this->count(this->root); }
    int countLeafs() { return this->countLeafs(this->root); }
    unsigned short countD2nodes() { return this->countD2nodes(this->root); }
    bool exists(int key) { return this->exists(this->root, key); }

    bool isStrictBinary();

    virtual ~Tree();
private:
    std::queue<TreeNode *> Q;
    bool exists(TreeNode *p, int key);

    // Traversals
    void PreOrderItr(TreeNode *p);
    void InOrderItr(TreeNode *p);
    void LevelOrder(TreeNode *p);

    int count(TreeNode *p);
    int sum(TreeNode *p);
    int countLeafs(TreeNode *p);

    void destroy(TreeNode *p);

    unsigned short countD2nodes(TreeNode *p);
};


#endif //CPP_TREE_H
