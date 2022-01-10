//https://leetcode.com/problems/delete-node-in-a-bst/submissions/

/*

             8
        1        5
      2   3    4   7


    The node we want to delete. Its entire left subtree is smaller than its enitre right sub tree. 
    We use this property. We connect the left subtree with the left most node of the right sub tree.
    And the right sub tree is connected with the parent of the node we have to delete.


*/

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int val) {
        if (!root) return root;
        
        if (val < root->val) {
            root->left = deleteNode(root->left, val);
        } else if (val > root->val) {
            root->right = deleteNode(root->right, val);
        } else {
            /* Leaf node case */
            if (!root->left && !root->right) {
                delete(root);
                return NULL;
            }
            /* 1 child case */
            if (!root->left || !root->right) {
                TreeNode *ret = root->left ? root->left : root->right;
                delete(root);
                return ret;
            }
            /* 2 child case */
            if (root->left && root->right) {
                TreeNode *tmp = root->right;
                while (tmp->left) {
                    tmp = tmp->left;
                }
                tmp -> left = root -> left;
                root = root -> right;
               
            }
        }
        return root;
    }
};