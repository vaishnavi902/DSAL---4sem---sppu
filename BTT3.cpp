#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    bool rightThread;

    Node(int val) : data(val), left(nullptr), right(nullptr), rightThread(false) {}
};

class ThreadedBinaryTree {
private:
    Node* root;

public:
    ThreadedBinaryTree() : root(nullptr) {}

    void insert(int val) {
        Node* newNode = new Node(val);
        if (root == nullptr) {
            root = newNode;
            return;
        }

        Node* curr = root;
        while (true) {
            if (val < curr->data) {
                if (curr->left == nullptr) {
                    curr->left = newNode;
                    newNode->right = curr;
                    newNode->rightThread = true;
                    return;
                }
                curr = curr->left;
            } else {
                if (curr->rightThread || curr->right == nullptr) {
                    newNode->right = curr->right;
                    curr->right = newNode;
                    curr->rightThread = false;
                    newNode->rightThread = true;
                    return;
                }
                curr = curr->right;
            }
        }
    }

    Node* search(int val) {
        Node* curr = root;
        while (curr != nullptr) {
            if (val == curr->data) return curr;
            else if (val < curr->data) curr = curr->left;
            else if (curr->rightThread) curr = nullptr;
            else curr = curr->right;
        }
        return nullptr;
    }

    void inorderTraversal() {
        Node* curr = root;
        while (curr != nullptr) {
            while (curr->left != nullptr)
                curr = curr->left;
            std::cout << curr->data << " ";

            while (curr->rightThread) {
                curr = curr->right;
                if (curr == nullptr) return;
                std::cout << curr->data << " ";
            }
            curr = curr->right;
        }
    }
};

int main() {
    ThreadedBinaryTree tree;
    int choice;
    int value;

    do {
        cout << "\n  Menu:  \n";
        cout << "1. Insert\n";
        cout << "2. Search\n";
        cout << "3. Inorder Traversal\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                tree.insert(value);
                cout << value << " inserted successfully.\n";
                break;
            case 2:
                cout << "Enter value to search: ";
                cin >> value;
                if (tree.search(value) != nullptr)
                    cout << "Found " << value << " in the tree.\n";
                else
                    cout << value << " not found in the tree.\n";
                break;
            case 3:
                cout << "Inorder traversal: ";
                tree.inorderTraversal();
                cout << endl;
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please enter again.\n";
        }
    } while (choice != 4);

    return 0;
}