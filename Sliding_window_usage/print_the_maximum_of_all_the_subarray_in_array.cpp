#include<iostream>
#include<vector>
#include<limits.h>
#include<queue>
using namespace std;

// Approach 1 -> using the sliding window technique.
/*
vector<int> findMaximum(vector<int>&arr,int k)
{
    vector<int> ans;
    int maxi = INT_MIN;
    for(int i = 0; i<k; i++){
        maxi = max(maxi, arr[i]);
    }
    ans.push_back(maxi);
    for(int i = k; i<arr.size(); i++)
    {
        maxi = max(maxi, arr[i]);
        ans.push_back(maxi);
    }
    return ans;
}
*/

// Approach 2 -> trying to solve this question using heap.
/*make a maxHeap, then push the first K element with their indices into the heap.
Now, traverse the array from the k to n and compare the array element with the maxHeap top and also check for the window size of the top element, whether it lies in the window of size k or not by comparing with the (i-k)
if the element is greater than maxheap top, then only push the element into heap by popping. else don't push.*/

vector<int> findMaximum(vector<int>&arr, int k)
{
    priority_queue<pair<int,int>>maxheap;
    vector<int> ans;
    // pushing the first k element to the maxheap.
    for(int i = 0; i<k; i++)
    {
        maxheap.push({arr[i],i});
    }
    ans.push_back(maxheap.top().first);

    // iterating over the rest of the array.
    for(int i = k; i<arr.size(); i++)
    {
        if(maxheap.top().second <= i-k)
        {
            maxheap.pop();
            maxheap.push({arr[i],i});
        }
        ans.push_back(maxheap.top().first);
    }
    return ans;
}

int main()
{
    vector<int>input {1, 2, 3, 1, 4, 5, 2, 3, 6};
    int k;
    cout<<"enter size of subarray -> ";
    cin>>k;
    vector<int> ans = findMaximum(input,k);
    for(auto i:ans)
        cout<<i<<" ";
    cout<<endl;
    return 0;
}