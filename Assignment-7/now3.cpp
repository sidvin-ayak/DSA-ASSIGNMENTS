#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class LinkedQueue {
    Node *front, *rear;

public:
    LinkedQueue() { front = rear = nullptr; }

    bool isEmpty() { return front == nullptr; }

    void enqueue(int val) {
        Node* newNode = new Node(val);
        if (isEmpty()) front = rear = newNode;
        else {
            rear->next = newNode;
            rear = newNode;
        }
        cout << "Enqueued: " << val << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow!\n";
            return;
        }
        Node* temp = front;
        cout << "Dequeued: " << front->data << endl;
        front = front->next;
        delete temp;
        if (!front) rear = nullptr; // Reset queue when empty
    }

    void peek() {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return;
        }
        cout << "Front element: " << front->data << endl;
    }
};

int main() {
    LinkedQueue lq;
    int choice, value;
    
    do {
        cout << "\n1. Enqueue\n2. Dequeue\n3. Peek\n4. Exit\nChoose: ";
        cin >> choice;

        switch (choice) {
            case 1: cout << "Enter value: "; cin >> value; lq.enqueue(value); break;
            case 2: lq.dequeue(); break;
            case 3: lq.peek(); break;
            case 4: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 4);

    return 0;
}
