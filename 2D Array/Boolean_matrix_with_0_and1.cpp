#include <iostream>
#include <vector>
using namespace std;

/*question link -> https://practice.geeksforgeeks.org/problems/boolean-matrix-problem-1587115620/1*/

void print(vector<vector<int>> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
            cout << arr[i][j] << " ";

        cout << endl;
    }
}

void booleanMatrix(vector<vector<int>> &matrix)
{
    int row = matrix.size();
    int col = matrix[0].size();

    vector<vector<int>> store;
    // storing the index of the 1 bit
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (matrix[i][j] == 1)
            {
                vector<int> temp;
                temp.push_back(i);
                temp.push_back(j);

                store.push_back(temp);
            }
        }
    }

    cout << "Printing the store matrix which stores the 1 bit index." << endl;
    print(store);

    int n = store.size();
    int i = 0;
    while (i < n)
    {
        // the first element of store vector at index i
        int one = store[i][0];
        // the second element of store vector at index i
        int second = store[i][1];

        // changing the row elements
        for (int j = 0; j < col; j++)
            matrix[one][j] = 1;

        // changing the col elements
        for (int k = 0; k < row; k++)
            matrix[k][second] = 1;

        i++;
    }
}

int main()
{
    /*
    vector<vector<int>> input;
    int row, col;
    cout << "enter the row-> ";
    cin >> row;
    cout << "enter the col-> ";
    cin >> col;

    for(int i = 0; i<row; i++)
    {
        vector<int>temp;
        for(int j = 0; j<col; j++)
        {
            cin>>temp[j];
        }
        input.push_back(temp);
    }
    */
    vector<vector<int>> input = {{1, 0, 0}, {1, 0, 0}, {1, 0, 0}, {0, 0, 0}};

    booleanMatrix(input);

    cout << "Printing the boolean matrix." << endl;
    print(input);

    return 0;
}