#include <iostream>
#include <unordered_map>
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

Node *findMergePoint_naive(Node *first, Node *second) //O(mn)
{
    Node *headofSecond = second;
    while (first != NULL)
    {
        second = headofSecond;
        while (second != NULL)
        {
            if (first == second)
            {
                return first;
            }
            second = second->next;
        }
        first = first->next;
    }
    return NULL;
}

Node *findMergePoint_hash(Node *first, Node *second) //O(mlogn + nlogn)
{
    Node *curr = second;
    unordered_map<Node *, int> l;
    while (curr != NULL)
    {
        l[curr]++;
        curr = curr->next;
    }

    while (first != NULL)
    {
        if (l[first] > 0)
        {
            return first;
        }
        first = first->next;
    }
    return NULL;
}

Node *findMergePoint_usingLength(Node *first, Node *second)
{
    int first_len = 5; //a function will return this, or if provided by the interviewer, its better
    int second_len = 3;
    int diff = abs(first_len - second_len);

    if (second_len > first_len)
    {
        Node *temp = second;
        second = first; //swap so thet first is alwys longer
        first = temp;
    }

    for (int i = 0; i < diff; i++)
    {
        first = first->next;
    }

    while (first != NULL && second != NULL)
    {

        if (first == second)
        {
            return first;
        }
        first = first->next;
        second = second->next;
    }
    return NULL;
}

int main()
{
    Node *first = new Node(3);
    first->next = new Node(6);
    first->next->next = new Node(9);
    first->next->next->next = new Node(15);
    first->next->next->next->next = new Node(30);

    Node *second = new Node(10);
    second->next = first->next->next->next;

    cout << findMergePoint_usingLength(first, second)->val << endl;

    return 0;
}