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

void printKthfromLast(Node *head, int k)
{
    Node *dummy_head = new Node(0);
    dummy_head->next = head;

    Node *fast = dummy_head;
    Node *slow = dummy_head;

    for (int i = 0; i < k; i++)
    {
        fast = fast->next;
    }

    while (fast != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }
    cout << slow->val;
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
    head->next = new Node(12);
    head->next->next = new Node(15);
    head->next->next->next = new Node(16);
    head->next->next->next->next = new Node(18);
    head->next->next->next->next->next = new Node(20);

    printList(head);

    cout << endl;
    printKthfromLast(head, 8);

    return 0;
}