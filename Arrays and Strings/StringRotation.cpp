#include <iostream>
#include <map>
#include <string>
using namespace std;

bool isRotation(string str1, string str2)
{
    string temp = str1 + str1;

    if (str1.length() != str2.length())
    {
        return false;
    }

    if (temp.find(str2) != string::npos) //npos is a type of "no value found" indicator. find returns npos when no occurance is found
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{

    string str1 = "waterbottle";
    string str2 = "ttlewaterbo";

    if (isRotation(str1, str2))
    {
        cout << "yes";
    }
    else
    {
        cout << "no!";
    }

    return 0;
}