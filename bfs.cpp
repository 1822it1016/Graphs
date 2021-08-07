#include<bits/stdc++.h>
using namespace std;
void BFS(int u,vector<int> adj[],bool vis[])
{
    queue <int> q;
    q.push(u);
    vis[u]=true;
    while(!q.empty())
    {
        int v=q.front();
        cout<<v<<" ";
        q.pop();
        for(auto it: adj[v])
        {
            if(vis[it]==false)
            {
                q.push(it);
                vis[it] = true;
                
            }
        }
        
    }
}


int main(){
    int n=5;
    vector<int> adj[n+1];

        adj[0].push_back(1);
        adj[0].push_back(2);
        adj[1].push_back(0);
        adj[1].push_back(4);
        adj[1].push_back(3);
        adj[2].push_back(0);
        adj[2].push_back(3);
        adj[3].push_back(2);
        adj[3].push_back(1);
        adj[3].push_back(5);
        adj[4].push_back(1);
        adj[5].push_back(4);        
        bool vis[n+1];
    for(int i=0;i<=n;i++)
    {
        vis[i]=false;
    }

    BFS(0,adj,vis);
}
