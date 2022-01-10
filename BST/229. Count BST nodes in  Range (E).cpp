//https://practice.geeksforgeeks.org/problems/count-bst-nodes-that-lie-in-a-given-range/1


//Function to count number of nodes in BST that lie in the given range.
int getCount(Node *root, int l, int h)
{
  // your code goes here   
  
  if(!root)
    return 0;
  if(root->data >= l && root->data <= h){
      return 1 + getCount(root->left,l,h) + getCount(root->right,l,h);
  }
  else if(root->data < l)
      return getCount(root->right,l,h);
  else 
      return getCount(root->left,l,h);
}
