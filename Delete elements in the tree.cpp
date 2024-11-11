#include <bits/stdc++.h>
using namespace std;
//creation of tree elements on class
class Node
{
public:    
    int key;
    Node*left,*right;
};
//creation of newnode
Node* newnode(int data)
{
    Node* n=new Node();
    n->key=data;
    n->left=NULL;
    n->right=NULL;
    return n;
}
//deleting last elements
Node* delete_last(Node* root)
{
    if(root==NULL)
    {
        cout<<"no elements"<<endl;
    }
    else
    {
        queue<Node*> q;
        q.push(root);
        Node*present =q.front();
        Node* prev=NULL;
        while(!q.empty())
        {
            if(present->left==NULL)
            {
               prev->right=NULL;    
            }
            if(present->right==NULL)
            {
                present->left=NULL;
            }
            if(present->left!=NULL)
            {
                q.push(present->left);
            }
            if(present->right!=NULL)
            {
                q.push(present->right);
            }
            prev =present;
            q.pop();
            present=q.front();
        }
    }
    return root;
}
//delete the element
Node* delete_element(int data,Node*root)
{
    if(root==NULL)
    {
        cout<<"no elements"<<endl;
    }
    else{
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            Node*present=q.front();
            q.pop();
            if(present->key==data)
            {
                present->key=find_last(root);
                root=delete_last(root);
            }
            if(present->left!=NULL)
            {
                q.push(present->left);
            }
            if(present->right != NULL)
            {
                q.push(present->right);
            }
        }
    }
    cout<<endl;
    return root;
}
