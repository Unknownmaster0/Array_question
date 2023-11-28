#include <iostream>
using namespace std;

void moveZerosEnd(int *arr, int n)
{
    // using the two pointer approach.
    int start = 0, end = 0;
    // whenever we get the zero, then increment the end. Doesn't move the start pointer b/c may be the next pointer is also the zero only,
    while (end < n)
    {
        if (arr[start] == 0)
        {
            swap(arr[start], arr[end]);
            end++;
        }
        else
            start++;

        if (start > end)
            end = start;
    }
}

void print(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int arr[5] = {3, 5, 0, 0, 4};

    moveZerosEnd(arr, 5);
    print(arr, 5);
    return 0;
}