#include <iostream>
#include <vector>
#include <queue>
#include <bits/stdc++.h>

using namespace std;

vector<int> dijkstra(vector<vector<pair<int,int>>> graph, int start)
{
    vector <int> dist;
    for(int i=0;i<9;i++)
    {
        dist.push_back(INT_MAX);
    }
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    
    pq.push(make_pair(0,start));
    dist[start]=0;
    while(!pq.empty())
    {
        auto u = pq.top().second;
        pq.pop();
            for(int i = 0; i < graph[u].size(); i++)
        {
            int v = graph[u][i].first;
            int weight = graph[u][i].second;

            if (dist[v] > dist[u] + weight)
            {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
    return dist;
    
}

void addEdge(vector<vector<pair<int,int>>>& graph, int u, int v, int w)
{
    graph[u].push_back(make_pair(v, w));
    graph[v].push_back(make_pair(u, w));
}

int main()
{
    vector<vector<pair<int,int>>> graph(9, vector<pair<int,int>>(9));

    addEdge(graph, 0, 1, 4);
    addEdge(graph, 0, 7, 8);
    addEdge(graph, 1, 2, 8);
    addEdge(graph, 1, 7, 11);
    addEdge(graph, 2, 3, 7);
    addEdge(graph, 2, 8, 2);
    addEdge(graph, 2, 5, 4);
    addEdge(graph, 3, 4, 9);
    addEdge(graph, 3, 5, 14);
    addEdge(graph, 4, 5, 10);
    addEdge(graph, 5, 6, 2);
    addEdge(graph, 6, 7, 1);
    addEdge(graph, 6, 8, 6);
    addEdge(graph, 7, 8, 7);

    vector<int> dist = dijkstra(graph, 0);
     cout << "Vertex      Distance from Source" << endl;
    for (int i = 0; i < 9; ++i)
        cout << i << "\t\t\t" << dist[i] << endl;
    return 0;
}