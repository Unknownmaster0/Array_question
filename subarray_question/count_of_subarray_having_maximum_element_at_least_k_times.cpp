/*
Question-> 
You are given an integer array nums and a positive integer k.
Return the number of subarrays where the maximum element of nums appears at least k times in that subarray.
A subarray is a contiguous sequence of elements within an array.

Input: nums = [1,3,2,3,3], k = 2
Output: 6
Explanation: The subarrays that contain the element 3 at least 2 times are: [1,3,2,3], [1,3,2,3,3], [3,2,3], [3,2,3,3], [2,3,3] and [3,3].
*/

 long long countSubarrays(vector<int>& nums, int k) {
        
        int maxi = *max_element(nums.begin(),nums.end());
        
        /* concept ->  use the sliding window technique and hashmap.
                        first simply add the frequency of the element to the map.
                        when we get the frequency of max element greater or equal to the k, then increment the count as 
                            count += n - j; // j is the current position of the index while traversing the array.
                        again increment the start index, to shrink the window but don't move the j pointer, 
                            again if the frequency of the max element >= k, then increment count = count + (n-j);
        */
        
        int n = nums.size();
        int start = 0;
        long long count = 0;
        unordered_map<int,int>freq;
        for(int curr = 0; curr < nums.size(); curr ++)
        {
            // incrementing the frequency of each and every element.
            freq[nums[curr]]++;

            // when we get the freq of max element greater than or equal to K, then come by shrinking window till the maxelement freq >= k
            while(start <= curr && freq[maxi] >= k)
            {
                count += n-curr;
                // shrinking the window size and also decrement the frequency of the element which is at start.
                freq[nums[start]]--;
                start++;
            }
        }
        return count;
        
    }