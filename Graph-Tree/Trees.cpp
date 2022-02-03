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

void preOrder(Node *node)
{
    if (node == NULL)
        return;
    cout << node->data << " ";
    preOrder(node->left);
    preOrder(node->right);
}

void inOrder(Node *node)
{
    if (node == NULL)
        return;
    inOrder(node->left);
    cout << node->data << " ";
    inOrder(node->right);
}

Node *findMin(Node *root)
{
    while (root->left != NULL)
    {

        root = root->left;
    }
    return root;
}

Node *Delete(Node *root, int data)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (data < root->data)
    {
        root->left = Delete(root->left, data);
    }
    if (data > root->data)
    {
        root->right = Delete(root->right, data);
    }

    else if (root->data == data)
    {
        //0 child
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            root = NULL;
        }

        //1 child. Either left child or right child
        else if (root->left == NULL)
        {
            delete root;
            ///
        }
        else if (root->right == NULL)
        {
            delete root;
            ///
        }

        //2 children logic
        else
        {

            Node *min = root->right;
            Node *minparent;

            while (min->left != NULL)
            {
                minparent = min;
                min = min->left;
            }

            root->data = min->data;

            minparent->left = NULL;
            delete min;

            // Node *temp = findMin(root->right);
            // root->data = temp->data;
            // root->right = Delete(root->right, temp->data);        the second way to do it
        }
    }
    return root;
}

int main()
{
    Node *root = new Node(9);
    root->left = new Node(7);
    root->right = new Node(12);
    root->right->left = new Node(10);
    root->right->right = new Node(13);

    inOrder(root);

    root = Delete(root, 9);
    cout << endl;

    inOrder(root);
}