//https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

//Approach - Start searching both the elements together in the BST. The point where the search path of both of them differs is the LCA.
//If you reach one of the before that happens , then the found Node is the LCA



class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* cur = root;
        while (true) {
            if (p -> val < cur -> val && q -> val < cur -> val) {
                cur = cur -> left;
            } else if (p -> val > cur -> val && q -> val > cur -> val) {
                cur = cur -> right;
            } else {
                break;
            }
        }
        return cur;
    }
};