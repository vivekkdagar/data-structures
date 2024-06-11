//
// Created by vivekdagar on 6/10/24.
//
//
// Created by vivekdagar on 6/7/24.
//
#include "../types/singly/SinglyLL.h"

class Solution {
    SinglyLL obj;
public:
    explicit Solution(const SinglyLL &obj) : obj(obj) {}

    SinglyLL merge(const SinglyLL &sec) {
        // This -1 is just because of constructor
        SinglyLL third(-1);

        Node *head = obj.getHead();
        Node *second = sec.getHead();

        while (head and second) {
            if (head->data < second->data) {
                third.append(head->data);
                head = head->next;
            } else {
                third.append(second->data);
                second = second->next;
            }
        }

        if (head)
            third.append(head->data);
        else if (second)
            third.append(second->data);

        third.remove(0);

        return third;
    }
};