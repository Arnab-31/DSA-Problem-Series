//https://leetcode.com/problems/validate-binary-search-tree/

//Every node has a range of valid possible values in BST (mi,ma). Use it to check every node.
//TC - O(N)
//SC- O(N)


class Solution {
public:

    bool isValid (TreeNode* root, long long mi, long long ma){
        if(root -> val > mi && root -> val < ma )
            return true;
        else
            return false;
    }
                  
                  
    bool isValidBST(TreeNode* root,  long long mi = LLONG_MIN,  long long ma = LLONG_MAX) {
        
        
        if(root == NULL)
            return true;
       
        
        if(isValid(root, mi, ma)){
            return (isValidBST(root -> left, mi, root->val) && isValidBST(root -> right, root->val, ma));
        }

        return false;
    }
};

    