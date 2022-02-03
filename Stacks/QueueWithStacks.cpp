#include <iostream>
#include <map>
#include <stack>
using namespace std;

class MyQueue
{
    stack<int> s;
    stack<int> t;

public:
    void enqueue_costly(int val)
    {
        if (s.empty())
        {
            s.push(val);
        }
        else
        {
            while (!s.empty())
            {
                int temp = s.top();
                s.pop();
                t.push(temp);
            }

            s.push(val);

            while (!t.empty())
            {
                int temp = t.top();
                t.pop();
                s.push(temp);
            }
        }
    }

    void dequeue()
    {
        cout << "poppped element:" << s.top() << endl;
        s.pop();
    }

    void enqueue(int val)
    {
        s.push(val);
    }

    void dequeue_costly()
    {
        if (!t.empty())
        {
            cout << "poppped element:" << t.top() << endl;
            t.pop();
        }
        else
        {
            while (!s.empty())
            {
                int temp = s.top();
                s.pop();
                t.push(temp);
            }
            cout << "poppped element:" << t.top() << endl;
            t.pop();
        }
    }
};

int main()
{
    MyQueue q;
    q.enqueue(8);
    q.enqueue(9);
    q.enqueue(10);
    q.enqueue(11);

    q.dequeue_costly();

    MyQueue qu;
    qu.enqueue_costly(55);
    qu.enqueue_costly(65);
    qu.enqueue_costly(75);
    qu.enqueue_costly(85);
    qu.enqueue_costly(95);

    qu.dequeue();
    qu.dequeue();
    return 0;
}