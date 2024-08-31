//leetcode problem no.47

class Solution {
public:
    void backtrack(vector<int>&nums,vector<vector<int>>&ans,map<int,int> &count,vector<int> &temp)
    {
        if(temp.size()==nums.size())
        {
            ans.push_back(temp);
            return;
        }
        for(auto it=count.begin();it!=count.end();it++)
        {
            if(it->second>0)
            {
                temp.push_back(it->first);
                it->second -=1;

                backtrack(nums,ans,count,temp);
                it->second +=1;
                temp.pop_back();
            }

        }
        
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {

        
        vector<vector<int>> ans;
        map<int,int> count;
        vector<int> temp;

        for(int i:nums)
        {
            count[i]+=1;
        }
        backtrack(nums,ans,count,temp);
        return ans;
        
    }
};

//Refer trace in your notebook.

// Another solution which is modified version of permutations 1

class Solution {
public:
    void backtrack(vector<int>&nums,vector<vector<int>>&ans,map<vector<int>,bool> &ele,int p)
    {
        if(nums.size()==p && ele[nums]==false)
        {
            ans.push_back(nums);
            ele[nums] = true;
            return;
        }

        for(int i=p;i<nums.size();i++)
        {
            swap(nums[p],nums[i]);
            backtrack(nums,ans,ele,p+1);
            swap(nums[p],nums[i]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {

        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> temp;
        map<vector<int>,bool> ele;

        backtrack(nums,ans,ele,0);

        return ans;
        
    }
};

//1st solution is more better than 2nd