#include <iostream>
#include <stack>
using namespace std;

// Node structure for Expression Tree
struct TreeNode {
    char value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(char val) {
        value = val;
        left = right = nullptr;
    }
};

// Function to construct Expression Tree from Postfix Expression
TreeNode* constructExpressionTree(const string& postfix) {
    stack<TreeNode*> st;

    for (char ch : postfix) {
        // If operand, push it to stack
        if (isalnum(ch)) {
            st.push(new TreeNode(ch));
        } 
        // If operator, pop two nodes, make them children, and push new node
        else {
            TreeNode* newNode = new TreeNode(ch);
            newNode->right = st.top(); st.pop();
            newNode->left = st.top(); st.pop();
            st.push(newNode);
        }
    }

    return st.top(); // Root of expression tree
}

// Preorder Traversal (Root-Left-Right)
void preorder(TreeNode* root) {
    if (root) {
        cout << root->value << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

// Inorder Traversal (Left-Root-Right)
void inorder(TreeNode* root) {
    if (root) {
        inorder(root->left);
        cout << root->value << " ";
        inorder(root->right);
    }
}

// Postorder Traversal (Left-Right-Root)
void postorder(TreeNode* root) {
    if (root) {
        postorder(root->left);
        postorder(root->right);
        cout << root->value << " ";
    }
}

int main() {
    string postfix;
    int choice;
    TreeNode* root = nullptr;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Enter Postfix Expression\n";
        cout << "2. Construct Expression Tree\n";
        cout << "3. Preorder Traversal\n";
        cout << "4. Inorder Traversal\n";
        cout << "5. Postorder Traversal\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter postfix expression: ";
                cin >> postfix;
                break;
            case 2:
                root = constructExpressionTree(postfix);
                cout << "Expression Tree Constructed!\n";
                break;
            case 3:
                if (root) {
                    cout << "Preorder Traversal: ";
                    preorder(root);
                    cout << endl;
                } else {
                    cout << "Tree not constructed yet!\n";
                }
                break;
            case 4:
                if (root) {
                    cout << "Inorder Traversal: ";
                    inorder(root);
                    cout << endl;
                } else {
                    cout << "Tree not constructed yet!\n";
                }
                break;
            case 5:
                if (root) {
                    cout << "Postorder Traversal: ";
                    postorder(root);
                    cout << endl;
                } else {
                    cout << "Tree not constructed yet!\n";
                }
                break;
            case 6:
                return 0;
            default:
                cout << "Invalid choice!\n";
        }
    }
}