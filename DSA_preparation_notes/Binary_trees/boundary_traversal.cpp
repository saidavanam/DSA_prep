// https://www.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1

/*

include root value first
include extreme left nodes without leaf
include leaf nodes
include extreme right nodes in reverse order
*/

class Solution {
public:
    bool isleaf(Node*node)
    {
        if(!node->left && !node->right)
        {
            return true;
        }
        return false;
    }

    void left(vector<int>&ans,Node*root)
    {
        Node *curr = root->left; //exclude root
        while(curr)
        {
            if(!isleaf(curr))
            {
                ans.push_back(curr->data);
            }
            if(curr->left)
            {
                curr = curr->left;
            }
            else
            {
                curr= curr->right;
            }
        }
        
        
    }

    void leafnodes(vector<int>&ans,Node*root)
    {
        if(!root)
        {
            return;
        }
        leafnodes(ans,root->left);
        leafnodes(ans,root->right);
        if(isleaf(root))
        {
            ans.push_back(root->data);
        }
    }

    void right(vector<int>&ans,Node*root)
    {
        vector<int> temp;
        Node *curr = root->right; //exclude root
        while(curr)
        {
            if(!isleaf(curr))
            {
                temp.push_back(curr->data);
            }
            if(curr->right)
            {
                curr = curr->right;
            }
            else
            {
                curr= curr->left;
            }
        }
        for(int i=temp.size()-1;i>=0;i--) //appending nodes in reverse order.
        {
            ans.push_back(temp[i]);
        }
        
    }

    vector <int> boundary(Node *root)
    {
        //Your code here
        vector<int> ans;
        if(!root)
        {
            return ans;
        }
        
        if(!isleaf(root))
        {
            ans.push_back(root->data);
        }
        
        left(ans,root);
        leafnodes(ans,root);
        right(ans,root);
        
        
        
        return ans;
    }
};