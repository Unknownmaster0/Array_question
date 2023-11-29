/* question link -> https://practice.geeksforgeeks.org/problems/rearrange-an-array-with-o1-extra-space3142/1

Given an array arr[] of size N where every element is in the range from 0 to n-1. Rearrange the given array so that the transformed array arrT[i] becomes arr[arr[i]].

NOTE: arr and arrT are both same variables, representing the array before and after transformation respectively.
*/

/*
Input
N = 2
arr[] = {1,0}
Output: 0 1

Input:
N = 5
arr[] = {4,0,2,1,3}
Output: 3 4 2 0 1*/

void arrange(long long arr[], int n)
{

    for (int i = 0; i < n; i++)
    {
        arr[i] = arr[i] + (arr[arr[i]] % n) * n;
    }
    for (int i = 0; i < n; i++)
    {
        arr[i] = arr[i] / n;
    }
    return;
}