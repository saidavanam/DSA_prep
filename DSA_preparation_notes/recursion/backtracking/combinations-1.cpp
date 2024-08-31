//leetcode problem no. 77

class Solution {
public:
    void backtrack(vector<vector<int>> &ans,vector<int> &temp,int n,int k,int index)
    {
        if(temp.size()==k)
        {
            ans.push_back(temp);
            return;
        }

        for(int i=index;i<n;i++)
        {
            temp.push_back(i+1);
            backtrack(ans,temp,n,k,i+1); // i is used here.
            temp.pop_back();

        }

    }
    vector<vector<int>> combine(int n, int k) {

        vector<vector<int>> ans;
        vector<int> temp;
        backtrack(ans,temp,n,k,0);
        return ans;
        
    }
};