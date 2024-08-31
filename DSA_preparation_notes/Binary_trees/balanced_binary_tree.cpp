//leetcode problem 110

/*
A balanced binary tree is a binary tree that follows the 3 conditions:
The height of the left and right tree for any node does not differ by more than 1.
The left subtree of that node is also balanced.
The right subtree of that node is also balanced.

abs(left-right)<=1

*/

//whenever u get subtree is not balanced return -1 to previous nodes or else return height of subtree.

class Solution {
public:
    int height(TreeNode*root)
    {
        if(root==nullptr)
        {
            return 0;
        }
        int left = height(root->left);
        int right = height(root->right);
        if(left==-1 || right==-1)
        {
            return -1;
        }
        if(abs(left-right)>1)
        {
            return -1;
        }
        return 1+max(left,right);

    }
    bool isBalanced(TreeNode* root) {

        int result = height(root);
        if(result==-1)
        {
            return false;
        }
        return true;
        
    }
};