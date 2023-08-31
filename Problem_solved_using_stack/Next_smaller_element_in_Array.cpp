#include<iostream>
#include <stack>
#include <vector>
using namespace std;

/* time complexity -> O(n^2) -> n is the number of nodes.
void findSmaller(vector<int>& arr,int i,int size)
{
    stack<int>s;
    while(size > i)
    {
        s.push(arr[size]);
        size--;
    }

    while(!s.empty())
    {
        if(s.top() < arr[i])
        {
            arr[i] = s.top();
            return;
        }
        else
            s.pop();
    } 

    if(s.empty())
        arr[i] = -1;

    return;
}
*/

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    // maintain the time complexity of O(n)
    // step 1 -> make a stack and initially push the element -1 in it.
    stack<int>s;
    s.push(-1);

    vector<int>ans(n);
    // step 2 -> now start traversing the array from the end.
    for(int i = n-1; i>= 0; i--)
    {
        // if the stack top element is greater then the element, then find the smaller element.
        while(s.top() >= arr[i])
        {
            s.pop();
        }

        // after coming out of loop, we have got the element less than the arr[i]
        ans[i] = s.top();
        s.push(arr[i]);
    }

    return ans;


    /* time complexity -> O(n^2) -> n is the number of nodes
    int i, j;
    for(i = 0; i<arr.size()-1; i++)
    {
        int temp = arr[i];
        for(j = i+1; j<arr.size(); j++)
        {
            if(temp > arr[j])
            {
                arr[i] = arr[j];
                break;
            }
        }

        if(arr[i] == temp)
            arr[i] = -1;

    }

    arr[i] = -1;

    return arr;

*/
    /*
    for(int i = 0; i<arr.size()-1; i++)
    {
        findSmaller(arr,i,n-1);
    }

    arr[n-1] = -1;

    return arr;
    */
}



int main()
{
    
    return 0;
}