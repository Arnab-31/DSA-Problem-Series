//https://leetcode.com/problems/recover-binary-search-tree/submissions/

//TC - O(N)
//SC - O(1)  -> this is the challenge

//Approach - Detect all the anomalies during inorder (current element is less than the previous one). Either we will get 2 elements in anomaly or 4 elements. 
//If it is two elements, replace them, if it is 4, then replace the first and the last

//Exammple - (inorder) 2,4,5,7,6,8,9 -> Elements in anomaly -> 7,6.     So we replace them
//Example - (inorder) 2,9,4,5,6,7,8,3,10 -> Elements in anomaly -> 9,4,8,3.  Here replace 9 and 3 ( the first and last element)


class Solution {
public:

    TreeNode* n1, *n2;
    TreeNode* parent = NULL;
    void inorder(TreeNode* root){
        if(root){
            inorder(root->left);
            
            if(parent && root->val < parent -> val){
                if(n1){
                    n2 = root;
                    return;
                }else{
                    n1 = parent;
                    n2 = root;
                }
            }
            
            parent = root;
            
            inorder(root->right);
        } 
    }
 
    
    void recoverTree(TreeNode* root) {
        inorder(root);
        swap(n1->val, n2->val);
    }
};