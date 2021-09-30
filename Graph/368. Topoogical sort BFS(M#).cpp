

include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> topo(int N, vector<int> adj[]) {
        queue<int> q; 
	    vector<int> indegree(N, 0); 
	    for(int i = 0;i<N;i++) {   //Creating the indegree array
	        for(auto it: adj[i]) {
	            indegree[it]++; 
	        }
	    }
	    
	    for(int i = 0;i<N;i++) {
	        if(indegree[i] == 0) {   //if indegree 0 ,push ton queue
	            q.push(i); 
	        }
	    }
	    vector<int> topo
	    while(!q.empty()) {   //start BFS with the nodes of indegree 0
	        int node = q.front(); 
	        q.pop(); 
	        topo.push_back(node)
	        for(auto it : adj[node]) {
	            indegree[it]--;           
	            if(indegree[it] == 0) {       //reduce indegree of neighbouring nodes, if it become 0, add to queue
	                q.push(it); 
	            }
	        }
	    }
	    return topo;
	}
};



int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}