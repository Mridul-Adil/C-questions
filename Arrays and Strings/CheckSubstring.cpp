#include <iostream>
#include <map>
#include <string>
using namespace std;

bool is_Substring_naive(string str, string s)
{
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == s[0])
        {
            for (int j = 1; j < s.length(); j++)
            {
                if (str[i + j] != s[j])
                {

                    return false;
                }
            }
            return true;
        }
        if ((i + 1) - str.length() < s.length())
        {
            return false;
        }
    }
}

int main()
{
    string str = "mriduladil";
    string s = "ridua";

    if (is_Substring_naive(str, s))
    {
        cout << "yes!!!";
    }
    else
    {
        cout << "no";
    }

    return 0;
}