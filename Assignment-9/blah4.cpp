#include <iostream>
#include <string>
using namespace std;

class BST{
private:
    struct node{
        int data;
        node* left;
        node* right;
    };
    node *root;
    //Recursive helper functions
    node* insert(node *root,int data){
        if (root==nullptr){
            root = new node();
            root->data = data;
            root->left = root->right = nullptr;
            return root;
        }
        if (data<root->data){
            root->left = insert(root->left,data);
        }
        else if (data>root->data){
            root->right = insert(root->right,data);
        }
        return root;
    }

    void preorder(node* root){
        if (root){
            cout << root->data << " ";
            preorder(root->left);
            preorder(root->right);
        }
    }

    void inorder(node* root){
        if (root){
            inorder(root->left);
            cout << root->data << " ";
            inorder(root->right);
        }
    }

    void postorder(node* root){
        if (root){
            postorder(root->left);
            postorder(root->right);
            cout << root->data << " ";
        }
    }

    bool search(node* root,int data){
        if (root==nullptr){
            return false;
        }
        else if (root->data==data){
            return true;
        }
        return search(root->left,data) || search(root->right,data);
    }
public:
    BST(){root = nullptr;}
    void insert(int);
    void preorder();
    void inorder();
    void postorder();
    bool search(int);
    void display();
};

int main(){
    BST BST;
    char choice;
    int value;
    do{
        cout << "\nBinary BST Operations:\n";
        cout << "1. Insert\n";
        cout << "2. Preorder Traversal\n";
        cout << "3. Inorder Traversal\n";
        cout << "4. Postorder Traversal\n";
        cout << "5. Search\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case '1':
                cout << "Enter value to insert: ";
                cin >> value;
                BST.insert(value);
                break;
            case '2':
                BST.preorder();
                break;
            case '3':
                BST.inorder();
                break;
            case '4':
                BST.postorder();
                break;
            case '5':
                cout << "Enter value to search: ";
                cin >> value;
                BST.search(value);
                break;
            case '6':
                cout << "Exiting Program\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != '6');

    return 0;
}

void BST::insert(int data){
    root = insert(root,data);
}   

void BST::preorder(){
    cout<<"Preorder Tree: ";
    preorder(root);
}

void BST::inorder(){
    cout<<"Inorder Tree: ";
    inorder(root);
}

void BST::postorder(){
    cout<<"Postorder Tree: ";
    postorder(root);
}

bool BST::search(int data){
    if (search(root,data)){
        cout<<"Value "<<data<<" is present in the tree.";
    }
    else{
        cout<<"Value "<<data<<" is not present in the tree.";
    }
}