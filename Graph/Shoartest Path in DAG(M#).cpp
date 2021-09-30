#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
#include <stack>
#define INT_MAX 10000
#define ll long long int
using namespace std;

class Solution{
public:
	void topoSort(int v, vector<pair<int,int>>adj[], stack<int>&st, int vis[]){

		vis[v] = 1;
		for(auto i: adj[v]){
			if(vis[i.first]==0){
				topoSort(i.first,adj,st,vis);
			}
		}

		st.push(v);
	}
	void shortestPath(int src,int V, vector<pair<int,int>>adj[]){
		stack<int>st;
		int vis[V]={0};

		for(int i=0;i<V;i++){
			if(vis[i]==0)
				topoSort(i,adj,st,vis);
		}	


		int dis[V] = {INT_MAX};
		for (int i = 0; i < V; i++) 
			dis[i] = 1e9; 

		
		dis[src] = 0;
	

		while(!st.empty()){
			int node = st.top();
			st.pop();

			if(dis[node]!=INT_MAX){
				for(auto i:adj[node]){			
					if(dis[i.first] > i.second + dis[node]){
						dis[i.first] = i.second + dis[node];
					}
				}
			}
		}


		for (int i = 0; i < V; i++) 
			(dis[i] == 1e9)? cout << "INF ": cout << dis[i] << " "; 
		
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

    	vector<pair<int,int>> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v, w;
    		cin >> u >> v >> w;
    		adj[u].push_back({v,w});
    	}

    	Solution obj;
    	obj.shortestPath(0,V, adj);
    }

    return 0;
}