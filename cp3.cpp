#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ar array

void dfs(ll node, vector<ll>adj[], vector<ll>& vis)
{
    vis[node] = 1;
    for(auto it:adj[node])
    {
        if(!vis[it])
            dfs(it,adj,vis);
    }
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
    vector<ar<ll,2>>arr;
    vector<ll>vis(n+1,0);
    for(ll i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            if(i != 1)
                arr.push_back({i,i-1});
            dfs(i,adj,vis);
        }
    }
    cout<<arr.size()<<endl;
    for(auto it:arr)
        cout<<it[0]<<" "<<it[1]<<endl;
}