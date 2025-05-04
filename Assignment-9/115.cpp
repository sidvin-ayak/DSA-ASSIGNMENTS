#include <iostream>
#include <cctype>  // For isdigit()
#include <cstdlib> // For atoi()
#include "Stack.h" // Including the stack header file

using namespace std;

string infixExpression = "";  // To store user input infix expression
string postfixExpression = ""; // To store converted postfix expression

// Function to return precedence of operators
int precedence(char op) {
    if (op == '=')
        return 1;
    else if (op == '+' || op == '-')
        return 2;
    else if (op == '*' || op == '/')
        return 3;
    return 0;
}

// Function to check if a character is an operator
bool isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '=');
}

// Function to convert infix to postfix
string infixToPostfix(string infix) {
    Stack s;
    string postfix = "";

    for (char ch : infix) {
        if (isdigit(ch)) {  
            postfix += ch;
        } else if (isOperator(ch)) {
            while (!s.isEmpty() && precedence(s.peek()) >= precedence(ch)) {
                postfix += s.pop();
            }
            s.push(ch);
        } else {
            cout << "Invalid character in infix expression.\n";
            return "";
        }
    }

    // Pop remaining operators in the stack
    while (!s.isEmpty()) {
        postfix += s.pop();
    }

    return postfix;
}

// Function to evaluate postfix expression
int evaluatePostfix(string postfix) {
    Stack s;
    for (char ch : postfix) {
        if (isdigit(ch)) {
            s.push(ch - '0');  // Convert char to int
        } else if (isOperator(ch)) {
            if (s.isEmpty()) return -1;
            int b = s.pop() - '0'; // Second operand
            if (s.isEmpty()) return -1;
            int a = s.pop() - '0'; // First operand

            switch (ch) {
                case '+': s.push(a + b + '0'); break;
                case '-': s.push(a - b + '0'); break;
                case '*': s.push(a * b + '0'); break;
                case '/': 
                    if (b == 0) {
                        cout << "Error: Division by zero.\n";
                        return -1;
                    }
                    s.push(a / b + '0'); 
                    break;
            }
        }
    }

    return s.pop() - '0';
}

int main() {
    int choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Get Infix\n";
        cout << "2. Convert Infix\n";
        cout << "3. Evaluate Postfix\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter a valid infix expression: ";
                cin >> infixExpression;
                break;

            case 2:
                if (infixExpression.empty()) {
                    cout << "Please enter an infix expression first!\n";
                } else {
                    postfixExpression = infixToPostfix(infixExpression);
                    cout << "Postfix Expression: " << postfixExpression << endl;
                }
                break;

            case 3:
                if (postfixExpression.empty()) {
                    cout << "Convert the infix expression to postfix first!\n";
                } else {
                    int result = evaluatePostfix(postfixExpression);
                    if (result != -1)
                        cout << "Result of Postfix Evaluation: " << result << endl;
                }
                break;

            case 4:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice! Please enter 1, 2, 3, or 4.\n";
        }
    } while (choice != 4);

    return 0;
}
