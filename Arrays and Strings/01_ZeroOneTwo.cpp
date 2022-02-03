#include <iostream>
#include <map>
using namespace std;

//Using the Dutch National Flag approach
void sort012(int arr[], int size) //since arrays are treated as pointers to the original array, int &srr[] is not needed and allowed
{

    int low = 0;
    int mid = 0;
    int high = size - 1;
    int temp;

    while (mid <= high)
    {
        switch (arr[mid])
        {
            // if mid -> 0, swap with low and increament low and mid
        case 0:

            temp = arr[low];
            arr[low] = arr[mid];
            arr[mid] = temp;

            low = low + 1;
            mid = mid + 1;
            break;

        //if mid -> 1, increament mid by one
        case 1:
            mid = mid + 1;
            break;

        // if mid -> 2, swap with high and increament mid and decrement high
        case 2:
            temp = arr[high];
            arr[high] = arr[mid];
            arr[mid] = temp;

            high = high - 1;
            break;
        }
    }
}

void printArray(int arr[], int size)
{

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{

    int arr[] = {0, 1, 0, 2, 1, 0, 1, 1, 0, 2, 1, 0, 1, 2}; //0, 1, 1, 0, 2, 1, 0, 1, 2

    int size = sizeof(arr) / sizeof(arr[0]);

    sort012(arr, size);

    printArray(arr, size);

    return 0;
}