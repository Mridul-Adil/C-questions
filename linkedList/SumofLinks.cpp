#include <iostream>
#include <map>
using namespace std;

class Node
{
public:
    int val;
    Node *next;

    Node(int val)
    {
        this->val = val;
        next = NULL;
    }
};

void printList(Node *n)
{
    while (n != NULL)
    {
        cout << n->val << " ";
        n = n->next;
    }
}

Node *add_inorder(Node *first, Node *second)
{
    Node *head = NULL;
    Node *curr = NULL;

    int carry = 0;
    int sum = 0;

    while (first != NULL || second != NULL)
    {
        sum = carry + (first ? first->val : 0) + (second ? second->val : 0);
        carry = (sum >= 10) ? 1 : 0;
        sum = sum % 10;

        Node *temp = new Node(sum);

        if (head == NULL)
        {
            head = temp;
            curr = head;
        }
        else
        {
            curr->next = temp;
            curr = curr->next;
        }

        if (first)
        {
            first = first->next;
        }

        if (second)
        {
            second = second->next;
        }
    }
    if (carry > 0)
    {
        curr->next = new Node(carry);
    }
    return head;
}

int main()
{
    Node *first = new Node(7);
    first->next = new Node(5);
    first->next->next = new Node(9);
    first->next->next->next = new Node(4);
    first->next->next->next->next = new Node(6);

    Node *second = new Node(8);
    second->next = new Node(4);

    Node *head = add_inorder(first, second);

    printList(head);

    return 0;
}