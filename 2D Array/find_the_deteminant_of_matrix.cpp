#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

int determinant(vector<vector<int>> inp, int n){
    // Base case
    if(n == 1) return inp[0][0];
    if(n == 2) return inp[0][0] * inp[1][1] - inp[0][1] * inp[1][0];

    // Now our matrix will have more than 2 rows and cols.
    int detr = 0;
    for(int i = 0; i<n; i++)
    {
        vector<vector<int>> temp;
        // this is calculating the submatrix.
        for(int j = 1; j<n; j++)
        {   
            vector<int>a;
            for(int k = 0; k<n; k++)
            {
                if(k == i)
                    continue;
                a.push_back(inp[j][k]);
            }
            temp.push_back(a);
        }
        detr = detr + pow(-1,i) * inp[0][i] * determinant(temp,n-1);
    }
    return detr;
}

int main()
{
    vector<vector<int>> inp = {{1, 2, 3},{4, 5, 6},{7, 10, 9}};

    int ans = determinant(inp,inp.size());
    cout<<"ans -> "<<ans<<endl;
    return 0;
}