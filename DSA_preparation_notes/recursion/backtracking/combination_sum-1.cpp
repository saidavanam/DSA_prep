//leetcode problem no.39
 
class Solution {
public:
    void backtrack(vector<int>&candidates,vector<int>&temp,int target,vector<vector<int>> &ans,int start)
    {
        if(target==0)
        {
            ans.push_back(temp);
            return;
        }
        else if(target<0)
        {
            return;
        }
        else
        {
            for(int i=start;i<candidates.size();i++)
            {
                temp.push_back(candidates[i]);
                backtrack(candidates,temp,target-candidates[i],ans,i); // notice i is used instead of i+1
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        vector<vector<int>> ans;
        vector<int> temp;
        backtrack(candidates,temp,target,ans,0);
        return ans;
    }
};

//If use start instead of i in recursive call then u will get set of permutations