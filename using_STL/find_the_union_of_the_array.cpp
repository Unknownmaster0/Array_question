//question link -> https://practice.geeksforgeeks.org/problems/union-of-two-arrays3538/1

#include<iostream>
#include<set>
using namespace std;

//Function to return the count of number of elements in union of two arrays.
int doUnion(int a[], int n, int b[], int m)  {
    
    // whenever we need to find the unique elements in the array
    // we use the "set" DATA STRUCTURE
    set<int>st;
    for(int i = 0; i<n; i++)
        st.insert(a[i]);
        
    for(int j = 0; j<m; j++)
        st.insert(b[j]);
        
    return st.size();
    
    /*
    // storing the array a in the map
    unordered_map<int,int> mp;
    for(int i = 0; i<n; i++)
        mp[a[i]]++;
        
    // storing the array b in map
    unordered_map<int,int> bp;
    for(int i = 0; i<m; i++)
        bp[b[i]]++;
        
    // finding the elements in b also in a.
    int count = 0;
    for(auto i:bp)
    {
        if(mp.find(i.first) != mp.end())   
            count++;
    }
    
    return mp.size() + (bp.size()-count);
    */
}

int main()
{
    
    return 0;
}