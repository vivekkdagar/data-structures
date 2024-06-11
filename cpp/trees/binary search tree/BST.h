//
// Created by vivekdagar on 6/11/24.
//

#ifndef CPP_BST_H
#define CPP_BST_H

#include <vector>
#include <queue>

struct TreeNode {
    TreeNode *left;
    TreeNode *right;
    int key;

    TreeNode(TreeNode *left, TreeNode *right, int key) : left(left), right(right), key(key) {}
};

class BST {
    TreeNode *root;
public:
    // Constructors
    explicit BST() : root(nullptr) {}
    explicit BST(const std::vector<int> &pre);          // Create using preorder traversal

    // Call the recursive functions internally, so you don't need to pass root to it everytime you call it.
    int height() { return this->height(this->root); }
    int CountLeafs() { return this->CountLeafs(this->root); }
    int CountNodes() { return this->CountNodes(this->root); }
    void PreOrder() { this->PreOrder(this->root); }
    void InOrder() { this->InOrder(this->root); }
    void PostOrder() { this->PostOrder(this->root); }

    // same with iterative traversals
    void PreOrderItr() { this->PreOrderItr(this->root); }
    void LevelOrder() { this->LevelOrder(this->root); }
    void InOrderItr() { this->InOrderItr(this->root); }
    void PostOrderItr() { this->PostOrderItr(this->root); }

    std::vector<int> toArray();

    TreeNode *remove(TreeNode *p, int key);

    // Search
    TreeNode *search(TreeNode *p, int key);
    TreeNode *searchItr(int key);

    // Insert
    void insertItr(int key);
    TreeNode *insert(TreeNode *p, int key);
    TreeNode *insert(int key);

    TreeNode *getRoot() const {
        return root;
    }

    virtual ~BST() {
        destroy(root);
    }
private:

    void destroy(TreeNode *p);
    static TreeNode *InPre(TreeNode *p);
    static TreeNode *InSucc(TreeNode *p);

    // Recursive
    int CountLeafs(TreeNode *p);
    int CountNodes(TreeNode *p);
    int height(TreeNode *p);

    // Traversals: Recursive
    void PreOrder(TreeNode *p);
    void InOrder(TreeNode *p);
    void PostOrder(TreeNode *p);

    // Iterative
    void PreOrderItr(TreeNode *p);
    static void InOrderItr(TreeNode *p);
    void PostOrderItr(TreeNode *p);
    void LevelOrder(TreeNode *p);
};


#endif //CPP_BST_H
