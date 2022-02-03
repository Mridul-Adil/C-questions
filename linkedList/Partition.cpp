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

Node *partitionByp(Node *head, int p)
{
    if (head == NULL)
    {
        return NULL;
    }

    Node *curr = head;
    Node *tail = head;
    Node *nxt_ptr;

    while (curr != NULL)
    {
        nxt_ptr = curr->next;
        if (curr->val < p)
        {
            curr->next = head;
            head = curr;
        }
        else
        {
            tail->next = curr;
            tail = curr;
        }
        curr = nxt_ptr;
    }
    tail->next = NULL;

    return head;
}

void printList(Node *n)
{
    while (n != NULL)
    {
        cout << n->val << " ";
        n = n->next;
    }
}

int main()
{
    Node *head = new Node(9);
    head->next = new Node(3);
    head->next->next = new Node(6);
    head->next->next->next = new Node(18);
    head->next->next->next->next = new Node(2);
    head->next->next->next->next->next = new Node(20);

    head = partitionByp(head, 5);

    printList(head);

    return 0;
}