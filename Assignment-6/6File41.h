#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

// Node structure for the singly linked list
struct Node {
    char data;
    Node* next;
};

// Stack class using a singly linked list
class Stack {
private:
    Node* top;
    
public:
    Stack() { top = nullptr; } // Constructor

    // Push an element onto the stack
    void push(char value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = top;
        top = newNode;
    }

    // Pop the top element
    char pop() {
        if (isEmpty()) {
            cout << "Stack underflow!\n";
            return '\0';
        }
        char value = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return value;
    }

    // Peek the top element
    char peek() {
        return (isEmpty()) ? '\0' : top->data;
    }

    // Check if the stack is empty
    bool isEmpty() {
        return top == nullptr;
    }

    // Destructor to free memory
    ~Stack() {
        while (!isEmpty()) pop();
    }
};

#endif
