//leetcode problem no. 90

class Solution {
public:
    void backtrack(vector<int>&nums,vector<vector<int>>&ans,vector<int>&temp,int index)
    {
        ans.push_back(temp);

       for(int i=index;i<nums.size();i++)
       {
           if(i>index && nums[i]==nums[i-1]) // step which doesnt allow duplicates for recursive calls.
           {
              continue;
           }
           temp.push_back(nums[i]);
           backtrack(nums,ans,temp,i+1);
           temp.pop_back();
       }

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        vector<vector<int>> ans;

        sort(nums.begin(),nums.end()); // Very important step. This step keeps all duplicates in one place.

        vector<int> temp;
        backtrack(nums,ans,temp,0);
        return ans;
        
    }
};