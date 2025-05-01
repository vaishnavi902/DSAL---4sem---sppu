#include <iostream>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

void insert(TreeNode *&root, int val)
{
    if (root == nullptr)
    {
        root = new TreeNode(val);
        return;
    }

    if (val < root->data)
    {
        insert(root->left, val);
    }
    else
    {
        insert(root->right, val);
    }
}

int longestPath(TreeNode *root)
{
    if (root == nullptr)
        return 0;

    int leftDepth = longestPath(root->left);
    int rightDepth = longestPath(root->right);
    return 1 + (leftDepth > rightDepth ? leftDepth : rightDepth);
}

int minValue(TreeNode *root)
{
    if (root == nullptr)
    {
        cerr << "Tree is empty!" << endl;
        exit(EXIT_FAILURE);
    }

    while (root->left != nullptr)
    {
        root = root->left;
    }
    return root->data;
}

void swapChildren(TreeNode *root)
{
    if (root == nullptr)
        return;

    TreeNode *temp = root->left;
    root->left = root->right;
    root->right = temp;

    swapChildren(root->left);
    swapChildren(root->right);
}

bool search(TreeNode *root, int val)
{
    if (root == nullptr)
        return false;

    if (root->data == val)
        return true;

    if (val < root->data)
        return search(root->left, val);
    else
        return search(root->right, val);
}


void inorderTraversal(TreeNode *root)
{
    if (root == nullptr)
        return;

    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

void deleteTree(TreeNode *&root)
{
    if (root == nullptr)
        return;

    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
    root = nullptr;
}

int main()
{
    TreeNode *root = nullptr;
    int choice;
    int value;

    do
    {
        cout << "\nMenu:\n";
        cout << "1. Insert into BST\n";
        cout << "2. Find the number of nodes in the longest path from root\n";
        cout << "3. Find the minimum value in the BST\n";
        cout << "4. Swap left and right pointers (Mirror the BST)\n";
        cout << "5. Search for a value in the BST\n";
        cout << "6. Print BST (Inorder Traversal)\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            insert(root, value);
            cout << value << " inserted into BST." << endl;
            break;
        case 2:
            cout << "Number of nodes in the longest path from root: " << longestPath(root) << endl;
            break;
        case 3:
            cout << "Minimum value in the BST: " << minValue(root) << endl;
            break;
        case 4:
            swapChildren(root);
            cout << "BST after swapping left and right pointers (Mirror - Inorder Traversal): ";
            inorderTraversal(root);
            cout << endl;
            break;
        case 5:
            cout << "Enter value to search: ";
            cin >> value;
            if (search(root, value))
            {
                cout << value << " is found in the BST." << endl;
            }
            else
            {
                cout << value << " is not found in the BST." << endl;
            }
            break;
        case 6:
            cout << "BST (Inorder Traversal): ";
            inorderTraversal(root);
            cout << endl;
            break;
        case 7:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 7);

    deleteTree(root);

    return 0;
}