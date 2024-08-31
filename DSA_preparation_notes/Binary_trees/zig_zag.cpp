
// leetcode problem 103


class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>> ans;
       
        if(root==nullptr)
        {
            return ans;
        }

        queue<TreeNode*> q;
        q.push(root);
        bool is_left_right = true;

        while(!q.empty())
        {
            int size = q.size();
             vector<int> level(size);
            for(int i=0;i<size;i++)
            {
                TreeNode *node = q.front();
                if(is_left_right)
                {
                    level[i] = node->val;
                }
                else
                {
                    level[size-i-1] = node->val;
                }
                if(node->left)
                {
                    q.push(node->left);
                }
                if(node->right)
                {
                    q.push(node->right);
                }
                q.pop();
            }
            is_left_right = !is_left_right;
            ans.push_back(level);
        }

        return ans;


        
    }
};

// same as level order traversal but reversing the order of the nodes at every level.