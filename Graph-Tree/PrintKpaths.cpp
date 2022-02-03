#include <iostream>
#include <map>
#include <vector>
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

void printK(vector<int> &paths, int n)
{

    for (int i = n; i < paths.size(); i++) //print from current node to last.
    {
        cout << paths[i] << " + ";
    }
    cout << endl;
}

void printKsumPaths_Util(Node *root, vector<int> &paths, int k)
{
    //base case
    if (root == NULL)
        return;

    //enter the current node into the path
    paths.push_back(root->data);

    //calculaet for subtrees
    printKsumPaths_Util(root->left, paths, k);

    printKsumPaths_Util(root->right, paths, k);

    //main logic
    int sum = 0;
    for (int i = paths.size() - 1; i >= 0; i--)
    {
        sum = sum + paths[i];

        if (sum == k)
        {
            printK(paths, i);
        }
    }
    paths.pop_back(); //means after adding this root->data nd adding all nodes in the path,
} // we didnt get sum = k. Hence remove this crrent node

void printKsumPaths(Node *root, int k)
{

    vector<int> paths;
    printKsumPaths_Util(root, paths, k);
}

int main()
{
    Node *root = new Node(3);
    root->left = new Node(1);
    root->left->left = new Node(1);
    root->left->right = new Node(5);
    root->right = new Node(1);
    root->right->left = new Node(2);
    root->right->left->left = new Node(1);

    printKsumPaths(root, 9);

    return 0;
}