//Check notes of Union Find

class UnionFind {
    int* parent;
    int* rank;
    
    public: 
    
    UnionFind(int size){
        parent = new int[size];
        rank = new int[size];
        
        for(int i=0;i<size;i++){
            parent[i] = i;
            rank[i] = 0;
        }
    }
    
    int findParent(int node){
        
        if(parent[node] == node)
            return node;
        
        return parent[node] = findParent(parent[node]);   //path compression
    }
    
    bool Union(int nodeA, int nodeB){
        
        int parentA = findParent(nodeA);
        int parentB = findParent(nodeB);
        
        if(parentA == parentB)
            return false;
        
        if(rank[parentA] > rank[parentB])  //assign parent based on whose rank is higher
            parent[parentB] = parentA;
        else if(rank[parentB] > rank[parentA])
            parent[parentA] = parentB;
        else{
             parent[parentB] = parentA;  //if rank is same, make any one of them the parent, and increase its rank.
             rank[parentA]++;
        }
        
        return true;
    }
};