//https://leetcode.com/problems/trim-a-binary-search-tree/

class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        
        if(!root)
            return root;
        
        if(root -> val >= low && root -> val <= high){
            root->left = trimBST(root->left, low, high);
            root->right = trimBST(root->right, low, high);
            return root;
            
        }else if(root -> val < low){
            
            while(root && root->val < low)
                root=root->right;
            
            return trimBST(root, low, high);
        }else{
            
            while(root && root->val > high)
                root=root->left;
            
            return trimBST(root, low, high);
        }
    }
};