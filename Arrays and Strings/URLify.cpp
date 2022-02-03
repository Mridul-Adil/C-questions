#include <iostream>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

void replaceWhites(string str, int truelength)
{
    int whitespaces = 0;
    for (int i = 0; i < truelength; i++)
    {
        if (str[i] == ' ')
        {
            whitespaces++;
        }
    }

    //set index
    int index = truelength + whitespaces * 2;
    if (truelength < str.length())
    {
        str[index] = '\0';
    }

    for (int i = truelength - 1; i >= 0; i--)
    {
        if (str[i] == ' ')
        {
            str[index - 1] = '0';
            str[index - 2] = '2';
            str[index - 3] = '%';
            index = index - 3;
        }
        else
        {
            str[index - 1] = str[i]; //setting it at the last
            index--;
        }
    }
    cout << str << endl;
}

int main()
{
    string str = "mridul adil amazonian         ";
    replaceWhites(str, 21);

    return 0;
}