#include<iostream>
#include<limits.h>
using namespace std;

int minDist(int a[], int n, int x, int y) {
    
    int Xindex = -1;
    int Yindex = -1;
    int minIndex = INT_MAX;
    
    for(int i = 0; i<n; i++)
    {
        if(a[i] == x)
        {
            Xindex = i;
            
            if(Yindex != -1)
            {
                // int temp = abs(Yindex, Xindex);
                minIndex = min(minIndex, abs(Yindex - Xindex));
            }
            else 
                continue;
        }
        
        if(a[i] == y)
        {
            Yindex = i;
            
            if(Xindex != -1)
            {
                // int temp = abs(Yindex, Xindex);
                minIndex = min(minIndex, abs(Yindex - Xindex));
            }
            else 
                continue;
        }
    }
    
    if(Xindex == -1 || Yindex == -1)
        return -1;
        
    return minIndex;
    
}

int main()
{
    int a[] = {86,39,90,67,84,66,62};
    // int a[] = {1,2,3,2};
    // int a[] = {1,2,3,5,1,6,3,5};
    int size = 7;

    // first element of comparision.
    int x = 7;
    // second element of comparision
    int y = 9;

    cout<<minDist(a,size,x,y);
    return 0;
}