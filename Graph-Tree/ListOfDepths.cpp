#include <iostream>
#include <map>
#include <queue>
using namespace std;

class Node
{

public:
    int data;
    Node *left;
    Node *right;
    Node *next;

    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
        next = NULL;
    }
};

//Linking using Level Order Traversal(LOT)------------------------------------------------------------------!

void link_LOT(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {

        Node *p = q.front();
        q.pop();

        if (p != NULL)
        {
            p->next = q.front();

            if (p->left)
            {
                q.push(p->left);
            }

            if (p->right)
            {
                q.push(p->right);
            }
        }
        else if (!q.empty())
        {
            q.push(NULL);
        }
    }
}

//linking nodes at each levels using POT(ore order traversal)----------------------------------------------------!

void Link(Node *root)
{

    if (!root)
    {
        return;
    }
    if (root->left)
    {
        root->left->next = root->right;
    }
    if (root->right)
    {
        root->right->next = (root->next) ? root->next->left : NULL;
    }

    Link(root->left);
    Link(root->right);
}

void Link_POT(Node *root)
{
    Node *p = root;
    p->next = NULL;

    Link(p);
}

void printLink(Node *root)
{
    Node *p = root;

    if (p == NULL)
    {
        return;
    }

    while (p != NULL)
    {
        cout << p->data << "->";
        p = p->next;
    }
    cout << "Null" << endl;
    printLink(root->left);
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

    link_LOT(root);
    //Link_POT(root);
    printLink(root);

    return 0;
}