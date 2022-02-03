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

Node *ArrayToBST(int arr[], int start, int end)
{

    if (start > end)
    {
        return NULL;
    }
    int mid = (start + end) / 2;
    Node *root = new Node(arr[mid]);

    root->left = ArrayToBST(arr, start, mid - 1);
    root->right = ArrayToBST(arr, mid + 1, end);

    return root;
}

void preorder(Node *root)
{

    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    Node *root = ArrayToBST(arr, 0, n - 1);

    preorder(root);

    return 0;
}