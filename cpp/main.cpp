#include <iostream>
#include "linked list/types/circular doubly/CDoublyLL.h"

using std::cin, std::cout;

// for remove, indices start from 1 onwards

int main() {
    std::vector<int> ob1 = {1, 2, 3, 4, 5};
    CDoublyLL obj(ob1);
    obj.insert(1, 23);
    obj.insert(6, 23);
    obj.remove(2);
    obj.remove(1);
    obj.remove(1);
    obj.remove(1);
    obj.remove(1);
    obj.remove(1);
    obj.remove(1);
    obj.remove(1);
    cout << obj.length();
}
