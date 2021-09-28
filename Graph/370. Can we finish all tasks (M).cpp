Question: https://www.geeksforgeeks.org/find-whether-it-is-possible-to-finish-all-tasks-or-not-from-given-dependencies/


Solution: Check for cycle

#include <bits/stdc++.h>
#define maxN 1000

using namespace std;

vector <int> graph[maxN];
int visited[maxN]={0};
int backEdge[maxN]={0};

void addEdge(int a, int b)
{
    graph[a].push_back(b);
}

bool checkUtil(int x, int n)
{
    if(visited[x]==1)
        return true;

    visited[x]=1;
    backEdge[x]=1;
    for(auto i: graph[x])
    {
        if(backEdge[i]==1)
        {
            cout<<i<<" "<<x<<endl;
            return false;
        }


        if(!checkUtil(i,n))
            return false;
    }
    backEdge[x]=0;
    return true;
}

bool check(int edges[][2], int n)
{

    for(int i=0;i<=n;i++)
    {
        if(!checkUtil(i,n))
            return false;
    }

    return true;
}

int main()
{
    int n = 4;    //0 to n nodes present
    int edges[maxN][2] = {{1, 0},{1,2},{2,3},{0,4}};

    for(int i=0;i<n;i++)
        addEdge(edges[i][1],edges[i][0]);

    bool b = check(edges, n);

    if(b)
        cout<<"It is possible to complete all the tasks";
    else
        cout<<"It is not possible to complete all the tasks";

    return 0;
}