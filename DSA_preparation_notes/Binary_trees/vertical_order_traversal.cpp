/*

Better solution
Explanation is in your notes

*/ 

class Solution {
public:
    void inorder(TreeNode*root,map<pair<int,int>,priority_queue<int,vector<int>,greater<int>>> &levels,int col,int row)
    {
        if(root==nullptr)
        {
            return;
        }
        inorder(root->left,levels,col-1,row+1);
        levels[{col,row}].push(root->val);
        inorder(root->right,levels,col+1,row+1);

    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {

       
        map<pair<int,int>,priority_queue<int,vector<int>,greater<int>>> levels;

        inorder(root,levels,0,0);
        int min_col = levels.begin()->first.first;
        int max_col = levels.rbegin()->first.first;

        cout<<min_col<<' '<<max_col<<'\n';

         vector<vector<int>> ans(max_col-min_col+1);

        

        for(auto it=levels.begin();it!=levels.end();it++)
        {
           while(!it->second.empty())
           {
              int num = it->second.top();
              ans[it->first.first-min_col].push_back(num);
              it->second.pop();

           }
        }

        return ans;

        
        
    }
};

/*

Time complexity is o(nlogn) + o(n)
Space complexity is o(2n)

*/

/*
Optimal Solution through iterative approach
same time complexity but memory efficient
*/

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        map<int,map<int,multiset<int>>> mpp;
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});

        while(!q.empty())
        {
            auto p = q.front();
            q.pop();
            TreeNode *node = p.first;
            int col = p.second.first;
            int row = p.second.second;
            mpp[col][row].insert(node->val);

            if(node->left)
            {
                q.push({node->left,{col-1,row+1}});
            }
            if(node->right)
            {
                q.push({node->right,{col+1,row+1}});
            }
        }

        vector<vector<int>> ans;

        for(auto it=mpp.begin();it!=mpp.end();it++)
        {
            vector<int> col;
            for(auto jt=it->second.begin();jt!=it->second.end();jt++)
            {
                col.insert(col.end(),jt->second.begin(),jt->second.end());
            }
            ans.push_back(col);
        }

        return ans;
        
    }
};