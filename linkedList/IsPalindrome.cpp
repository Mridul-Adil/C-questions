#include <iostream>
#include <map>
#include <stack>
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

Node *reverseList(Node *head)
{
    Node *curr = head;
    Node *prev = NULL;
    Node *nxt = NULL;

    while (curr != NULL)
    { //see iteration vid here: https://www.geeksforgeeks.org/reverse-a-linked-list/
        nxt = curr->next;
        curr->next = prev;

        prev = curr;
        curr = nxt;
    }
    head = prev;
    return head;
}

bool isPalindrome(Node *head)
{
    //find middle

    Node *fast = head;
    Node *slow = head;

    while (fast->next != NULL && fast->next->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    //reverse the second half
    slow->next = reverseList(slow->next);
    slow = slow->next;

    //compare and check
    Node *curr = head;
    while (slow != NULL)
    {

        if (slow->val != curr->val)
        {
            return false;
        }
        curr = curr->next;
        slow = slow->next;
    }
    return true;
}

bool isPalin(Node *head)
{
    stack<int> s;
    Node *curr = head;
    int data;

    while (curr != NULL)
    {

        s.push(curr->val);
        curr = curr->next;
    }
    curr = head;
    while (curr != NULL)
    {
        data = s.top();
        s.pop();

        if (data != curr->val)
        {
            return false;
        }
        curr = curr->next;
    }
    return true;
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
    head->next->next->next = new Node(3);
    head->next->next->next->next = new Node(3);
    head->next->next->next->next->next = new Node(9);

    if (isPalin(head))
    {
        cout << "yes";
    }
    else
    {
        cout << "no";
    }

    //printList(head);

    return 0;
}