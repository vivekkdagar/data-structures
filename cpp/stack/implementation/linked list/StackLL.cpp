//
// Created by vivekdagar on 6/10/24.
//
#include <iostream>

// Node class to represent each element in the stack
class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// Stack class
class Stack {
private:
    Node* top; // Pointer to the top of the stack

public:
    Stack() {
        top = nullptr;
    }

    // Function to check if the stack is empty
    bool isEmpty() {
        return top == nullptr;
    }

    // Function to push an element onto the stack
    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
    }

    // Function to pop an element from the stack
    int pop() {
        if (isEmpty()) {
            std::cerr << "Stack is empty." << std::endl;
            return -1; // Return a default value indicating failure
        }
        int poppedValue = top->data;
        Node* temp = top;
        top = top->next;
        delete temp; // Free memory of the popped node
        return poppedValue;
    }

    // Function to peek at the top element of the stack
    int peek() {
        if (isEmpty()) {
            std::cerr << "Stack is empty." << std::endl;
            return -1; // Return a default value indicating failure
        }
        return top->data;
    }
};

//int main() {
//    Stack stack;
//
//    stack.push(5);
//    stack.push(10);
//    stack.push(15);
//
//    std::cout << "Top element of the stack: " << stack.peek() << std::endl;
//
//    std::cout << "Popping elements from the stack: ";
//    while (!stack.isEmpty()) {
//        std::cout << stack.pop() << " ";
//    }
//    std::cout << std::endl;
//
//    return 0;
//}