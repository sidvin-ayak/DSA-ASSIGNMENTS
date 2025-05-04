#include <iostream>
using namespace std;

#define SIZE 5

class CircularQueue {
    int arr[SIZE], front, rear, count;

public:
    CircularQueue() { front = rear = -1; count = 0; }

    bool isFull() { return count == SIZE; }
    bool isEmpty() { return count == 0; }

    void enqueue(int val) {
        if (isFull()) {
            cout << "Queue Overflow!\n";
            return;
        }
        rear = (rear + 1) % SIZE;
        arr[rear] = val;
        count++;
        if (front == -1) front = 0;
        cout << "Enqueued: " << val << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow!\n";
            return;
        }
        cout << "Dequeued: " << arr[front] << endl;
        front = (front + 1) % SIZE;
        count--;
        if (count == 0) front = rear = -1; // Reset queue when empty
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
    CircularQueue cq;
    int choice, value;
    
    do {
        cout << "\n1. Enqueue\n2. Dequeue\n3. Peek\n4. Exit\nChoose: ";
        cin >> choice;

        switch (choice) {
            case 1: cout << "Enter value: "; cin >> value; cq.enqueue(value); break;
            case 2: cq.dequeue(); break;
            case 3: cq.peek(); break;
            case 4: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 4);

    return 0;
}
