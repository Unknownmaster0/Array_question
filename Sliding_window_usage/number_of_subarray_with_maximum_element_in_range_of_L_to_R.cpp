    long countSubarrays(int a[], int n, int L, int R)
    {
        // king -> the elements in the range of L and R including the L and R.
        // villan -> the elements who is greater than R.
        // aam aadmi -> the elements who is lesser than L.
        
        /* concept -> If we get the king element then incremnt the subarrays count as equal to the size of the 
                    current array size.
                    
                else if we get the aam aadmi then don't update the size, leave it with the previous king element
                size.
                
            but when we get the villan element then size will updated as 0, as the old empire has been 
            broken by the villan.
        */
        
        long long countSub = 0, size = 0, start = 0;
        
        for(int end = 0; end < n; end ++)
        {
            if(a[end] >= L && a[end] <= R)
                size = end - start + 1;
                
            else if(a[end] > R)
            {// the villan element.
                size = 0;
                start = end + 1;
            }
            
            countSub += size;
        }
        
        return countSub;
    }