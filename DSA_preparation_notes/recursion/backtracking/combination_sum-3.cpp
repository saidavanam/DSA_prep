//leetcode problem no.216




class Solution {
public:
    void backtrack(vector<vector<int>>&ans,vector<int>&temp,int target,int k,int number)
    {
        if(temp.size()==k && target==0)
        {
            ans.push_back(temp);
            return;
        }
        if(temp.size()>k || target<0)
        {
            return;
        }
        for(int i=number;i<=9;i++)
        {
            
            temp.push_back(i);
            backtrack(ans,temp,target-i,k,i+1);
            temp.pop_back();
        }

    }
    vector<vector<int>> combinationSum3(int k, int n) {

        vector<vector<int>> ans;
        vector<int> temp;
        backtrack(ans,temp,n,k,1);
        return ans;
        
    }
};