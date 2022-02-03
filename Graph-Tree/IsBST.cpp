#include <iostream>
#include <limits.h>
#include <map>
using namespace std;

class Node
{

public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
    }
};

bool isBST_Util(Node *root, int min, int max)
{
    if (root == NULL)
    {
        return true;
    }
    if (root->data < min || root->data > max)
    {
        return false;
    }

    return (isBST_Util(root->left, min, (root->data) - 1)) && (isBST_Util(root->right, (root->data) + 1, max));
}

void isBST(Node *root)
{
    if (isBST_Util(root, INT_MIN, INT_MAX))
    {
        cout << "Its a BST" << endl;
    }
    else
    {
        cout << "Not a BST" << endl;
    }
}

int main()
{
    Node *root = new Node(9);
    root->left = new Node(5);
    root->right = new Node(12);
    // root->left->left = new Node(3);
    // root->left->right = new Node(8);
    // root->right->left = new Node(11);
    // root->right->right = new Node(90);

    isBST(root);
    return 0;
}