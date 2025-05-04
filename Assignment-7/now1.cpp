#include <iostream>
using namespace std;

#define SIZE 5

class Queue {
    int arr[SIZE], front, rear;
    
public:
    Queue() { front = rear = -1; }

    bool isFull() { return rear == SIZE - 1; }
    bool isEmpty() { return front == -1 || front > rear; }

    void enqueue(int val) {
        if (isFull()) {
            cout << "Queue Overflow!\n";
            return;
        }
        if (front == -1) front = 0;
        arr[++rear] = val;
        cout << "Enqueued: " << val << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow!\n";
            return;
        }
        cout << "Dequeued: " << arr[front++] << endl;
        if (front > rear) front = rear = -1; // Reset queue when empty
    }

    void peek() {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return;
        }
        cout << "Front element: " << arr[front] << endl;
    }
};

int main() {
    Queue q;
    int choice, value;
    
    do {
        cout << "\n1. Enqueue\n2. Dequeue\n3. Peek\n4. Exit\nChoose: ";
        cin >> choice;

        switch (choice) {
            case 1: cout << "Enter value: "; cin >> value; q.enqueue(value); break;
            case 2: q.dequeue(); break;
            case 3: q.peek(); break;
            case 4: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 4);

    return 0;
}
