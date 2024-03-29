Question:  https://practice.geeksforgeeks.org/problems/topological-sort/1#


Solution: 

int visited[10000] = {0};
vector <int> ans;

void DFS (int src, vector<int> adj[])
{
    visited[src] = 1;
    
    for(auto i: adj[src])
    {
        if(visited[i]==0)
            DFS(i,adj);
    }
    ans.push_back(src);
    
}

vector<int> topoSort(int V, vector<int> adj[]) {
    // Your code here
    memset(visited, 0, sizeof visited);
    ans.clear();
    
    for(int i=0;i<V;i++)
    {
        if(visited[i]==0)
            DFS(i,adj);
    }
    
    reverse(ans.begin(), ans.end()); 
    return ans;
}