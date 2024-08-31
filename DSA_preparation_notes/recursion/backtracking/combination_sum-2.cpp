// leetcode problem no.40


//whenever duplicates are there,sort array and then use backtracking


class Solution {
public:
    void backtrack(vector<int>&candidates,vector<vector<int>>&ans,vector<int>&temp,int target,int index)
    {
        if(target == 0)
        {
            ans.push_back(temp);
            return;
        }
        if(target<0)
        {
            return;
        }
        for(int i=index;i<candidates.size();i++)
        {
            if(i>index && candidates[i]==candidates[i-1]) // step which doesnt allow duplicates for recursive calls.
            {
                continue;
            }
            temp.push_back(candidates[i]);
            backtrack(candidates,ans,temp,target-candidates[i],i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        sort(candidates.begin(),candidates.end()); //IMP STEP

        vector<vector<int>> ans;
        vector<int> temp;
        int index = 0;

        backtrack(candidates,ans,temp,target,index);
        return ans;
        
    }
};