#include <iostream>
#include <map>
#include <vector>
using namespace std;

//Aprroach 1: linear search consumes O(n);
//Appproach 2: binary search O(logn);
//Appraoch 3: if dups are present

int magicIndex(vector<int> arr, int start, int end) //O(logn)
{
    if (end >= start)
    {
        int midindex = (start + end) / 2;

        if (arr[midindex] == midindex)
        {

            return midindex;
        }

        if (midindex > arr[midindex])
        {

            return magicIndex(arr, midindex + 1, end);
        }
        else if (midindex < arr[midindex])
        {
            cout << "c ";
            return magicIndex(arr, start, midindex - 1);
        }
    }

    return -1;
}

int min(int a, int b)
{
    return (a > b) ? b : a;
}

int magicIndex_withDups(vector<int> arr, int start, int end) //O(logn)
{
    int midindex = (start + end) / 2;

    if (midindex == arr[midindex])
    {
        return midindex;
    }

    if (midindex > arr[midindex])
    {
        int start = min(midindex, arr[midindex]);
        return magicIndex_withDups(arr, start, end);
    }
    if (midindex < arr[midindex])
    {
        int end = min(midindex, arr[midindex]);
        return magicIndex_withDups(arr, start, end);
    }
}

int main()
{
    vector<int> arr = {-1, 0, 1, 3, 7};
    int n = arr.size();

    //cout << magicIndex(arr, 0, n - 1);

    vector<int> arr2 = {-10, -5, 2, 2, 2, 3, 4, 7, 9, 12, 13};
    int n2 = arr2.size();

    cout << magicIndex_withDups(arr2, 0, n2 - 1);

    return 0;
}