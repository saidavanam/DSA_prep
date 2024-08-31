
https://www.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1

//PRE REQUISTES :- LEVEL ORDER TRAVERSAL,VERTICAL ORDER TRAVERSAL 

/*
Do level order traversal and insert elements into map. append last element of every column to map.
*/

vector <int> bottomView(Node *root)
{
        vector<int> ans;
        map<int,int> ele;
        
        queue<pair<Node*,int>> nodes;
        nodes.push({root,0});
        
        while(!nodes.empty())
        {
            auto front = nodes.front();
            nodes.pop();
            
            ele[front.second] = front.first->data;   
            
            if(front.first->left)
            {
                nodes.push({front.first->left,front.second-1});
            }
            
            if(front.first->right)
            {
                nodes.push({front.first->right,front.second+1});
            }
            
        }
        
        for(auto it=ele.begin();it!=ele.end();it++)
        {
            ans.push_back(it->second);
        }
        
        return ans;
        
}