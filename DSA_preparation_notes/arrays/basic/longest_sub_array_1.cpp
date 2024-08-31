#include<iostream>
#include<bits/stdc++.h>

/*
  Problem:-Longest sub array of POSITIVE elements with sum k(i.e longest contiguous part of array with sum equal to k)

*/

/*
   Brute force solution is generating all sub arrays
   Here we fix i at certain position,declare sum to zero and iterate j from that position to the end and add each element to sum.
   If sum equals k then find the length and compare with max everytime to get max_length.
*/

int longest_sub_array_brute(int*arr,int n,int k)
{
    int sum=0,length=0;
    for(int i=0;i<n;i++)
    {
      sum=0;
      for(int j=i;j<n;j++)
      {
         sum+=arr[j];
         if(sum==k)
         {
           length=std::max(length,j-i+1);  
         }
      }

    }

    return length;
}

//Better solution by using hash maps

int max(int a,int b)
{
  return a>=b?a:b;
}

int longest_sub_array_better(int*arr,int n,int k)
{
     std::map<int,int> mpp;//keys of map are values of array and values of map are indices of elements of array.
     int sum=0;
     int max_len=0,length=0;
     int rem;

     for(int i=0;i<n;i++)
     {
        sum+=arr[i];
        rem=sum-k;
        if(sum==k)
        {
          max_len=max(max_len,i+1);
        }
        if(mpp.find(rem)!=mpp.end())
        {
            length=i-mpp[rem];
            max_len=max(max_len,length);
        }
        if(mpp.find(sum)==mpp.end()) //i updates when sum is not present in map.this condition is useful when array contains zeroes. 
        {
          mpp[sum]=i;
        }
        std::cout<<sum<<" "<<rem<<" "<<mpp[rem]<<'\n';
     }

     return max_len;
}

//BRUTE AND BETTER WORKS FOR BOTH NEGATIVE AND POSITIVE K AND VALUES OF ARRAY.
//Time complexity is o(nlogn) for ordered map and o(n*1)(o(n^2) very worst case) for un ordered map. space complexity is o(n).

//Optimal solution using 2 pointer method.wroks for only positive values(including zeros)

int longest_sub_array_optimal(vector<int> arr, long long k) {

    int start=0,end=0,max_len=0;
    int n=arr.size();

   long long sum=arr[start];

   while(start<n)
   {
       if(sum==k)
       {
          max_len=max(max_len,end-start+1);
          std::cout<<'\n';
          if(end<n-1)
          {
            sum+=arr[++end];
          }
          else
          {
            start++;
          }
       }
       else if(sum<k)
       {
          if(end<n-1)
          {
            sum+=arr[++end];
          }
          else
          {
            start++;
          }
       }
       else
       {
           sum-=arr[start++];
       }
   }
   return max_len;
}

//Time complexity is o(n) and space is o(1).




int main(void)
{
    int arr[]={1,2,3,1,1,1,1,4,2,3};

    int arr2[]={2,0,0,3};

    std::cout<<longest_sub_array_better(arr,10,4)<<'\n';

}