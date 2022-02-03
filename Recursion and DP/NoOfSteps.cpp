#include <iostream>
#include <map>
#include <vector>
using namespace std;

//for n number of stairs, how many ways can a child cover this if he can do 1, 2 or 3 hops

long int TripleStep_recursive(int n) //O(3^n)
{
    //base cases for 1, 2, and 3 hops

    if (n == 1)
    {
        return 1;
    }
    if (n == 2)
    {
        return 2;
    }
    if (n == 3)
    {
        return 4;
    }

    return TripleStep_recursive(n - 1) + TripleStep_recursive(n - 2) + TripleStep_recursive(n - 3);
}

int TripleStep_DP(int n)
{
    cout << "jnvken";
    //vector<int> v;

    //v[0] = 1;         flow stops after vector initialization
    // v[1] = 1;
    // v[2] = 2;
    // v[3] = 4;

    int arr[n + 1];
https: //www.geeksforgeeks.org/count-ways-reach-nth-stair-using-step-1-2-3/

    for (int i = 4; i <= n; i++)
    {
        v[i] = v[i - 1] + v[i - 2] + v[i - 3];
        cout << "unfjen";
    }
    cout << "eee";
    return 3;
}

int main()
{

    int n = 4; //1233548; //what to do for such large numbers?

    cout << TripleStep_DP(n) << endl;

    return 0;
}