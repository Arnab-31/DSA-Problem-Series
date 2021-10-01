#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
#include <stack>
#include<queue>
#define INT_MAX 2147483647
#define ll long long int


#include<iostream>
using namespace std;

class Solution{
public:
	
	void spanningTree(vector<pair<int,int>>adj[], int v){
		
		

		priority_queue< pair<int,int>, vector <pair<int,int>> , greater<pair<int,int>> > pq;

		
		pq.push({0,0});

		int MST[v] = {0};
		int parent[v];
		int key[v] = {INT_MAX};

    	for (int i = 0; i < v; i++) 
        	key[i] = INT_MAX, MST[i] = 0;

   	    key[0] = 0;

		while(!pq.empty()){

			int b = pq.top().second;			
			pq.pop();

		
			MST[b] = 1;
			
			
			for(auto i: adj[b]){

				if(MST[i.first]==0 && key[i.first] > i.second){
					key[i.first] = i.second;
					parent[i.first] = b;
					pq.push({i.second,i.first});
				}
				
			}
		}

		for (int i = 1; i < v; i++) 
        	cout << parent[i] << " - " << i <<" \n"; 
	
	}

};


int main()
{
    
   int t;
   cin>>t;

   while(t--){
   	int V,E;

   	cin>>V>>E;

   	vector<pair<int,int>>adj[V];

   	for(int i=0;i<E;i++){
   		int a,b,wt;
   		cin>>a>>b>>wt;

   		adj[a].push_back({b,wt});
   		adj[b].push_back({a,wt});
   	}

   	Solution obj;
   	obj.spanningTree(adj,V);
   }

    return 0;
}