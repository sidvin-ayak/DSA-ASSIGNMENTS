#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Function to check if the parentheses string is balanced
bool isBalanced(const string& str) {
    stack<char> s;
    
    for (char ch : str) {
        if (ch == '(') {
            s.push(ch);
        } else if (ch == ')') {
            if (s.empty()) return false; // More closing brackets than opening
            s.pop();
        } else {
            // Invalid character
            return false;
        }
    }

    return s.empty(); // Stack should be empty if balanced
}

int main() {
    int choice;
    string input;

    do {
        cout << "\nMenu:\n";
        cout << "1. Check Balance\n";
        cout << "2. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter a string of parentheses: ";
                cin >> input;
                
                if (isBalanced(input)) {
                    cout << "The parentheses are balanced.\n";
                } else {
                    cout << "The parentheses are NOT balanced.\n";
                }
                break;

            case 2:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice! Please enter 1 or 2.\n";
        }

    } while (choice != 2);

    return 0;
}
