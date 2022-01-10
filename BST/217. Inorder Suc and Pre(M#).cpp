//https://practice.geeksforgeeks.org/problems/predecessor-and-successor/1

/* BST Node
struct Node
{
	int key;
	struct Node *left, *right;
};
*/



Node* inorderSuccessor(Node* root, int k) {
    Node* successor = NULL;
    
    while (root != NULL) {
        
        if (k >= root->key) {
            root = root->right;
        } else {
            successor = root;
            root = root->left;
        }
    }
    return successor;
}


Node* inorderPredecessor(Node* root, int k) {
    Node* predecessor = NULL;
    
    while (root != NULL) {
        
        if (k <= root->key) {
            root = root->left;
        } else {
            predecessor = root;
            root = root->right;
        }
    }
    return predecessor;
}


// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
    pre = inorderPredecessor(root, key);
    suc = inorderSuccessor(root, key);      
}