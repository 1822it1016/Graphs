
#include <bits/stdc++.h>
using namespace std;

void prims(vector<vector<pair<int,int>>> graph, int start)
{
    int parent[5],mst[5],key[5];
    for(int i=0;i<5;i++)
    {
        parent[i]=-1;
        mst[i]=0;
        key[i]=INT_MAX;
    }
    priority_queue <pair<int,int> ,vector<pair<int,int>>, greater<pair<int,int>>> pq;
    key[start]=0;
    pq.push(make_pair(start,0));
    while(!pq.empty())
    {
        int u=pq.top().first;
        
        pq.pop();
        mst[u]=1;
        for(auto it: graph[u])
        {
            int v=it.first;
            int weight=it.second;
            if(mst[v]==0 and weight<key[v])
            {
                parent[v]=u;
                pq.push(make_pair(v,key[v]));
                key[v]=weight;
            }
            
        }
    }
    
    
    for(int i=0;i<5;i++)
    {
     
     cout<<parent[i] << "  "<<i << "  "<<key[i]<<endl;
        
    }
}
void addEdge(vector<vector<pair<int,int>>>& graph, int u, int v, int w)
{
    graph[u].push_back(make_pair(v, w));
    graph[v].push_back(make_pair(u, w));
}

int main()
{
    vector<vector<pair<int,int>>> graph(5, vector<pair<int,int>>(5));

    addEdge(graph, 0, 1, 2);
    addEdge(graph, 0, 3, 6);
    addEdge(graph, 1, 2, 3);
    addEdge(graph, 1, 3, 8);
    addEdge(graph, 1, 4, 5);
    addEdge(graph, 2, 1, 3);
    addEdge(graph, 2, 4, 7);
    addEdge(graph, 3, 0, 6);
    addEdge(graph, 3, 1, 8);
    addEdge(graph, 4, 5, 10);
    addEdge(graph, 4, 2, 7);
    addEdge(graph, 4, 1, 5);
     prims(graph,0);
}