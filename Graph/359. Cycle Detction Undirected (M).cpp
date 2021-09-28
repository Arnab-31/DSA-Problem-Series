#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    public:
    bool checkForCycleBFS(int s, int V, vector<int> adj[], vector<int>& visited)
    {
        vector<int> parent(V, -1);
     
        // Create a queue for BFS
        queue<pair<int,int>> q;
     
        visited[s] = true;
        q.push({s, -1});
     
        while (!q.empty()) {
     
            int node = q.front().first;
            int par = q.front().second;
            q.pop();
     
            for (auto it : adj[node]) {
                if (!visited[it]) {
                    visited[it] = true;
                    q.push({it, node});
                }
                else if (par != it)   //if node is already viisited and not the parent of current node
                    return true;
            }
        }
        return false;
    }
    
    bool checkForCycleDFS(int s, int V, vector<int> adj[], vector<int>& visited, int parent)
    {
        visited[s]=1;
        
        for (auto it : adj[s]) {
                if (!visited[it]) {
                    if(checkForCycle(it, V, adj, visited, s)){
                        //cout<<it<<endl;
                        return true;
                    }
                        
                }
                else if(it!=parent)
                    return true;
            }
        
        return false;
    }
public:
	bool isCycle(int V, vector<int>adj[]){
	    vector<int> vis(V, 0); 
	    for(int i = 0;i<V;i++) {           //graph can we disconnected so check for every node, in case they are left unvisited
	        if(!vis[i]) {
	            if(checkForCycle(i, V, adj, vis,-1)) return true; 
	        }
	    }
	    
	    return false; 
	}
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends