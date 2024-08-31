//leetcode problem is 124 and explanation is in notes

class Solution {
public:
    int maxPath(TreeNode*root,int &max_value)
    {
        if(root==nullptr)
        {
            return 0;
        }
        int left_sum = max(maxPath(root->left,max_value),0);
        int right_sum = max(maxPath(root->right,max_value),0);

        max_value = max(max_value,root->val+left_sum+right_sum);

        return root->val+max(left_sum,right_sum);
        
        
    }
    int maxPathSum(TreeNode* root) {

        int max_value = INT_MIN;
        maxPath(root,max_value);

        return max_value;
        


        
    }
};