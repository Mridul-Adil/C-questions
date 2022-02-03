#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

bool canbePalindrome(string str)
{
    int bitvector = 0;
    int mask = 0;

    for (int i = 0; i < str.length(); i++)
    {
        int char2int = str[i] - 'a';
        mask = 1 << char2int;

        bitvector = bitvector ^ mask; //adding a chars footprint to the list(bitvector=list). If any duplicate char is added, its nullified
    }

    return (bitvector & (bitvector - 1)) == 0;
}

string reverse(string str)
{
    reverse(str.begin(), str.end());
    return str;
}

void printAllpalindromes(string str)
{
    if (!canbePalindrome(str))
    {
        cout << "cant form a palindrome";
        return;
    }

    string palin = "";

    //count frequency of chars in the string
    unordered_map<char, int> fmap;
    for (int i = 0; i < str.length(); i++)
    {
        fmap[str[i]]++;
    }

    char oddchar;

    //get half of all the chars
    string half = "";
    bool isOdd;
    for (auto i : fmap)
    {
        if (i.second % 2 == 1)
        {
            oddchar = i.first;
            isOdd = true;
        }

        half = half + string(i.second / 2, i.first); //string constructor
    }

    //take this half and the odd(if any) and add it with different permutations
    do
    {
        palin = half;
        if (isOdd)
        {
            palin = palin + oddchar;
        }
        palin = palin + reverse(half);

        cout << palin << endl;
    } while (next_permutation(half.begin(), half.end()));
}

int main()
{
    string str = "malayalam";

    printAllpalindromes(str);

        return 0;
}