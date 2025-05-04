#include <iostream>
#include <stack>
using namespace std;

string processString(string input) {
    stack<char> s;
    
    for (char ch : input) {
        if (ch == '+') {
            if (!s.empty()) s.pop();
        } else {
            s.push(ch);
        }
    }
    
    string result;
    while (!s.empty()) {
        result = s.top() + result;
        s.pop();
    }
    return result;
}

int main() {
    string input;
    cout << "Enter a string: ";
    cin >> input;
    
    cout << "Processed string: " << processString(input) << endl;
    return 0;
}
