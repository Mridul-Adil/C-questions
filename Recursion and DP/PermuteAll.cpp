#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

void permute_naive(string str, int start, int end) //will also print the duplicate values
{
    //base case
    if (start == end)
    {
        cout << str << endl;
    }

    for (int i = start; i < end; i++)
    {
        //swap the function
        swap(str[i], str[0]);

        //permute using recursion
        permute_naive(str, start + 1, end);

        //backtracking
        swap(str[i], str[0]);

        // if (i < end - 1 && str[i] == str[i + 1])
        // {
        //     i++;
        // }
    }
}

void permute_unique_Util(string str, vector<int> counts, vector<char> result, int level)
{
    if (level == str.length())
    {
        //print result vector;
    }

    for (int i = 0; i < str.length(); i++)
    {
        result[level] = str[i];
        counts[i]--;
        permute_unique_Util(str, counts, result, level);
        counts[i]++;
    }
}

// void permute_unique_helper(string str, map<char, int> nmap, string result, int level) //https://www.youtube.com/watch?v=nYFd7VHKyWQ&ab_channel=TusharRoy-CodingMadeSimple
// {
//     if (level == result.length())
//     {
//         cout << result << endl;

//         return;
//     }

//     for (int i)
// }

// void permute_unique(string str, int start, int end)
// {
//     map<char, int> nmap;
//     string str2;
//     vector<int> counts;

//     for (int i = 0; i < str.length(); i++)
//     {
//         nmap[str[i]]++;
//     }

//     for (auto i : nmap)
//     {
//     }

//     permute_unique_helper(str, nmap, 0);
// }

int main()
{
    string str = "aab";
    permute_naive(str, 0, 2);

    return 0;
}