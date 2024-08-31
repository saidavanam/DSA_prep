class Solution {
public:
    void recurse(vector<int> &nums,vector<vector<int>> &ans,int index)
    {
        if(index==nums.size())
        {
            ans.push_back(nums);
            return;
        }
        for(int i=index;i<nums.size();i++)
        {
            swap(nums[index],nums[i]);

            recurse(nums,ans,index+1); 
            //notice index is used instead of i. refer trace in your notebook. or use i and do dry run and you will observe that solutions are INCOMPLETE for every test case.

            swap(nums[index],nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();

        vector<int> temp;

        recurse(nums,ans,0);

        return ans;
        
    }
};