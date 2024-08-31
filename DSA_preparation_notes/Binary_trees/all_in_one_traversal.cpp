#include<iostream>
#include<bits/stdc++.h>

using namespace std;



struct Node
{
    Node* left = nullptr;
    Node* right = nullptr;
    int data;

    Node(int val): data{val},left{nullptr},right{nullptr}{}
};


void traversal(stack<pair<Node*,int>>&st)
{
    vector<int>postorder;
    vector<int>preorder;
    vector<int>inorder;

    while(!st.empty())
    {
        if(st.top().second==1)
      {
        preorder.push_back(st.top().first->data);
        st.top().second++;
        if(st.top().first->left)
        st.push({st.top().first->left,1});
      }
      else if(st.top().second==2)
      {
        inorder.push_back(st.top().first->data);
        st.top().second++;
        if(st.top().first->right)
        st.push({st.top().first->right,1});
      }
      else if(st.top().second==3)
      {
        postorder.push_back(st.top().first->data);
        st.pop();
      }

    }

    cout<<"preorder"<<' ';

    for(int it:preorder)
    {
        cout<<it<<'\n';
    }

    cout<<"inorder"<<' ';

    for(int it:inorder)
    {
        cout<<it<<'\n';
    }

    cout<<"postorder"<<' ';

    for(int it:postorder)
    {
        cout<<it<<'\n';
    }

   
    



}


int main(void)
{

    stack<pair<Node*,int>> st;
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    st.push({root,1});
    traversal(st);

    




}