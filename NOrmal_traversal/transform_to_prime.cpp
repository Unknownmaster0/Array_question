bool isPrime(int n)
{
    if(n <= 1)
        return false;
        
    for(int i = 2; i*i <= n; i++)
    {
        if(n % i == 0)
            return false;
    }
    
    return true;
}

int minNumber(int arr[],int N)
{
    int sum = 0;
    for(int i = 0; i<N; i++)
    {
        sum += arr[i];
    }
    
    // check if sum is prime then return it.
    if(isPrime(sum))
        return 0;
    
    int ans = 0;
    for(int i = 1; i<INT_MAX; i++)
    {
        sum += i;
        // cout<<"sum -> "<<sum<<endl;
        if(isPrime(sum))
        {
            ans = i;
            break;
        }
        sum -= i;
    }
    
    return ans;
}