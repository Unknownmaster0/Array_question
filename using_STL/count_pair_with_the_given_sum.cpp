/*
Question link-> https://practice.geeksforgeeks.org/problems/count-pairs-with-given-sum5022/1?page=1&difficulty[]=0&category[]=Arrays&category[]=Sorting&category[]=Binary%20Search&sprint=94ade6723438d94ecf0c00c3937dad55&sortBy=submissions
*/

    int getPairsCount(int arr[], int n, int k) {
        
        int count = 0;
        unordered_map<int,int> m;
        
        for(int i = 0; i<n; i++){
            
            if( m[k-arr[i]] > 0)
                count += m[k-arr[i]];
            
            m[arr[i]]++;
        }
        
        return count;
    }