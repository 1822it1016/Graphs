#include<bits/stdc++.h>
using namespace std;

bool cycleDFS(int u,vector<int> adj[],bool vis[],int parent)
{
    vis[u]=true;
    for(auto it: adj[u])
    {
     if (!vis[it])
        {
           if (cycleDFS(it,adj, vis, u))
              return true;
        }
        else if (it != parent)
           return true;
    }
    return false;
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

cout<<cycleDFS(0,adj,vis,-1);
}