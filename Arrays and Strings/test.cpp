#include <iostream>
#include <map>
#include <vector>
using namespace std;

vector<int> insertionSort(vector<int> arr)
{
    int n = arr.size();
    int key;
    vector<int> res;
    int temp;

    for (int i = 0; i < n; i++)
    {
        key = arr[i];

        while (key < arr[i])
        {
            res[i + 1] = arr[i];
            i--;
        }

        res.push_back(key);
    }

    return res;
}

int main()
{
    vector<int> arr = {3, 5, 2, 7, 5, 8};

    vector<int> result = insertionSort(arr);

    for (auto i : result)
    {
        cout << i << " ";
    }

    return 0;
}