// leetcode problem no.48

#include<iostream>
#include<bits/stdc++.h>

/*
 
IF ALLOCATING MEMORY IS ALLOWED THEN

int ans[n][n];

for(int i=0 ->n)
{
    for(int j=0 ->n)
    {
        ans[j][n-1-i]=matrix[i][j]
    }

}

space and time complexity is o(n^2)

*/

//leetcode problem is asking for INPLACE so solution is different

// Optimal solution is Transpose the matrix and reverse elements in each row.

void rotate(vector<vector<int>>& matrix) {

        int temp=0;

        int m=matrix.size();
        int n=matrix[0].size();

        for(int i=0;i<m;i++)
        {
            for(int j=i;j<n;j++)
            {
                if(i!=j)
                {
                    temp=matrix[i][j];
                    matrix[i][j]=matrix[j][i];
                    matrix[j][i]=temp;
                }
            }
        }

        for(int i =0;i<m;i++)
        {
            for(int j=0;j<n/2;j++)
            {
                temp = matrix[i][n-j-1];
                matrix[i][n-j-1]=matrix[i][j];
                matrix[i][j]=temp;
            }
        }
        
    }

// order of time complexity is o(n^2)+o(n^2) and space complexity is o(1)