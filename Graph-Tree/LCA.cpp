#include <iostream>
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
        left = NULL;
        right = NULL;
    }
};

Node *LCA_BT(Node *root, int p, int q)
{
    if (root == NULL)
    {
        return NULL;
    }
    if ((root->data == p) || (root->data == q))
    {
        return root; //that means one of p or q is the ancstor
    }

    Node *l = LCA_BT(root->left, p, q);
    Node *r = LCA_BT(root->right, p, q);

    if (l && r)
    {
        return root;
    }

    return (l != NULL) ? l : r;
}

Node *LCA_BST(Node *root, int p, int q)
{

    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == p || root->data == q)
    {
        return root;
    }
    if (p > root->data && q > root->data)
    {
        return LCA_BST(root->right, p, q);
    }
    else if (p < root->data && q < root->data)
    {
        return LCA_BST(root->left, p, q);
    }

    return root;
}

int main()
{
    Node *root = new Node(9);
    root->left = new Node(7);
    root->right = new Node(12);
    root->right->right = new Node(16);
    root->left->left = new Node(3);

    cout << LCA_BT(root, 12, 7)->data << endl;

    return 0;
}