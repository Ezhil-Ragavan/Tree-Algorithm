bool sum_tree(Node* root)
{
    if(root == NULL)
    {
        cout<<"No elements"<<endl;
    }
    else
    {
        queue<Node*>q;
        q.push(root);
        while(!q.empty())
        {
            Node* present = q.front();
            q.pop();
            if(present->left != NULL && present->right != NULL)
            {
                Node* left_element = present->left;
                Node* right_element = present->right;
                int sum = left_element->key + right_element->key;
                if(sum != present->key)
                {
                    return false;
                }
            }
            if(present->left != NULL)
            {
                q.push(present->left);
            }
            if(present->right != NULL)
            {
                q.push(present->right);
            }
        }
    }
    return true;
}
