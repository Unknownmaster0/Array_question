#include <iostream>
#include <algorithm>
using namespace std;

// problem link -> https://www.geeksforgeeks.org/problems/minimize-the-heights3351/1

// concept -> IN copy

int getMinDiff(int arr[], int n, int k)
{

    // first we sort the array.
    sort(arr, arr + n);

    int ans = arr[n - 1] - arr[0];

    for (int j = 0; j < n - 1; j++)
    {
        // kabhi bhi minus krne pr 'k' se agar less than 0 za rha hai, then don't find max and min.
        if (arr[j + 1] - k < 0 || arr[n - 1] - k < 0)
            continue;
        int mini = min(arr[0] + k, arr[j + 1] - k);
        int maxi = max(arr[n - 1] - k, arr[j] + k);
        ans = min(ans, maxi - mini);
    }
    return ans;
}

int main()
{

    return 0;
}