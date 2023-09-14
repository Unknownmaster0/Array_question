/*
https://practice.geeksforgeeks.org/problems/equilibrium-point-1587115620/1?page=1&difficulty[]=-2&difficulty[]=-1&difficulty[]=0&category[]=Arrays&sortBy=submissions
*/
/*
Solved using the two methods -> 
1. using the binary search operation
2. using the prefix sum algorithm
*/

int equilibriumPoint(long long arr[], int n) {

// Approach 2 -> using the prefix sum concept.
    int leftSum = 0, rightSum = 0;
    
    // calcultaing the rightSum
    for(int i = 0; i<n; i++)
        rightSum += arr[i];
        
    // checking for the equilibrium
    for(int i = 0; i<n; i++)
    {
        // incrementing the left sum
        leftSum += arr[i];
        
        // decrement the right sum, by substracting the current element from it.
        rightSum -= arr[i];
        
        // Now, check whether the leftSum and right becomes equal or not.
        if( rightSum == leftSum - arr[i] )
            return i+1;
    }
    
    return -1;


/*
// Approach 1 -> using the concept of the binary search something.
    if(n == 2 && arr[0] == arr[1])
        return -1;

    int start = 0, end = n-1;
    long long sumStart = 0, sumEnd = 0;
    
    while(start < end)
    {
        if(sumStart == sumEnd)
        {
            sumStart += arr[start];
            sumEnd += arr[end];
            start++;
            end--;
        }
        else if(sumStart < sumEnd)
        {
            sumStart = sumStart + arr[start];
            start++;
        }
        else
        {
            sumEnd = sumEnd + arr[end];
            end--;
        }
    }
    
    if(sumStart == sumEnd)
        return (start+1);
        
    return -1;
*/
    
}