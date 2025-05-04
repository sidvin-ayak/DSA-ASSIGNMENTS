#include <iostream>
using namespace std;

const int SIZE = 10;
int hashTable[SIZE];

void init() {
    for (int i = 0; i < SIZE; i++)
        hashTable[i] = -1;
}

int hashFunction(int key) {
    return key % SIZE;
}

void insert(int key) {
    int index = hashFunction(key);
    int i = 0;
    while (hashTable[(index + i*i) % SIZE] != -1 && i < SIZE)
        i++;
    if (i == SIZE) {
        cout << "Hash table is full!" << endl;
        return;
    }
    hashTable[(index + i*i) % SIZE] = key;
    cout << "Inserted at index " << (index + i*i) % SIZE << endl;
}

void search(int key) {
    int index = hashFunction(key);
    int i = 0;
    while (hashTable[(index + i*i) % SIZE] != -1 && i < SIZE) {
        if (hashTable[(index + i*i) % SIZE] == key) {
            cout << "Found at index " << (index + i*i) % SIZE << endl;
            return;
        }
        i++;
    }
    cout << "Not found!" << endl;
}

void remove(int key) {
    int index = hashFunction(key);
    int i = 0;
    while (hashTable[(index + i*i) % SIZE] != -1 && i < SIZE) {
        if (hashTable[(index + i*i) % SIZE] == key) {
            hashTable[(index + i*i) % SIZE] = -1;
            cout << "Deleted from index " << (index + i*i) % SIZE << endl;
            return;
        }
        i++;
    }
    cout << "Not found!" << endl;
}

void display() {
    for (int i = 0; i < SIZE; i++)
        cout << i << " : " << (hashTable[i] == -1 ? "Empty" : to_string(hashTable[i])) << endl;
}

int main() {
    init();
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
