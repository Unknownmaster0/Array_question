/*
Question link -> https://www.codingninjas.com/studio/problems/product-of-array-except-self_630271
*/

// my approach and optimal approach

/*
    This can also be solved using two new array say prefix[n] and suffix[n].
    prefix will store the multiplication of the all elements till just before the i-th element.
    suffix will store the multiplication of the all elements till just after the i-th element.

    finally they are used to store the product in the new array 
    such that poduct[0] = suffix[1];
            product[n-1] = prefix[n-1];

    else in all other cases ->  product[i] = prefix[i-1] * suffix[i+1];

*/

int *getProductArrayExceptSelf(int *arr, int n)
{

// ************  Brutforce method-> gives TLE on long cases **********************

    // long long* PRODUCT = new long long[n];
    // int mod = 1000000007;
    // int i = 0; 
    // while( i < n ){
    //     PRODUCT[i] = 1;
    //     long long mul = PRODUCT[i];
    //     for(int j = 0; j<n; j++){
    //         if( i != j ){
    //             mul *= (arr[j] % mod);
    //         }
    //     }
    //     PRODUCT[i] = mul;
    //     i++;
    // }

    // return PRODUCT;


// ***********  Optimal Approach-> Time complexity O(n)  *******************
/*
concept -> 1. make the array product.
           2. set the all the elements of the product array as 1.
           3. if the original array has only one element then its product is 1. return product.
           4. step 1 -> Assign the value of temp in each iteration.
                start traversing the whole array from left side and use temp variable 
                to store the multiplication of all the left elements.


            5. step 2-> start traversing the array from back side.
             Assign the value of temp2 to the product[i] with the multiplication of previously stored 
                        product[i];
                        temp2 will updated with the multiplication of the all the right elements of the array starting from the end index.
*/


    int* PRODUCT = new int[n];
    // setting the value of the product all element to 1.
    for(int i = 0; i<n; i++){
        PRODUCT[i] = 1;
    }

    int mod = 1000000007;
    // if only one element then return the Product.
    if(n == 1){
        return PRODUCT;
    }

    // step -> 1
    long long temp = 1;
    for(int i = 0; i<n; i++){
        // PRODUCT[i] = 1;
        PRODUCT[i] = temp;
        temp = ( temp * arr[i] ) % mod;
    }

    // step 2 ->
    long long temp_1 = 1;
    // now traversing the array from back side
    for(int i = n-1; i>=0; i--){
        PRODUCT[i] = (PRODUCT[i] * temp_1) % mod;
        temp_1 = (temp_1 * arr[i]) % mod;
    }


    return PRODUCT;
}