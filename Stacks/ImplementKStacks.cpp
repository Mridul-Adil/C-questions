#include <iostream>
#include <map>
using namespace std;

//simply divide it in k equal parts. But it isnt space efficient.
//for k =2, use a single stack and store from both ends

class kStacks
{

public:
    int *arr;
    int *top;
    int *next;

    int free = 0;
    kStacks(int n, int k)
    {
        arr = new int[n];
        top = new int[k];
        arr = new int[n];

        //initialize top
        for (auto i = 0; i < k; i++)
        {
            top[i] = -1;
        }

        //initialize next
        for (auto i = 0; i < n - 1; i++)
        {
            next[i] = i + 1;
        }
        next[n - 1] = -1;
    }

    bool isFull_stack()
    {
        return free == -1;
    }

    bool isEmpty_stack(int sn)
    {
        return top[sn] == -1;
    }

    void push_in_k(int val, int k)
    {
        if (isFull_stack())
        {
            cout << "stack is full";
        }

        int sn = k; //sn=stack number

        //push data
        int i = free;
        arr[i] = val;

        //update free
        free = next[i]; //to get the next free space

        //update next. this is tricky
        next[i] = top[sn]; //next of i index is top of the stack

        //update top
        top[sn] = i; //top of stack sn is at i;
    }

    int pop_from_k(int k)
    {
        if (isEmpty_stack(k))
        {
            cout << "stack is empty";
        }

        int sn = k;

        //return top of stack sn
        int i = top[sn];

        //update top to previous value
        top[sn] = next[i];

        //store the current free as next free space
        next[i] = free;
        free = i; //store the returned top as current free so that it can be used next.

        return arr[i];
    }
};

int main()
{
    kStacks ks(9, 3);

    ks.push_in_k(22, 1);
    ks.push_in_k(55, 0);
    ks.push_in_k(56, 0);
    ks.push_in_k(57, 0);
    ks.push_in_k(58, 0);

    ks.push_in_k(23, 1);
    ks.push_in_k(90, 2);
    ks.push_in_k(90, 2);
    ks.push_in_k(90, 2);
    ks.push_in_k(90, 2);

    cout << ks.pop_from_k(0) << endl;

    return 0;

    //https://www.geeksforgeeks.org/efficiently-implement-k-stacks-single-array/
}