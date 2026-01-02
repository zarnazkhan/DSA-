#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

// Creating new node
Node* createNode(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insertBST(Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->data) {
        root->left = insertBST(root->left, value);
    }
    else if (value > root->data) {
        root->right = insertBST(root->right, value);
    }
    else {
        cout << "Duplicate value not allowed\n";
    }

    return root;
}

// Inorder Traversal
void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Preorder Traversal
void preorder(Node* root) {
    if (root == NULL) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// Postorder Traversal
void postorder(Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main() {
    Node* root = NULL;
    int choice, value;

    do {
        cout << "\n--- Binary Search Tree Menu ---\n";
        cout << "1. Insert node\n";
        cout << "2. Inorder Traversal\n";
        cout << "3. Preorder Traversal\n";
        cout << "4. Postorder Traversal\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            root = insertBST(root, value);
            break;

        case 2:
            if (root == NULL)
                cout << "Tree is empty\n";
            else {
                cout << "Inorder Traversal: ";
                inorder(root);
                cout << endl;
            }
            break;

        case 3:
            if (root == NULL)
                cout << "Tree is empty\n";
            else {
                cout << "Preorder Traversal: ";
                preorder(root);
                cout << endl;
            }
            break;

        case 4:
            if (root == NULL)
                cout << "Tree is empty\n";
            else {
                cout << "Postorder Traversal: ";
                postorder(root);
                cout << endl;
            }
            break;

        case 5:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 5);

    return 0;
}
