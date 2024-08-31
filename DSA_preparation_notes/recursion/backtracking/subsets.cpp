// Leetcode problem no. 78

class Solution {
public:
    void backtrack(vector<int> &nums,vector<int> &temp,vector<vector<int>> &ans,int p)
    {
        ans.push_back(temp);
        for(int i=p;i<nums.size();i++)
        {
            temp.push_back(nums[i]);
            backtrack(nums,temp,ans,i+1); //notice i is used here.refer trace in your notes then you will understand. 
            temp.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        int p=0;
        vector<vector<int>> ans;
        vector<int> temp;
        backtrack(nums,temp,ans,p);
        return ans;

    }
};