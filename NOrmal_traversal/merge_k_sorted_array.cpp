#include <bits/stdc++.h>
#include<iostream>
using namespace std;

vector<int> mergeKSortedArrays(vector<vector<int>>&arr, int k)
{
    // Bruforce ->
    /* // Time complexity -> O(N * log N)  Space -> O(N*k)
    make a vector and simply push all the element in it. 
    and finally sort the vector

    vector<int>ans;
    for(int i = 0; i<k; i++)
    {
        for(int j = 0; j<arr[i].size(); j++)
        {
            ans.push_back(arr[i][j]);
        }
    }

    sort(ans.begin(),ans.end());

    return ans;
    */

    // Optimal -> 
    /* // Time complexity -> O(k * log N)  Space -> O(N*k)
    use the merge two sorted array technique to finally push all the array in one
    single array in sorted order */

    // Better
    /* // Time complexity -> O(k * N)  Space -> O(N*k)
    priority_queue<int,vector<int>,greater<int>>q;
    for(int i = 0; i<k; i++)
    {
        for(int j = 0; j<arr[i].size(); j++)
        {
            q.push(arr[i][j]);
        }
    }

    vector<int>ans;
    while(!q.empty())
    {
        ans.push_back(q.top());
        q.pop();
    }
    return ans;
    */
}
