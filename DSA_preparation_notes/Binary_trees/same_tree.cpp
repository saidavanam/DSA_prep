//leetcode problem 100

//analogous to post order traversal

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        if(p!=nullptr && q==nullptr)
        {
            return false;
        }
        else if(p==nullptr && q!=nullptr)
        {
            return false;
        }
        else if(p==nullptr && q==nullptr)
        {
            return true;
        }
        else if(p->val != q->val)
        {
            return false;
        }
        bool left = isSameTree(p->left,q->left);
        bool right = isSameTree(p->right,q->right);
        if(!left || !right)
        {
            return false;
        }
        return true;
        
        
    }
};