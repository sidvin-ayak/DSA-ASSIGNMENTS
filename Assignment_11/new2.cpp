#include <iostream>
#include <list>
using namespace std;

const int SIZE = 10;
list<int> hashTable[SIZE];

int hashFunction(int key) {
    return key % SIZE;
}

void insert(int key) {
    int index = hashFunction(key);
    hashTable[index].push_back(key);
}

void search(int key) {
    int index = hashFunction(key);
    for (int item : hashTable[index]) {
        if (item == key) {
            cout << "Found in chain at index " << index << endl;
            return;
        }
    }
    cout << "Not found!" << endl;
}

void remove(int key) {
    int index = hashFunction(key);
    hashTable[index].remove(key);
    cout << "Deleted if it existed at index " << index << endl;
}

void display() {
    for (int i = 0; i < SIZE; i++) {
        cout << i << " : ";
        for (int item : hashTable[i])
            cout << item << " -> ";
        cout << "NULL\n";
    }
}

int main() {
    int choice, key;
    do {
        cout << "\n1. Insert\n2. Delete\n3. Search\n4. Display\n5. Exit\n";
        cin >> choice;
        switch (choice) {
            case 1: cout << "Enter key: "; cin >> key; insert(key); break;
            case 2: cout << "Enter key: "; cin >> key; remove(key); break;
            case 3: cout << "Enter key: "; cin >> key; search(key); break;
            case 4: display(); break;
            case 5: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 5);
    return 0;
}
