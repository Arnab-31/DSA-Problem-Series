Question: https://practice.geeksforgeeks.org/problems/steps-by-knight5927/1#

Solution: 

int visited [1001][1001]={0};
bool isPossible (int a,int b,int N)
{
    if(a>=1 && b>=1 && a<=N && b<=N && visited[a][b]==0)
        return true;
    return false;
}

int findstep (int a,int b,int t1,int t2,int N)
{
    
   queue <pair<int,int>> q;
   int step = 0;
   
   int dx[8] = {2,2,1,1,-1,-1,-2,-2};
   int dy[8] = {1,-1,2,-2,2,-2,1,-1};
   
   if(a==t1 && b==t2)
        return 0;
        
   q.push(make_pair(a,b));
   visited[a][b] = 1;
 
   
   while(!q.empty())
   {
       
        pair<int,int> c = q.front();
        q.pop();
        
        int x = c.first;
        int y = c.second;
        
        for(int i=0;i<8;i++)
        {
            if(isPossible(x+dx[i],y+dy[i],N))
            {
                if(((x+dx[i]) == t1) && ((y+dy[i]) == t2))
                {
                    return visited[x][y];
                }
                    
                q.push(make_pair(x+dx[i],y+dy[i]));
                visited[x+dx[i]][y+dy[i]] = 1 + visited[x][y];
            }
        }
   }
}


int minStepToReachTarget(int knightPos[], int targetPos[], int N) {
    memset(visited, 0, sizeof visited);

    int a = knightPos[0];
    int b = knightPos[1];
    
    int t1 = targetPos[0];
    int t2 = targetPos[1];
    
    int s = findstep(a,b,t1,t2,N);
    
    return s;
}