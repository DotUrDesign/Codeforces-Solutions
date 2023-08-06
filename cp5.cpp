#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ar array

bool dfs(ll node, vector<ll>adj[], vector<ll>& vis,vector<ll>& color,ll col)
{
    vis[node] = 1;
    color[node] = col;
    for(auto it :adj[node])
    {
        if(!vis[it]){
            if(!dfs(it,adj,vis,color,!col))
                return false;
        }
        else if(vis[it] and color[node] == color[it])
            return false;
    }
    return true;
}

int main()
{
    ll n,m; cin>>n>>m;
    vector<ll>adj[n+1];
    for(ll i=0;i<m;i++)
    {
        ll u,v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<ll>color(n+1,-1);
    vector<ll>vis(n+1,0);
    for(ll i=0;i<n;i++)
    {
        if(!vis[i])
            if(!dfs(i,adj,vis,color,1))
            {
                cout<<"IMPOSSIBLE"<<endl;
                return 0;
            }
    }

    for(ll i=1;i<=n;i++){
        color[i] = color[i] == 0 ? 2 : color[i];
        cout<<color[i]<<" ";
    }
    cout<<endl;
}