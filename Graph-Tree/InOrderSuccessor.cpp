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

Node *find(Node *root, int a)
{

    while (root->data != a)
    {
        if (a > root->data)
        {
            root = root->right;
        }
        else
        {
            root = root->left;
        }
    }
    return root;
}

Node *inOrderSuccessor(Node *root, int currentnode)
{
    Node *current = find(root, currentnode);

    if (current == NULL)
    {
        return NULL;
    }

    //if current node has a right subtree
    if (current->right)
    {
        Node *temp = current->right;
        while (temp->left)
        {
            temp = temp->left;
        }

        return temp;
    }

    //if no right subtree is present
    else
    {
        Node *successor = NULL;
        Node *ancestor = root;

        while (ancestor != current)
        {
            if (current->data > ancestor->data)
            {
                ancestor = ancestor->right;
            }
            else
            {
                successor = ancestor;
                ancestor = ancestor->left;
            }
        }

        return successor;
    }
}

int main()
{
    Node *root = new Node(9);
    root->left = new Node(5);
    root->right = new Node(12);
    root->left->left = new Node(3);
    root->left->right = new Node(8);
    root->right->left = new Node(11);
    root->right->right = new Node(90);
    root->right->right->right = new Node(100);

    cout << "successor of 3 is" << endl;

    Node *p = inOrderSuccessor(root, 90);
    cout << p->data;

    return 0;
}