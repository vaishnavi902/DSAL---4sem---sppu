#include <iostream>
#include <algorithm>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    int height;

    Node(int val) : data(val), left(nullptr), right(nullptr), height(1) {}
};

class AVLTree
{
private:
    Node *root;

    int height(Node *node)
    {
        if (node == nullptr)
            return 0;
        return node->height;
    }

    int balanceFactor(Node *node)
    {
        if (node == nullptr)
            return 0;
        return height(node->left) - height(node->right);
    }

    Node *rightRotate(Node *y)
    {
        Node *x = y->left;
        Node *T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = 1 + std::max(height(y->left), height(y->right));
        x->height = 1 + std::max(height(x->left), height(x->right));

        return x;
    }

    Node *leftRotate(Node *x)
    {
        Node *y = x->right;
        Node *T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = 1 + std::max(height(x->left), height(x->right));
        y->height = 1 + std::max(height(y->left), height(y->right));

        return y;
    }

    Node *insertNode(Node *node, int data)
    {
        if (node == nullptr)
            return new Node(data);

        if (data < node->data)
            node->left = insertNode(node->left, data);
        else if (data > node->data)
            node->right = insertNode(node->right, data);
        else
            return node;

        node->height = 1 + std::max(height(node->left), height(node->right));

        int balance = balanceFactor(node);

        if (balance > 1 && data < node->left->data)
            return rightRotate(node);

        if (balance < -1 && data > node->right->data)
            return leftRotate(node);

        if (balance > 1 && data > node->left->data)
        {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        if (balance < -1 && data < node->right->data)
        {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    void inorderTraversal(Node *node)
    {
        if (node == nullptr)
            return;

        inorderTraversal(node->left);
        cout << node->data << " ";
        inorderTraversal(node->right);
    }

public:
    AVLTree() : root(nullptr) {}

    void insert(int data)
    {
        root = insertNode(root, data);
    }

    void inorder()
    {
        inorderTraversal(root);
        cout <<endl;
    }
};

int main() {
    AVLTree tree;
    int choice;
    int value;

    do {
        cout << "\nMenu:\n";
        cout << "1. Insert into AVL Tree\n";
        cout << "2. Inorder Traversal\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                tree.insert(value);
                cout << value << " inserted into AVL tree.\n";
                break;
            case 2:
                cout << "Inorder traversal of the AVL tree: ";
                tree.inorder();
                cout << std::endl;
                break;
            case 3:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please enter again.\n";
        }
    } while (choice != 3);

    return 0;
}