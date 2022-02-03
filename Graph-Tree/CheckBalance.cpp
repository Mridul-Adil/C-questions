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

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int height(Node *root)
{

    if (root == NULL)
    {
        return 0;
    }

    return 1 + max(height(root->left), height(root->right));
}

bool isBalanced(Node *root)
{
    if (root == NULL)
    {
        return true;
    }
    int lh;
    int rh;

    lh = height(root->left);
    rh = height(root->right);

    if (abs(lh - rh) <= 1 && isBalanced(root->left) && isBalanced(root->right))
    {
        return true;
    }

    return false;
}

bool isBalancedOpt(Node *root, int *ht)
{
    if (root == NULL)
    {
        *ht = 0;
        return true;
    }

    int lh;
    int rh;

    int l = isBalancedOpt(root->left, &lh);
    int r = isBalancedOpt(root->right, &rh);

    *ht = ((lh > rh) ? lh : rh) + 1;

    if (abs(lh - rh) <= 1 && l && r)
    {
        return true;
    }

    return false;
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(8);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(9);
    root->right->left = new Node(11);
    root->right->right = new Node(90);
    root->left->right->right = new Node(12);
    root->left->right->right->right = new Node(15);

    int ht = 0;

    if (isBalancedOpt(root, &ht))
    {
        cout << "tree is balnced!!";
    }
    else
    {
        cout << "unbalnced tree!! ";
    }

    return 0;
}
