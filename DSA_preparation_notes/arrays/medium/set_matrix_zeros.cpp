// leetcode problem no.73

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

/*
Brute force solution :- whenever matrix[i][j] is zero. set its entire row and column to -1 IN PLACE OF 1'S. zero should remain same

  traverse whole matrix once more to convert all -1 to zeros
*/

void setZeroes(vector<vector<int>>& matrix) {

        for(int i=0;i<matrix.size();i++)
    {
        for(int j=0;j<matrix[0].size();j++)
        {
            if(matrix[i][j]==0)
            {
                for(int k=0;k<matrix.size();k++)
                {
                    if(matrix[k][j]!=0)
                    {
                        matrix[k][j]=-1;
                    }
                }

                for(int l=0;l<matrix[0].size();l++)
                {
                    if(matrix[i][l]!=0)
                    {
                        matrix[i][l]=-1;
                    }
                }
            }
        }
    }

    for(int i=0;i<matrix.size();i++)
    {
        for(int j=0;j<matrix[0].size();j++)
        {
            if(matrix[i][j]==-1)
            {
                matrix[i][j]=0;
            }
        }
    }
        
}

/*
  This solution doesnt work always. consider this test case [[-1],[2],[3]]. 
  According to brute force solution output is [[0],[2],[3]]. but expected is [[-1],[2],[3]]. not all -1s should not be converted to zeros

time complexity is O(n*m)*(n+m)+o(n*m) approx to O(n^3)
*/

/*

    Better solution :-
    define two arrays of size row and column and intialize it to MAX_VALUE.
    steps:-
    1)traverse through the array, if matrix[i][j]==0 then change the value of arr_row[i] and arr_col[j] to zero
    2)Traverse through the array once again and if arr_row[i] or arr_col[j] is 0 then change value of matrix[i][j] to 0 
*/

void better(vector<vector<int> >& matrix) {

        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> arr_row(m);
        vector<int> arr_col(n);

        for(int i = 0;i<m;i++)
        {
            arr_row[i] = INT_MAX;
        }
        for(int j=0;j<n;j++)
        {
            arr_col[j] = INT_MAX;
        }

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]==0)
                {
                    arr_row[i]=0;
                    arr_col[j]=0;
                }
            }
        }

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(arr_row[i]==0 || arr_col[j]==0)
                {
                    matrix[i][j]=0;
                }
            }
        }
        
    }

/*
   Time complexity is o(2*n*m)
   space complexity is o(m)+o(n)
*/

/*
  Optimal Solution:- O(1) space complexity and same time complexity

  doing same better solution procedure but we compare elements with col[0] and row[0][1:].

  https://www.youtube.com/watch?v=N0MgLvceX7M&list=PLgUwDviBIf0rENwdL0nEH0uGom9no0nyB&index=14. (optimal)

  read solution carefully
*/

void optimal(vector<vector<int>>& matrix) {

        int col_0 = matrix[0][0];
        int m = matrix.size();
        int n = matrix[0].size();

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(j==0)
                {
                    if(matrix[i][j]==0)
                    {
                        col_0=0;
                    }
                }
                else
                {
                    if(matrix[i][j]==0)
                    {
                        matrix[0][j]=0;
                        matrix[i][0]=0;
                    }
                }
            }
        }


        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(matrix[0][j]==0 || matrix[i][0]==0)
                {
                    matrix[i][j]=0;
                }

            }
        }

        if(matrix[0][0]==0)
        {
             for(int j=1;j<n;j++)
           {
                matrix[0][j]=0; 
           }    

        }

        if(col_0==0)
        {
            for(int i=0;i<m;i++)
           {
                matrix[i][0]=0;
           }

        }
        
}