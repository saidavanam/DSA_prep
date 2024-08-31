
//RECURSIVE SOLUTION
class Solution {
public:
    void preorderTraversal(TreeNode* root,vector<int> &ans)
    {
        if(root==nullptr)
        {
            return;
        }
        ans.push_back(root->val);
        preorderTraversal(root->left,ans);
        preorderTraversal(root->right,ans);
    }
    vector<int> preorderTraversal(TreeNode* root) {

        vector<int> ans;
        preorderTraversal(root,ans);

        return ans;
        
    }
};



//ITERATIVE SOLUTION
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {

        vector<int> ans;
        if(root==nullptr)
        {
            return ans;
        }

        stack<TreeNode*>st;

        st.push(root);

        while(!st.empty())
        {
            TreeNode* root_node = st.top();
            st.pop();
            ans.push_back(root_node->val);

            if(root_node->right)
            {
                st.push(root_node->right);
            }
            if(root_node->left)
            {
                st.push(root_node->left);
            }

            
        }

        return ans;
    }
};