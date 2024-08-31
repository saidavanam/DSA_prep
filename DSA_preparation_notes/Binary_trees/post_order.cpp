// postorder iterative using 2 stacks

class Solution{
    public:
    vector<int> postOrder(Node* root) {
        // code here
        
        stack<Node*>s1;
        stack<Node*>s2;
        vector<int> ans;
        s1.push(root);
        
        while(!s1.empty())
        {
            Node *node = s1.top();
            s2.push(node);
            s1.pop();
            
            if(node->left)
            {
                s1.push(node->left);
            }
            if(node->right)
            {
                s1.push(node->right);
            }
        }
        
        while(!s2.empty())
        {
            ans.push_back(s2.top()->data);
            s2.pop();
        }
        
        return ans;
    }
};

//postorder traversal using 1 stack

vector<int> postOrder(Node* root) {
        // code here
        
        stack<Node*>st;
        st.push(root);
        vector<int> postorder;
        Node *curr = root;
        Node *temp = root;
        
        while (!st.empty()) {
        curr = st.top();
        if (curr->left && temp != curr->left && temp != curr->right) {
            st.push(curr->left);
        } else if (curr->right && temp != curr->right) {
            st.push(curr->right);
        } else {
            postorder.push_back(curr->data);
            temp = curr;
            st.pop();
        }
    }
        
        return postorder;
    }

//Recursive Solution

void postorder(TreeNode*root,vector<int> &ans)
{
    if(root==nullptr)
    {
        return;
    }
    postorder(root->left,ans);
    postorder(root->right,ans);
    ans.push_back(root->val);

}