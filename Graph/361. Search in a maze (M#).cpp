Question: https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1#


Solution:

vector <string> ans;
int visited[MAX][MAX]= {0};



bool isPossible(int A[MAX][MAX], int a, int b, int n)
{
    if(a<n && b<n && a>=0 && b>=0 && A[a][b]==1 && visited[a][b]==0)
        return true;
    return false;
}


void Paths(int A[MAX][MAX], int n, int a, int b, string s)
{
    
    
  
    if(a==(n-1) && b==(n-1))
    {
        ans.push_back(s);
        return;
    }
    
    visited[a][b]=1;
    
    if(isPossible(A, a+1, b, n))
        Paths( A, n, a+1, b, s+"D");
    
    if(isPossible(A, a, b+1, n))
        Paths( A, n, a, b+1, s+"R");
    
    if(isPossible(A, a-1, b, n))
        Paths( A, n, a-1, b, s+"U");
    
    if(isPossible(A, a, b-1, n))
        Paths( A, n, a, b-1, s+"L");
        
    visited[a][b]=0;
}


vector<string> printPath(int m[MAX][MAX], int n)
{
    ans.clear();
    memset(visited, 0, sizeof visited);
    
    if(m[0][0] == 0 || m[n-1][n-1]==0)
        return ans;
    
    Paths(m,n,0,0,"");
    
    sort(ans.begin(),ans.end());
    return ans;
}