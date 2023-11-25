// question link -> https://www.geeksforgeeks.org/problems/shuffle-integers2401/1

/* 
    input -> [1,2,3,4,5,6] here n = 6;
    here a1,a2,a3.....a(n/2),b1,b2,b3...b(n/2)
    here a1 = 1, a2 = 2, a3 = 3, b1 = 4, b2 = 5, b3 = 6;

   we need to make an array which have [a1,b1,a2,b2,a3,b3.....] that is. 
   Time complexity -> O(N)
   space complexity -> O(1)

    output ->[1,4,2,5,3,6]
*/

	void shuffleArray(int arr[],int n)
	{
/*
    Concept -> what we are doing is ->
                making a number which will store the two number.
                let's take example of -> {1,2,3,4,5,6};
                
                ex -> we going to store the 4&1 in same number and similarly 5&2 in same , similarly 6&3 same.
                
                By seeing the consraints we came to know that , no any number in the array will greater than 1000.
                thus, we find how many bits is required to store the maximum number like 1000.
                
                2^10 = 1024 [that is if we consider 10bits then we can store the 1000 in it.]
                
                so we make the 10bits space at number 4,5,6 and store there 1,2,3 in it.
                
                for making space we use left shift operator.
                
4 << 3 -> it means that three zeros are more added to the 4 numbers end. i.e 100[4 binary] becomes 100000 now.
so, we need 10 zeros extra to store the any number .
so, we do 4 << 10.
step 1 -> we do left shift of every number after the half of the array with the 10 till the last index.
step 2 -> Now we store the number of index (0 to n/2) in the number from index (n/2 to n)
        by using the "or" operator.
        4 << 10 -> 100[initial 4] -> after left shifting -> 1000000000000[becomes this.] 
        now taking that number or with the first index number. 
        1000000000000 | 2 -> 1000000000010 becomes this.
        
step 3 -> now we store everything now come to take out of it.
        so for taking out 'a' -> we do 'and[&]' with the (nine times 1)[i.e. 1023] 
        
        1000000000010 & 1023 -> this will give the 'a' part i.e. 2.
        then we do right shift 10 times again to remove the spaces what we created.
*/
	    int k = n/2;
	    for(int i = 0; i<n/2; i++)
	    {
	        
// step 1 -> we do left shift of every number after the half of the array with the 10 till the last index.
	        arr[k] = arr[k] << 10;
// step 2 -> Now we store the number of index (0 to n/2) in the number from index (n/2 to n) by using the "or" operator.
	        arr[k] = (arr[k] | arr[i]);
	        k++;
	    }
	    
// step 3 -> now we store everything now come to take out of it.
//         so for taking out 'a' -> we do 'and[&]' with the (nine times 1)[i.e. 1023] 

//         1000000000010 & 1023 -> this will give the 'a' part i.e. 2.
//         then we do right shift 10 times again to remove the spaces what we created.


	    // number wapas nikalna hai
	    k = n/2;
	    for(int i = 0; i<n;)
	    {
	        // a value first
	        int a = arr[k] & (1023);
	        arr[i++] = a;
	        
	        int b = arr[k] >> 10;
	        arr[i++] = b;
	        
	        k++;
	    }
	}
	