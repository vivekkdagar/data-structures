cmake_minimum_required(VERSION 3.27)
project(cpp)

set(CMAKE_CXX_STANDARD 17)

add_executable(cpp main.cpp
        "linked lists/types/singly/SinglyLL.cpp"
        "linked lists/types/singly/SinglyLL.h"
        "linked lists/types/doubly/DoublyLL.cpp"
        "linked lists/types/doubly/DoublyLL.h"
        "linked lists/types/circular/CircularLL.cpp"
        "linked lists/types/circular/CircularLL.h"
        "linked lists/types/circular doubly/CDoublyLL.cpp"
        "linked lists/types/circular doubly/CDoublyLL.h"
        "linked lists/problems/MergeTwoSortedLL.cpp"
        "linked lists/problems/ReverseLLRecur.cpp"
        "linked lists/problems/SortedLL.cpp"
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
        "polynomial/linked list/PolyLL.h"
        stack/implementation/array/StackArr.cpp
        stack/implementation/array/StackArr.h
        "stack/implementation/linked list/StackLL.cpp"
        "stack/expression eval/ExprEvaluator.cpp"
        "stack/expression eval/ExprEvaluator.h"
        heap/Heap.cpp
        heap/Heap.h
        "matrices/toeplitz matrix/Toeplitz.cpp"
        "matrices/toeplitz matrix/Toeplitz.h"
        "matrices/tridiagonal matrix/Tridiagonal.cpp"
        "matrices/tridiagonal matrix/Tridiagonal.h"
        "matrices/symmetric matrix/Symmetric.cpp"
        "matrices/symmetric matrix/Symmetric.h"
        "matrices/diagonal matrix/Diagonal.cpp"
        "matrices/diagonal matrix/Diagonal.h"
        "matrices/sparse matrix/array/SparseArr.cpp"
        "matrices/sparse matrix/array/SparseArr.h"
        "matrices/sparse matrix/linked list/SparseLL.cpp"
        "matrices/sparse matrix/linked list/SparseLL.h"
        "matrices/upper triangular matrix/UTMatrix.cpp"
        "matrices/upper triangular matrix/UTMatrix.h"
        "matrices/lower triangular matrix/LTMatrix.cpp"
        "matrices/lower triangular matrix/LTMatrix.h"
        hashing/chaining/ChainHashing.h
        hashing/chaining/ChainHashing.cpp
        "hashing/double hashing/DHtable.h"
        "hashing/double hashing/DHtable.cpp"
        hashing/probing/linear/LProbingHT.h
        hashing/probing/linear/LProbingHT.cpp
        hashing/probing/quadratic/QProbingHT.h
        hashing/probing/quadratic/QProbingHT.cpp
        "trees/avl tree/AVL.cpp"
        "trees/avl tree/AVL.h"
        "trees/binary search tree/BST.cpp"
        "trees/binary search tree/BST.h"
        "trees/binary tree/Tree.cpp"
        "trees/binary tree/Tree.h"
        "queues/two stacks/QTwoStacks.h"
        "queues/two stacks/QTwoStacks.cpp"
        "queues/array/linear/Queue.h"
        "queues/array/linear/Queue.cpp"
        queues/array/circular/Cqueuee.h
        queues/array/circular/CQueue.cpp
        queues/array/dequeue/DEQUEUE.h
        queues/array/dequeue/DEQUEUE.cpp
)
