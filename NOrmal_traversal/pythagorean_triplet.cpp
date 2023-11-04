#include <iostream>
#include <limits.h>
using namespace std;

// question link -> https://www.geeksforgeeks.org/problems/pythagorean-triplet3018/1

// Pythagorean triplet exists or not
bool checkTriplet(int arr[], int n)
{

    // method -> using the frequency array.

    // find the max element in the array.
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, arr[i]);
    }

    maxi = maxi * maxi;

    // creating the dynamic array of size maxi
    int *frequency = new int[maxi + 1];
    // storing the 0 to all the index of frequency array.
    for (int i = 0; i < maxi; i++)
        frequency[i] = 0;

    // now store the frequecy of array elements in the frequency array.
    for (int i = 0; i < n; i++)
    {
        frequency[arr[i] * arr[i]]++;
    }

    for (int i = 1; i <= maxi; i++)
    {
        // i -> first element of triplet

        // checking if the frequecy of the particular element is 0 in the frequency array, then simply continue.
        if (frequency[i] == 0)
            continue;

        for (int j = 1; j <= maxi; j++)
        {
            // j -> second element of triplet.

            if (frequency[j] == 0 || (i == j && frequency[j] == 1))
                continue;

            // c -> the third element of triplet
            int c = i + j;

            // index c jo hai agar, maxi wale index se hee bara hai, then wo frequency array me nhi hoga
            // thus wo element nhi ho sakta, then continue.
            if (c > maxi)
                continue;

            // but, if the frequency of the index c in the frequency array is greater than 1, then it will present in
            // frequency array.
            if (frequency[c] > 0)
            {
                free(frequency);
                return true;
            }
        }
    }

    free(frequency);
    return false;
}

int main()
{
    int arr[] = {3, 2, 4, 6, 5};
    // int arr[] = {10, 5, 19, 1, 2, 28, 9, 1, 25, 10, 1, 21, 4, 16, 29, 6, 7, 4, 16, 28, 23, 4, 2, 4};
    int size = 5;

    if (checkTriplet(arr, size))
        cout << "yes Pythagorian Triplet." << endl;
    else
        cout << "No pythagorean triplet." << endl;
    return 0;
}