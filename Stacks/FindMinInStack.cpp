#include <iostream>
#include <map>
#include <stack>
using namespace std;

//approach 1: have a int min_val and as u push elements in the stack, check for min and update it.
//drawback: cant be used after the curr min is poped from the stack as min_val will be empty

//approach 2:have a stack of min_val and update it as items are pushed in original stack, thus the stop of the min_val will the curr min.
//drawback: if another ele of curr min value is added and then poped, the curr min from the top of the min_val will als be poped and hence top will point to the next min, not the curr min

//approach 3: have a stack of min_val and if val to be pushed is less than top of min_val, push it to min_val. if its >, push the curr min again.
//drawback: push and pop will happen fine but will take O(n) extra space.

//approach 4: is discussed below. this approach is modified version of the first approach

class SpecialStack
{
public:
    stack<int> s;
    int min;

    void push_inSpecialStack(int data)
    {
        if (s.empty())
        {
            s.push(data);
            min = data;
        }

        if (data >= min)
        {
            s.push(data);
        }
        else
        {
            s.push(2 * data - min); //if something even smaller comes, store it in min and push something smaller with tags of curr min and data to be stored
            min = data;
        }
    }

    void pop_inSpecialStack()
    {
        int data = s.top();
        s.pop();

        if (data > min) //there cant be an ele equal to min.
        {
            cout << data << endl;
        }
        else
        {
            cout << min << endl;
            min = 2 * min - data;
        }
    }

    void printmin()
    {
        cout << "min val:" << min << endl;
    }
};

int main()
{
    SpecialStack s;

    s.push_inSpecialStack(3);
    s.push_inSpecialStack(5);
    s.push_inSpecialStack(2);
    s.push_inSpecialStack(7);
    s.push_inSpecialStack(1);

    s.pop_inSpecialStack();

    s.printmin();

    return 0;
}