#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ar array

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
    
    vector<ll>dist(n+1,1e10);
    set<ar<ll,2>>s;    // dist,node
    s.insert({0,1});
    dist[1] = dist[0] = 0;
    vector<ll>path(n+1,-1);
    while(!s.empty())
    {
        auto it = *(s.begin());
        ll node = it[1];
        s.erase(it);
        for(auto it : adj[node])
        {
            if(dist[node] + 1 < dist[it])
            {
                if(dist[it] != 1e10)
                    s.erase({dist[it],it});
                path[it] = node;
                dist[it] = dist[node] + 1;
                s.insert({dist[it], it});
            }
        }
    }

    if(dist[n] == 1e10){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    cout<<dist[n]+1<<endl;

    ll v = path[n];
    vector<ll>ans;
    ans.push_back(n);
    while(v^1)
    {
        ans.push_back(v);
        v = path[v];
    }
    ans.push_back(1);
    reverse(ans.begin(),ans.end());
    for(auto it:ans)
        cout<<it<<" ";
    cout<<endl;
}