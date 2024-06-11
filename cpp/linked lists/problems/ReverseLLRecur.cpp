//
// Created by vivekdagar on 6/10/24.
//

#include "../types/singly/SinglyLL.h"

class Solution {
public:
    static void reverse(SinglyLL &obj, Node *q, Node *p) {
        if(p) {
            reverse(obj, p, p->next);
            p->next = q;
        } else {
            obj.setHead(q);
        }
    }
};