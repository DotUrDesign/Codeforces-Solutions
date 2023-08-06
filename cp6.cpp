#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ar array

void dfs(ll node, ll parent, vector<ll>adj[], vector<ll>& vis,vector<ll>& path)
{
    vis[node] = 1;
    for(auto it:adj[node])
    {
        if(!vis[it]){
            path[it] = node;
            dfs(it,node,adj,vis,path);
        }
        else if(vis[it] and it != parent)
        {
            path[it] = node;
            ll v = node;
            ll u = it;
            vector<ll>ans;
            ans.push_back(node);
            while(v ^ u)
            {
                v = path[v];
                ans.push_back(v);
            }
            ans.push_back(node);
            reverse(ans.begin(),ans.end());
            cout<<ans.size()<<endl;
            for(auto it:ans)
                cout<<it<<" ";
            cout<<endl;
            exit(0);
        }
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
    
    vector<ll>path(n+1,-1);
    vector<ll>vis(n+1,0);
    for(ll i=1;i<=n;i++){
        if(!vis[i])
            dfs(i,-1,adj,vis,path);
    }
    cout<<"IMPOSSIBLE"<<endl;
}