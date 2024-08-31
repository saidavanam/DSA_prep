/*
Problem statement
There is an integer array ‘A’ of size ‘N’.



Number of inversions in an array can be defined as the number of pairs of ‘i’, ‘j’ such that ‘i’ < ‘j’ and ‘A[i]’ > ‘A[j]’.

You must return the number of inversions in the array.



For example,
Input:
A = [5, 3, 2, 1, 4], N = 5
Output:
7
Explanation: 
The pairs satisfying the condition for inversion are (1, 2), (1, 3), (1, 4), (1, 5), (2, 3), (2, 4), and (3, 4). 
The number of inversions in the array is 7.
*/

// Brute solution

int numberOfInversions(vector<int>&a, int n) {
    // Write your code here.
    int count = 0;
     for(int i=0;i<n;i++)
     {
         for(int j=i;j<n;j++)
         {
             if(a[i]>a[j])
             {
                 count++;
             }

         }
     }
     return count;
}

//Time complexity is o(n**2) and space complexity is o(1)