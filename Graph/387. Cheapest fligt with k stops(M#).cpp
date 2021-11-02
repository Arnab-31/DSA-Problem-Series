//https://leetcode.com/problems/cheapest-flights-within-k-stops/

//Approach - Refer 



class Solution {
public:
     int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<vector<pair<int,int>>> g(n);
        for(auto x : flights){
            g[x[0]].push_back({x[1],x[2]});
        }
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>pq;
        
        vector<int> dist(n+1, INT_MAX);   //to avoid tle
	
        pq.push(make_tuple(0,src,0));
        while(!pq.empty()){
            
            auto [costs,u,stops] = pq.top();
            pq.pop();
            if(dist[u]< stops) continue;  // to avoid tle
		    dist[u]= stops;
            if(u == dst)return costs;
            if(stops>k)continue;
            for(auto child : g[u]){
                auto [v,w] = child;
                pq.push(make_tuple(costs+w,v,stops+1));
            }
        }
        return -1;       
    }
};