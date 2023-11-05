#include<iostream>
#include<vector>
// max element is not found in the header file that why we include the bits/stdc++.h
#include<bits/stdc++.h>
using namespace std;

// question link -> https://leetcode.com/problems/find-the-winner-of-an-array-game/description/?envType=daily-question&envId=2023-11-05

int getWinner(vector<int>& arr, int k) {
    
// Brutforce approach -> Time complexity = O(N^2)
/*
    int n = arr.size();
    if(k >= n)
    {
        int maxi = INT_MIN;
        for(auto i:arr)
            maxi = max(maxi,i);

        return maxi;
    }   

    pair<int,int> p = {0,0};
    for(int i = 0; i<n; i++)
    {
        // if the 0th index element is greater.
        if(arr[0] > arr[1])
        {
            // checking if the element is already on the pair.
            if(p.first == arr[0])
                p.second ++;
            else 
            {
                p.first = arr[0];
                p.second = 1;
            }

            // making the right rotation
            int temp = arr[1];
            int i = 2;
            for(; i<n; i++)
            {
                arr[i-1] = arr[i];
            }
            arr[i] = temp;
        }

        // if the 1st index element is greater.
        else
        {
            // checking if the element is already on the pair.
            if(p.first == arr[1])
                p.second ++;
            else 
            {
                p.first = arr[1];
                p.second = 1;
            }

            int temp = arr[0];
            int i = 1;
            for(; i<n; i++)
            {
                arr[i-1] = arr[i];
            }
            arr[i] = temp;
        }

        // check if the p.first has won the kth round
        if(p.second == k)
            break;
    }

    return p.first;

*/
// what is wrong or extra in the brutforce approach -> right rotation.
// avoid right rotation then it will save time complexity.

    // optimal approach -> O(N)
    int n = arr.size();
    // edge cases
    if(k >= n)
        return *max_element(arr.begin(),arr.end());
    // edge cases
    if(k == 1)
        return (arr[0]> arr[1] ? arr[0]: arr[1]);

    pair<int,int> p = {arr[0],0};

    /*
    we don't need to return the array in rotated form, then why we care of rotation, simply
    do the work.
    */
    for(int i = 1; i<n; i++)
    {
        if(p.first > arr[i])
            p.second++;
        else
        {
            p.first = arr[i];
            p.second = 1;
        }

        if(p.second == k)
            break;
    }   
        return p.first;
}

int main()
{
    vector<int> nums = {3,2,1};
    int k = 10;

    int ans =  getWinner(nums,k);

    cout<<"the winner element is -> "<<ans<<endl;

    return 0;
}