#include <bits/stdc++.h>
#include<iostream>
using namespace std;

class element{
    public:
        int data;
        int row;
        int col;

    element(int data, int row, int col)
    {
        this -> data = data;
        this -> row = row;
        this -> col = col;
    }
};

class comparator{
    public:
        bool operator()(element* e1, element* e2)
        {
            return e1->data > e2->data;
        }
};

// Time complexity -> O(n*k * log(n*k)) Space complexity -> O(n * k)
vector<int> mergeKSortedArrays(vector<vector<int>>&arr, int k)
{
    // step 1 -> I need one user defined data type of the priority queue.
    priority_queue<element*, vector<element*>, comparator> minHeap;

    // step 2 -> Push the first element of all the k arrays in the vector.
    for(int i = 0; i<k; i++)
    {
        element* temp = new element(arr[i][0], i , 0);
        minHeap.push(temp);
    }

    /* step 3 -> Now push the top element
     of the queue into the ans vector and push the next 
     element of the same array into the queue again
     */
    vector<int>ans;
    while(!minHeap.empty())
    {
        element* top = minHeap.top();
        minHeap.pop();
        ans.push_back(top->data);

        // pushing the next element of the same array into the heap
        int row = top->row; // current element row
        int col = top->col; // current element col

        // for next element of the same array we just need to move the col
        if(col + 1 < arr[row].size())
        {
            element* nextelement = new element(arr[row][col+1], row, col+1);
            minHeap.push(nextelement);
        }
    }
    return ans;
}


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
