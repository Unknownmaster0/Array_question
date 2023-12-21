#include<iostream>
using namespace std;

/* Approach -> Traversing the array from the both side. From, the left and from right.
            for the particular children, it has two neighbour's its left and right both.
            so, we have to consider both of them.

step 1 -> first assign the minimum number of candy each require in candy array.
step 2 -> traverse from the back side of rating array and check if the rating of curr child has greater value
        than it's left neighbour, then we need to update the candy value of the current child.
        candy[i] = max(its own candy, its neighbour candy + 1);
step 3 -> traverse from the front side of rating array and check if the rating of curr child has greater value
        than it's right neighbour then we need to update the candy value of the current child.
        
finally sum up all the candy array element and return it.
*/
int minCandy(int N, vector<int> &ratings) {
    vector<int>candy(N,1);
    
    
    // right neighbour comparision
    for(int i = N-2; i>=0; i--)
    {
        if(ratings[i] > ratings[i+1])
            candy[i] = candy[i+1]+1;
    }
    
    // left neighbour comparision
    for(int i = 1; i<N; i++)
    {
        if(ratings[i] > ratings[i-1])
            candy[i] = max(candy[i], candy[i-1]+1);
    }

    int totalCandy = 0;
    for(auto i:candy)
    {
        totalCandy += i;
    }
        
    return totalCandy;
}

int main()
{
    
    return 0;
}