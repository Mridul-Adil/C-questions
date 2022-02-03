#include <iostream>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

//Approach 1: nested loop O(n^2)
//Approach 2: use sorting O(nlogn) to O(n^2) depends on sorting algo: merge or quick
//Approach 3: hash map    extra space for data structure
//Approach 4: hash set    extra space for data structure
//Approach 5: bit wise    using int as a data structure of bitwise

bool isUnique_nested(string str)
{
    for (auto i = 0; i < str.length() - 1; i++)
    {
        for (auto j = i + 1; j < str.length(); j++)
        {
            if (str[i] == str[j])
            {
                return false;
            }
        }
    }
    return true;
}

bool isUnique_sort(string str)
{
    sort(str.begin(), str.end());

    for (auto i = 0; i < str.length(); i++)
    {
        if (str[i] == str[i + 1])
        {
            return false;
        }
    }
    return true;
}

bool isUnique_bitwise(string str)
{
    int check = 0;

    for (auto i = 0; i < str.length(); i++)
    {
        int char2int = str.at(i) - 'a';
        if (check & (1 << char2int))
        {
            return false;
        }

        check = check | (1 << char2int);
    }
    return true;
}

int main()
{

    string str = "Mridul";

    if (isUnique_bitwise(str))
    {
        cout << "its unique";
    }
    else
    {
        cout << "not unique";
    }

    return 0;
}