#include <iostream>
#include <map>
#include <stack>
using namespace std;

class MyStack
{
    stack<int> s;

public:
    void push_in(int val)
    {
        s.push(val);
    }

    void pop_out()
    {
        cout << s.top() << " is popped" << endl;
        s.pop();
    }

    void sort_withextraspace()
    {
        stack<int> t;

        while (!s.empty())
        {
            int temp = s.top();
            s.pop();

            while (!t.empty() && temp < t.top())
            {
                int temp2 = t.top();
                t.pop();
                s.push(temp2);
            }
            t.push(temp);
        }
        while (!t.empty())
        {
            int temp2 = t.top();
            t.pop();
            s.push(temp2);
        }
    }

    void sortInsert(int val)
    {
        if (s.empty() || val < s.top())
        {
            s.push(val);
            return;
        }

        int temp2 = s.top();
        s.pop();

        sortInsert(val);

        s.push(temp2);
    }

    void sort_usingRecursion()
    {
        if (!s.empty())
        {
            int temp = s.top();
            s.pop();

            //sort the rest of the items in the stack
            sort_usingRecursion();

            sortInsert(temp);
        }
    }
};

int main()
{
    MyStack s;

    s.push_in(3);
    s.push_in(5);
    s.push_in(9);
    s.push_in(2);
    s.push_in(7);
    s.push_in(1);

    s.sort_usingRecursion();

    s.pop_out();
    s.pop_out();
    s.pop_out();
    s.pop_out();
    s.pop_out();
    s.pop_out();

    return 0;
}