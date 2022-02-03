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
        next = NULL;
    }
};

bool isThereLoop_hashmap(Node *head)
{
    unordered_map<Node *, int> visited;
    Node *curr = head;
    while (curr != NULL)
    {
        if (visited[curr] > 0)
        {
            return true;
        }
        visited[curr]++;
        curr = curr->next;
    }
    return false;
}

bool detectLoop(Node *head)
{
    Node *fast = head;
    Node *slow = head;

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
        {
            return true;
        }
    }
    return false;
}

//floyds cycle finding algorithm

int main()
{
    Node *first = new Node(3);
    first->next = new Node(6);
    first->next->next = new Node(9);
    first->next->next->next = new Node(15);
    first->next->next->next->next = first->next->next;

    cout << detectLoop(first) << endl;

    if (detectLoop(first))
    {
        cout << "yes";
    }
    else
    {
        cout << "no";
    }

    return 0;
}