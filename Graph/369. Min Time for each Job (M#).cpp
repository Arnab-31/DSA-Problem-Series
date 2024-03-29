https://www.geeksforgeeks.org/minimum-time-taken-by-each-job-to-be-completed-given-by-a-directed-acyclic-graph/

(Topological sort using BFS)

#include <bits/stdc++.h>
#define maxN 1000

using namespace std;

vector<int> graph[maxN];
vector <int> inDegree(maxN, 0);

void addEdge(int a, int b)
{
    graph[a].push_back(b);
    inDegree[b]++;
}

void printOrder(int n)
{
    queue<int>q;
    int time = 1;
    int timeArr[n];

    for(int i=1;i<=n;i++)
    {
        if(inDegree[i]==0)
        {
            q.push(i);
            timeArr[i]=time;
        }
    }

    while(!q.empty())
    {
        int x = q.front();
        q.pop();

        time = timeArr[x];

        for(auto i:graph[x])
        {
            inDegree[i]--;   //update indegree of all the neigbours of the deleted node

            if(inDegree[i]==0)
            {
                q.push(i);
                timeArr[i]=time + 1;
            }
        }

    }

    for(int i=1;i<=n;i++)
        cout<<timeArr[i]<<" ";

}

int main()
{

    // Given Nodes N
    int n;
    n = 7;

    // Given Directed Edges of graph
    addEdge(1, 2);
    addEdge(2, 3);
    addEdge(2, 4);
    addEdge(2, 5);
    addEdge(3, 6);
    addEdge(4, 6);
    addEdge(5, 7);

    // Function Call
    printOrder(n);
    return 0;
}