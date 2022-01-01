
//https://practice.geeksforgeeks.org/problems/binary-tree-to-bst/1#

//Approach - Find inorder by sorting all elements. Now do an inorder of the binary tree, replace the elemnets at positions which does not match with the inorder of the BST found by sorting.


class Solution{
  public:
    // The given root is the root of the Binary Tree
    // Return the root of the generated BST
    vector<int>v;
    void inorder(Node *root){
        if(root){
            inorder(root->left);
            v.push_back(root->data);
            inorder(root->right);
        }
    }
    
    void inorderSwap(Node *root, int &i){
        if(root){
            inorderSwap(root->left,i);
            root->data = v[i];
            i = i+1;
            inorderSwap(root->right,i);
        }
    }

    Node *binaryTreeToBST (Node *root)
    {
        //Your code goes here
        
       
        inorder(root);
       
        sort(v.begin(),v.end());
        
        int i=0;
        inorderSwap(root,i);
        
        return root;
        
    }
};