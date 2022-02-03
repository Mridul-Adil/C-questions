#include <iostream>
#include <map>
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

void removeDup(Node *head) //O(n^2)
{
    Node *ptr1;
    Node *ptr2;
    Node *dup;

    ptr2 = head;

    while (ptr2 != NULL && ptr2->next != NULL)
    {
        ptr1 = ptr2;
        while (ptr1->next != NULL)
        {
            if (ptr2->val == ptr1->next->val)
            {
                dup = ptr1->next;
                ptr1->next = ptr1->next->next;
                delete (dup);
            }
            else
            {
                ptr1 = ptr1->next;
            }
        }
        ptr2 = ptr2->next;
    }
}

void remDuplicate(Node *head) //O(n)
{
    //this uses hashmaps
    unordered_map<int, int> umap;

    Node *curr = head;
    Node *prev = NULL;
    Node *dup;
    while (curr != NULL)
    {
        if (umap[curr->val] > 0)
        {
            prev->next = curr->next;
            dup = curr;
            delete (dup);
        }
        else
        {
            umap[curr->val]++;
            prev = curr;
        }

        curr = curr->next;
    }
    // for (auto itr = umap.begin(); itr != umap.end(); itr++)
    // {
    //     // itr works as a pointer to pair<string, double>
    //     // type itr->first stores the key part  and
    //     // itr->second stroes the value part
    //     cout << itr->first << "  " << itr->second << endl;
    // }
}

int main()
{
    Node *head = new Node(9);
    head->next = new Node(12);
    head->next->next = new Node(15);
    head->next->next->next = new Node(9);
    head->next->next->next->next = new Node(10);
    head->next->next->next->next->next = new Node(10);

    printList(head);

    remDuplicate(head);
    cout << endl;

    printList(head);
}