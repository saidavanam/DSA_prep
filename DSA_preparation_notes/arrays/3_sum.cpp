#include<iostream>
#include<bits/stdc++.h>

using namespace std;

//leetcode problem no.15 -> 3sum (arr[i]+arr[j]+arr[k]=0).prevent duplicates also

//Brute force

vector<vector<int>> threeSum(vector<int>& arr) {
        set<vector<int>> st;
        vector<vector<int>> v;

        int n = arr.size();

    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            for(int k=j+1;k<n;k++)
            {
                if(arr[i]+arr[j]+arr[k]==0)
                {
                    vector<int> temp = {arr[i],arr[j],arr[k]};
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
                    
                }
                
            }
        }
    }

    for(auto ele:st)
    {
        v.push_back(ele);
    }

    

    return v;

        
    }

//Time complexity is o(n**3*logn)(Very Bad it is) and space complexity is o(2n). where n is no.of triplets

//Better solution using hashing.(we use sets for hashing instead of maps)

vector<vector<int>> BetterthreeSum(vector<int>& arr) {
        
        vector<vector<int>> v;
        set<vector<int>> st;
        int n = arr.size();
        int neg_sum;

        for(int i=0;i<n;i++)
        {
            set<int> hashset;
            for(int j=i+1;j<n;j++)
            {
                neg_sum = -(arr[i]+arr[j]);
                if(hashset.find(neg_sum)!=hashset.end())
                {
                    vector<int> temp ={arr[i],arr[j],neg_sum};
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
                }
                hashset.insert(arr[j]);
                
            }
            
        }

        for(auto ele:st)
        {
            v.push_back(ele);
        }

        return v;


        
    }

//Time complexity is o(n**2*logM) m can be 1,2,3 
// space complexity is o(n)+o(no.of.triplets)+o(no.of triplets)(consider n only)

//BOTH BRUTE AND BETTER DOESNT RUN FOR ALL TEST CASES IN LEETCODE(ONLY 311/313 ARE PASSED)

//Optimal solution

//Understand solution with this test case {-2,-2,-2,-1,-1,-1,0,0,0,2,2,2,2}

vector<vector<int>> optimalthreeSum(vector<int>& arr) {
        
        vector<vector<int>> v;
        int n = arr.size();
        int j,k,sum;

        sort(arr.begin(),arr.end()); //sort the array first


        for(int i=0;i<n;i++)
        {
            if(i!=0 && arr[i]==arr[i-1]) //Avoiding duplicate elements
            {
                continue;
            }

            // Now i remains constant for this iteration and use two pointer approach(j,k)

            k = n-1; //**
            j = i+1; //**
            
            while(j<k)
            {
                if(j!=i+1 && arr[j]==arr[j-1]) //Avoiding duplicate elements
                {
                    j++;
                    continue;
                }
                if(k!=n-1 && arr[k]==arr[k+1]) //Avoiding duplicate elements
                {
                    k--;
                    continue;
                }


                sum = arr[i]+arr[j]+arr[k]; 

                if(sum<0)
                {
                    j++;
                }
                else if(sum>0)
                {
                    k--;
                }
                else
                {
                    v.push_back({arr[i],arr[j],arr[k]});
                    j++;
                    k--;
                }
            }
        }

    return v;
        
}

/*
 Time complexity is o(n*logn)+o(n**2)
 space complexity is o(no.of.triplets)
*/

