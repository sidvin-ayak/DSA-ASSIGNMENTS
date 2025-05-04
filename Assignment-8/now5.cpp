#include <iostream>
using namespace std;

// Definition of a Tree Node
class TreeNode {
public:
    char data;
    TreeNode *left, *right;

    TreeNode(char value) {
        data = value;
        left = right = nullptr;
    }
};

class BinaryTree {
private:
    TreeNode* root;

    // Helper function for insertion (recursive)
    TreeNode* insert(TreeNode* node, char value) {
        if (!node) return new TreeNode(value);

        char choice;
        cout << "Insert " << value << " to (L)eft or (R)ight of " << node->data << "? ";
        cin >> choice;

        if (choice == 'L' || choice == 'l')
            node->left = insert(node->left, value);
        else
            node->right = insert(node->right, value);

        return node;
    }

    // Helper function for Preorder traversal
    void preorder(TreeNode* node) {
        if (!node) return;
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }

    // Helper function for Inorder traversal
    void inorder(TreeNode* node) {
        if (!node) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    // Helper function for Postorder traversal
    void postorder(TreeNode* node) {
        if (!node) return;
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }

    // Helper function for searching
    bool search(TreeNode* node, char key) {
        if (!node) return false;
        if (node->data == key) return true;
        return search(node->left, key) || search(node->right, key);
    }

public:
    BinaryTree() { root = nullptr; }

    void insert(char value) {
        if (!root) root = new TreeNode(value);
        else root = insert(root, value);
    }

    void preorder() {
        cout << "Preorder Traversal: ";
        preorder(root);
        cout << endl;
    }

    void inorder() {
        cout << "Inorder Traversal: ";
        inorder(root);
        cout << endl;
    }

    void postorder() {
        cout << "Postorder Traversal: ";
        postorder(root);
        cout << endl;
    }

    void search(char key) {
        if (search(root, key))
            cout << "Element " << key << " found in the tree.\n";
        else
            cout << "Element " << key << " not found in the tree.\n";
    }
};

// Menu-driven program
int main() {
    BinaryTree tree;
    int choice;
    char value;

    do {
        cout << "\n1. Insert\n2. Preorder\n3. Inorder\n4. Postorder\n5. Search\n6. Exit\nChoose: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter character to insert: ";
                cin >> value;
                tree.insert(value);
                break;
            case 2:
                tree.preorder();
                break;
            case 3:
                tree.inorder();
                break;
            case 4:
                tree.postorder();
                break;
            case 5:
                cout << "Enter character to search: ";
                cin >> value;
                tree.search(value);
                break;
            case 6:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 6);

    return 0;
}
