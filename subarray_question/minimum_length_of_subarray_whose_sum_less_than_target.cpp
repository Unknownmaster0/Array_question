#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int smallestSubWithSum(int arr[], int n, int x)
{
    int sum = 0;
    int length = INT_MAX;
    int j = 0;
    for(int i = 0; i<n; i++){
        
        sum += arr[i];
        
        while(sum > x)
        {
            length = min( length, i-j+1 );
            sum -= arr[j]; 
            j++;
        }
        
    }
    
    if( length != INT_MAX )
        return length;
        
    return 0;
}

int main()
{
    
    return 0;
}