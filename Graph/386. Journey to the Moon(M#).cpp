//https://www.hackerrank.com/challenges/journey-to-the-moon/problem

//Approach - We need to find no of elements in each country. For that we create a graph by drawing an edge betwween all given astraonauts pairs.
//Now the number of DFS requred to traverse the entire graph will give the no of countries,and the number of elements traversed in each fo the DFS will give the 
//number of elements in that country. If some node doest have any edge, its DFS will give only one element. Now to find the answer multiply no of elements in one country to
//all elemnents not in the country. Do it for every country and keep adding the result. The final answer will be half of the final result as we took all combination of pairs twice during the calculation.


int DFS(vector<int>adj[], int v, bool vis[], int c){
    c++;
    
    for(auto i: adj[v]){
        if(!vis[i]){
            vis[i]  = true;
            c  = DFS(adj, i, vis, c);
            cout<<i<<endl;
        }
    }.
    
    cout<<"h"<<endl;
    
    return c;
}

long long journeyToMoon(int n, vector<vector<int>> a) {
    
    vector<int>adj[n];
    bool flag[n] = {false}; 
    
    for(int i=0;i<a.size();i++){
        int p = a[i][0];
        int q = a[i][1];
        
        adj[p].push_back(q);
        adj[q].push_back(p);
        
        flag[p] = true;
        flag[q] = true;
    }
    
    vector<int>count;
    bool vis[n] = {false};
    
    long long total = 0;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            vis[i] = true;
            int c = DFS(adj, i, vis, 0);
            cout<<c<<" count "<<endl;
            count.push_back(c);
            total = total + c;
        }
    }
    
  
    
    long long  ans = 0;
    for(int i=0;i<count.size();i++){
        ans = ans + (count[i] * (total - count[i]));
    }
    
    
    return ans/2;
                    
}
