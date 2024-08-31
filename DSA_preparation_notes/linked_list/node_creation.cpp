#include<iostream>
#include<vector>

using namespace std;

struct Node
{
    int data;
    struct Node*next;

    Node(int data1,Node* next1)
    {
        data = data1;
        next = next1;

    }
};

int main()
{
    vector<int> v = {1,3,4,5};

    Node *node = new Node(v[0],nullptr);

    cout<<node->data;
}