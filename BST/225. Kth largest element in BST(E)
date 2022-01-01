

class Solution
{
    public:
    
    vector<int>v;
    void inorder(Node *root){
        if(root){
            inorder(root->left);
            v.push_back(root->data);
            inorder(root->right);
        }
    }
    int kthLargest(Node *root, int K)
    {
        //Your code here
        inorder(root);
        return v[v.size()-K];
    }
};