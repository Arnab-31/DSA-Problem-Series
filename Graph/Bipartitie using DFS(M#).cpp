
//https://practice.geeksforgeeks.org/problems/bipartite-graph/1
//Checking if graph is bipartite using DFS
//Approach - Maintain a index array for storing the colors of each index. If while doing DFS
//you find a node which is already visited and have same color as current node, means it s bipartite graph

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkForCycle(int s, int V, vector<int> adj[], vector<int>& visited, vector<int> &index, int color)
    {
        visited[s]=1;
        index[s] = color;
        for (auto it : adj[s]) {
                if (!visited[it]) {
                    if(checkForCycle(it, V, adj, visited,index,!color)){
                        //cout<<it<<endl;
                        return true;
                    }
                        
                }
                else if(index[it] == color)
                    return true;

            }
        
        return false;
    }
    
	bool isBipartite(int V, vector<int>adj[]){
	    vector<int> vis(V, 0); 
	    vector<int> index(V, -1);
	    for(int i = 0;i<V;i++) {           //graph can we disconnected so check for every node, in case they are left unvisited
	        if(vis[i]==0) {
	            if(checkForCycle(i, V, adj, vis,index, 1)) return false; 
	        }
	    }
	    
	    return true; 
	}

};


int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}  