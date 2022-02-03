#include <iostream>
#include <map>
#include <string>
using namespace std;

void printcompressString(string str)
{
    int count = 1;
    int strlen = str.length();
    for (int i = 0; i < strlen; i++)
    {
        cout << str[i]; //print first occurance

        while (i < strlen - 1 && str[i] == str[i + 1])
        {
            count++;
            i++;
        }
        cout << count;
        count = 1;
    }
}

int main()
{
    string str = "xxyyzv";
    printcompressString(str);
    return 0;
}