// Leetcode problem no.18

//Optimal solution(similar one to 3 sum)

vector<vector<int>> optimalfourSum(vector<int>& nums, int target) {

        sort(nums.begin(),nums.end());
        vector<vector<int>> v;
        set<vector<int>> st;
        int n = nums.size();
        int i,j,k,l;
        long long sum =0;

        for(i=0;i<n;i++)
        {
            if(i>0 && nums[i]==nums[i-1])
            {
                continue;
            }
            for(j=i+1;j<n;j++)
            {
                if(j!=i+1 && nums[j]==nums[j-1])
                {
                    continue;
                }
                k = j+1;
                l = n-1;
                while(k<l)
                {
                    if(k!=j+1 && nums[k]==nums[k-1])
                    {
                        k++;
                        continue;
                    }
                    if(l!=n-1 && nums[l]==nums[l+1])
                    {
                        l--;
                        continue;
                    }
                    sum = nums[i]+nums[j];
                    sum += nums[k]+nums[l];
                    if(sum>target)
                    {
                        l--;
                    }
                    else if(sum<target)
                    {
                        k++;
                    }
                    else
                    {
                        st.insert({nums[i],nums[j],nums[k],nums[l]});
                        k++;
                        l--;
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

// use this testcase {1,0,-1,0,-2,2} for dry run

/* 
Time complexity is o(n**3)+o(nlogn)
space complexity is o(n)
*/