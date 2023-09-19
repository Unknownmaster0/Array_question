/* question link -> https://practice.geeksforgeeks.org/problems/minimum-number-of-jumps-1587115620/1 */
#include <iostream>
using namespace std;

int minJumps(int arr[], int n)
{

    int steps = 0, destination = 0, position = 0;

    for (int i = 0; i < n - 1; i++)
    {
        destination = max(destination, i + arr[i]);

        if (i == destination)
            return -1;

        else if (i == position)
        {
            position = destination;
            steps++;
        }
    }

    return steps;
}

int main()
{
    int arr[] = {2, 3, 1, 1, 2, 4, 0, 1, 1};
    int size = 9;
    int jumps = minJumps(arr,size);

    cout<<"the number of jumps required is -> "<<jumps<<endl;

    return 0;
}