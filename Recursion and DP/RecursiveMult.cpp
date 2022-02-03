#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
//mult without * sign
int mult(int a, int b)
{
    int res = 0;
    //assuming a is bigger > than b. if not return alt vals
    if (a < b)
    {
        return mult(b, a);
    }

    //since a is bigger and b is smaller, we will run loop for smaller val
    for (int i = 0; i < b; i++)
    {
        res = res + a;
    }
    return res;
}

int mult_recursively(int a, int b)
{
    //base case
    if (a == 0 || b == 0)
    {
        return 0;
    }
    return b + mult_recursively(a - 1, b);
}

int mult_again(int a, int b)
{
    if (a == 0 || b == 0) //https://www.youtube.com/watch?v=b0_S0X1JwGk&ab_channel=EasyTheory
    {
        return 0;
    }

    int a1 = a >> 1; //its halves the a into nearest integer. if a=5, s=2
    int b1 = b + b;

    int res = mult_again(a1, b1);

    if (a % 2 != 0) //checking if a was odd or not
    {
        res = res + b; //if odd, add another b and then return
    }

    return res;
}

int mult_memoization_helper(int a, int b, unordered_map<int, int> &mem)
{

    //base case
    if (a == 0 || b == 0) //this will happen only if a is odd or anyone of original a or b ==0
    {

        return 0;
    }
    if (mem[a])
    {

        return mem[a];
    }

    int a1 = a >> 1;
    int b1 = b + b;
    int res = mult_memoization_helper(a1, b1, mem);

    if (a % 2 != 0) //if a is odd
    {

        res = res + b;
    }

    mem[a] = res; //storing this result with a key of a. so if another a with the same value appears, it will simply use this value and not compute further
    return mem[a];
}

void mult_memoization(int a, int b)
{
    unordered_map<int, int> mem;

    cout << mult_memoization_helper(a, b, mem);
}

void bin(unsigned n)
{
    /* step 1 */
    if (n > 1)
        bin(n / 2);

    /* step 2 */
    cout << n % 2;
}

int main()
{
    int a = 5;
    int b = 7;

    //cout << mult_recursively(a, b);

    mult_memoization(a, b);

    return 0;
}