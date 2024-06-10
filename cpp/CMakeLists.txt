cmake_minimum_required(VERSION 3.27)
project(cpp)

set(CMAKE_CXX_STANDARD 17)

add_executable(cpp main.cpp
        "linked list/types/singly/SinglyLL.cpp"
        "linked list/types/singly/SinglyLL.h"
        "linked list/types/doubly/DoublyLL.cpp"
        "linked list/types/doubly/DoublyLL.h"
        "linked list/types/circular/CircularLL.cpp"
        "linked list/types/circular/CircularLL.h"
        "linked list/types/circular doubly/CDoublyLL.cpp"
        "linked list/types/circular doubly/CDoublyLL.h"
        "linked list/problems/MergeTwoSortedLL.cpp"
        "linked list/problems/ReverseLLRecur.cpp"
        "linked list/problems/SortedLL.cpp"
        sorting/BubbleSort.cpp
        sorting/BucketSort.cpp
        sorting/CountSort.cpp
        sorting/InsertionSort.cpp
        sorting/MergeSort.cpp
        sorting/QuickSort.cpp
        sorting/RadixSort.cpp
        sorting/SelectionSort.cpp
        sorting/ShellSort.cpp
        graph/traversal/Graph.cpp
        graph/traversal/Graph.h
        graph/kruskals.cpp
        graph/prims.cpp
        string/Anagram.cpp
        string/FindDuplicates.cpp
        string/InvertCase.cpp
        string/LexicographicalCompare.cpp
        string/Palindrome.cpp
        string/Permutation.cpp
        recursion/Fibonacci.cpp
        recursion/TaylorSeries.cpp
        recursion/Power.cpp
        recursion/SumOfN.cpp
        recursion/IndirectRecursion.cpp
        recursion/NCR.cpp
        recursion/NestedRecursion.cpp
        recursion/StaticGlobal.cpp
        recursion/TailHeadRecursion.cpp
        recursion/TowerOfHanoi.cpp
        recursion/TreeRecursion.cpp
        array/implementation/Array.h
        array/problems/RearrangeNegatives.cpp
        array/problems/ReverseAndShift.cpp
        array/set/USet.h
        array/set/USet.cpp
        "array/student challenge/1.cpp"
        "array/student challenge/2.cpp"
        "array/student challenge/3.cpp"
        "array/student challenge/4.cpp"
        "array/student challenge/5.cpp"
        polynomial/array/PolyArr.cpp
        polynomial/array/PolyArr.h
        "polynomial/linked list/PolyLL.cpp"
        "polynomial/linked list/PolyLL.h")
