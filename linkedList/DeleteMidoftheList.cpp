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

void deleteMid(Node *head)
{
    if (head == NULL)
    {
        cout << "null value: no data found";
    }

    Node *fast, *slow, *prev;

    fast = head;
    slow = head;

    while (fast != NULL && fast->next->next != NULL) //for odd and even number of nodes
    {

        fast = fast->next->next;
        prev = slow;
        slow = slow->next;
    }

    prev->next = slow->next;
    delete (slow);
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

    //printList(head);

    deleteMid(head);

    printList(head);

    return 0;
}