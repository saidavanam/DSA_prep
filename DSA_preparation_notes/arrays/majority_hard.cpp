// Leetcode problem 229

#include<iostream>
#include<bits/stdc++.h>

/*
  Problem description:- find elements in array whose occurence is more n/3.
  
  Number of elements in array whsoe count>n/3 cannot be more than 2.
  suppose n=8.
  count>2, so minimum is 3
  so maximum no. of elements whose count >3 is 2
*/

/*
   Brute force solution:- picking an element and traversing through the array.
*/

vector<int> majorityElementBrute(vector<int>& nums) {

        int count=0,n=nums.size(),majority;
        vector<int> ls;
        for(int i=0;i<n;i++)
        {
            count=0;
            majority = nums[i];
            for(int j=i;j<n;j++)
            {
                if(ls.size()==0 || ls[0]!=majority)
                {
                    if(majority==nums[j])
                    {
                        count++;
                    }
                }
                else if(ls[0]==majority)
                {
                    break;
                }

            }
            if(count>n/3)
            {
                ls.push_back(majority);
            }
            if(ls.size()>=2)
            {
                break;
            }
        }

        return ls;
        
}

//Time complexity is o(n^2) and space complexity is o(k).

// Better solution is by using hash maps

    vector<int> majorityElement_Better(vector<int>& nums) {

        vector<int> ls;
        int n = nums.size();
        map<int,int> mpp;

        for(int i=0;i<n;i++)
        {
            mpp[nums[i]]++;
        }
        int count=n/3;
        for(auto it:mpp)
        {
            if(it.second>count)
            {
                ls.push_back(it.first);
            }
        }

        return ls;

        
    }

//Time complexity is o(n) and space complexity is o(n).

//Optimal Solution:- using different version of moore's algorithm. once visit optimal solution of majority element(n/2) in medium folder

vector<int> majorityElement(vector<int>& nums) {
        int ele1 = INT_MIN,c1 = 0;
        int ele2 = INT_MIN,c2 = 0;
        int n = nums.size();

        for(int i=0;i<n;i++)
        {
            if((c1==0 && ele1!=nums[i])&& nums[i]!=ele2)
            {
                ele1 = nums[i];
                c1++;
            }
            else if((c2==0 && ele2!=nums[i]) && nums[i]!=ele1)
            {
                ele2 = nums[i];
                c2++;
            }
            else if(ele1==nums[i])
            {
                c1++;
            }
            else if(ele2==nums[i])
            {
                c2++;
            }
            else
            {
                c1--,c2--;
            }
        }

        c1 = 0,c2 = 0;
        vector<int> ls;

        for(int i=0;i<n;i++)
        {
            if(nums[i]==ele1)
            {
                c1++;
            }
            if(nums[i]==ele2)
            {
                c2++;
            }
        }

        if(c1>n/3)
        {
            ls.push_back(ele1);
        }
        if(c2>n/3)
        {
            ls.push_back(ele2);
        }

        return ls;

        
    }
    /*
    Trace this solution by using array {2,1,1,3,1,4,5,6} and also understand solution carefully.To understand why nums[i]!=ele2 and nums[i]!=ele1 exists
    in first 2 if statements. remove them and trace the solution.

    Time complexity is O(n)+O(n) and space complexity is O(K).   
    */