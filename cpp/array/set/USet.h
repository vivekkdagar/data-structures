//
// Created by vivekdagar on 6/7/24.
//

#ifndef CPP_USET_H
#define CPP_USET_H


#include <vector>
#include <ostream>

class USet {            // Unordered set
    std::vector<int> array;
public:
    explicit USet(const std::vector<int> &array);

    USet();

    void Union(USet src);

    void Intersection(USet src);

    void Difference(USet src);

    friend std::ostream &operator<<(std::ostream &os, const USet &set);
};


#endif //CPP_USET_H
