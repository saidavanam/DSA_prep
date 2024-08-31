class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>> ans;

        if(root==nullptr)
        {
            return ans;
        }

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            int size = q.size();
            vector<int> level;

            while(size--)
            {
                TreeNode* last_node = q.front();
                if(last_node->left)
                {
                    q.push(last_node->left);
                }
                if(last_node->right)
                {
                    q.push(last_node->right);
                }
                level.push_back(last_node->val);
                q.pop();
            }
            ans.push_back(level);
        }

        return ans;
    }
};