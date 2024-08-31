https://www.geeksforgeeks.org/problems/top-view-of-binary-tree/1

//PRE REQUISTES :- LEVEL ORDER TRAVERSAL,VERTICAL ORDER TRAVERSAL 

/*
Do level order traversal and insert elements into map. key being column position and values are root values.insert only WHEN KEY IS NOT FOUND.
*/


vector<int> topView(Node *root)
    {
        vector<int> ans;
        map<int,int> ele;
        
        queue<pair<Node*,int>> nodes;
        nodes.push({root,0});
        
        while(!nodes.empty())
        {
            auto front = nodes.front();
            nodes.pop();
            
            if(ele.find(front.second)==ele.end())
            {
                ele[front.second] = front.first->data;   
            }
            
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