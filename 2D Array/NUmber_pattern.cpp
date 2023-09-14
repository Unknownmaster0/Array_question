/*
https://www.codingninjas.com/studio/problems/easy_6613995?topList=21-days-beginner-coding-challenge&leftPanelTab=0
*/

/*
Given pattern like -> for n = 3
                      1 2 3 10 11 12   // the elements in the 1st row after the n number of element is (n*n)+1
                      4 5 8 9
                      6 7
*/
#include <bits/stdc++.h> 
vector<vector<int>>printPattern(int n)
{
	vector<vector<int>>v ;
	vector<int>temp;
	int num = (n * n) + 1;
	int i = 1;
	for(int row = 1; row <= n; row++)
	{
		for(int col = 0; col < n-row+1;  col++)
		{
			temp.push_back(i);
			i++;
		}
		
		int store = num - 1;
		for(int col = 0; col < n-row+1; col++ )
		{
		    temp.push_back(num);
		    num++;
		}
		
		v.push_back(temp);
		
		num = store - (n - row - 1);
		temp.erase(temp.begin(),temp.end());
	}

	return v;
}