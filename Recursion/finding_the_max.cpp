#include <iostream>
using namespace std;

int getMax(int *arr, int n)
{
    if (n == 1)
        return arr[0];

    return max(arr[0], getMax(arr + 1, n - 1));
}

int getMin(int *arr, int n)
{
    if (n == 1)
        return arr[0];

    return min(arr[0], getMin(arr + 1, n - 1));
}

int main()
{
    int arr[] = {3, 5, 1, 6, 7, 2};
    int maxi = getMax(arr, 6);
    int mini = getMin(arr, 6);

    cout << "the maximum element is -> " << maxi << endl;
    cout << "the minimum element is -> " << mini << endl;

    return 0;
}