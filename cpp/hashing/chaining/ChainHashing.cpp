//
// Created by vivekdagar on 6/7/24.
//

#include "ChainHashing.h"

/* Create a hashtable which is basically a double pointer to an array of node * in heap
                                       and fill them with nullptr. * */
ChainHashing::ChainHashing() {
    HT.resize(SIZE);

    for(auto i: HT)
        i = nullptr;
}
void ChainHashing::insert(int key) {
    // Get the index
    int hashIndex = hash(key);

    // Create a node with the key
    Node *t = new Node(key);

    // If the node is nullptr
    if (not HT[hashIndex])
        HT[hashIndex] = t;
    else {

        // Temporary nodes on the first node on the hashing index
        Node *p = HT[hashIndex], *q = HT[hashIndex];

        // Find the position at which the node is to be inserted
        while (p and p->data < key) {
            q = p;
            p = p->next;
        }

        // If p hasn't moved at all, it means the position to be inserted is the first position
        if (p == HT[hashIndex]) {

            // New node points to the current first node
            t->next = HT[hashIndex];

            // Current first node is brought to the new node
            HT[hashIndex] = t;
        } else {

            // q stands on the desired node, so make t point to q's next
            t->next = q->next;

            // make q point to t
            q->next = t;
        }
    }
}

int ChainHashing::search(int key) {     // Pick the head node of the key w.r.t its hashcode and start searching.
    for (Node *p = HT[hash(key)]; p not_eq nullptr; p = p->next)
        if (p->data == key)
            return p->data;
    return -1;
}

int ChainHashing::remove(int key) {
    // Find the index of key in the linked lists
    int index = indexOf(key), t;

    // If the element is not in the hash table
    if (index == -1)
        return -1;

    index++;

    Node *head{HT[hash(key)]};
    Node *p{head};

    // First node
    if (index <= 1) {
        HT[hash(key)] = HT[hash(key)]->next ? HT[hash(key)]->next : nullptr;
        t = p->data;
        delete p;
    } else {
        Node *q{nullptr};
        for (int i{0}; i < index - 1; i++) {
            q = p;
            p = p->next;
        }
        t = p->data;
        q->next = p->next;
        delete p;
    }
    return t;
}

ChainHashing::~ChainHashing() {
    for (int i{0}; i < SIZE; i++) {
        Node *p = HT[i];
        while (p) {
            HT[i] = HT[i]->next;
            delete p;
            p = HT[i];
        }
    }
}

int ChainHashing::indexOf(int key) {
    if (search(key) not_eq -1) {
        int idx{0};
        for (Node *p = HT[hash(key)]; p not_eq nullptr; p = p->next) {
            if (p->data == key)
                return idx;
            else
                idx++;
        }
    }
    return -1;
}
