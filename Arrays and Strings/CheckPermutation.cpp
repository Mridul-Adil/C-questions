#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

bool arePermutations(string str1, string str2)
{
    if (str1.length() != str2.length())
    {
        cout << "here";
        return false;
    }
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());

    for (auto i = 0; i < str1.length(); i++)
    {
        if (str1[i] != str2[i])
        {
            cout << "heree";
            return false;
        }
    }
    return true;
}

bool arePermutation_usinghash(string str1, string str2)
{
    if (str1.length() != str2.length())
    {
        return false;
    }

    unordered_map<char, int> map1;
    unordered_map<char, int> map2;

    for (int i = 0; i < str1.length(); i++)
    {
        map1[str1[i]]++;
        map2[str2[i]]++;
    }
}

int main()
{
    string str1 = "mridul";
    string str2 = "dulrem";

    if (arePermutations(str1, str2))
    {
        cout << "yes";
    }
    else
    {
        cout << "no";
    }
    return 0;
}