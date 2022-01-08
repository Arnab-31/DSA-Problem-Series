//https://practice.geeksforgeeks.org/problems/check-whether-bst-contains-dead-end/1


bool solve(Node *root,int mi,int ma){
    
    if(!root)
        return false;
        
    if( ((root->data - 1) == mi) && ((root->data + 1) == ma) )
      return true;
      
    return solve(root->left,mi,root->data) || solve(root->right,root->data,ma);
    
}
bool isDeadEnd(Node *root)
{
    //Your code here
    return solve(root,0,INT_MAX);
}