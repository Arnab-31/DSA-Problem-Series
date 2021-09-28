#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution {
  public:
   
    bool checkForCycle(int s, vector<int> adj[], vector<int>& visited,  vector<int>& rec)
    {
        visited[s]=1;
        rec[s] = 1;
        for (auto it : adj[s]) {
            if (visited[it]==0) {
                if(checkForCycle(it, adj, visited, rec)){
                    //cout<<it<<endl;
                    return true;
                }
                    
            }
            else if(rec[it]==1)    //if node present in the current traversed path, then its a cycle 
                return true;
        }
        
        rec[s]=0;
        
        return false;
    }
public:
	bool isCyclic(int V, vector<int>adj[]){
	    vector<int> vis(V, 0); 
	    vector<int> rec(V, 0); 
	    for(int i = 0;i<V;i++) {
	        if(vis[i] == 0) {
	            if(checkForCycle(i, adj, vis, rec)) return true; 
	        }
	    }
	    
	    return false; 
	}
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends