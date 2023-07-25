#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int optimalPoint(int n, int* magic, int dist_count,int* dist)
{
    vector<ll>pref(n,0);
    pref[0] = magic[0] - dist[0];
    for(ll i=1;i<n;i++)
        pref[i] = pref[i-1] + (magic[i] - dist[i]);
    if(pref[n-1] < 0)
        return -1;
    for(ll i=0;i<n;i++)
    {
        if(magic[i] >= dist[i])
        {
            ll s = 0, j = 0;
            if(i > 0)   j = i;
            while(i < n and s >= 0){
                s += (magic[i] - dist[i]);
                i++;
            }
            if(i == n)
            {
                if(s + pref[j] >= 0)
                    return j;
                else    
                    return -1;
            }
            else 
                i--;
        }
    }
    return -1;
}


int main()
{
    int n,m;
    cin>>n>>m;
    int magic[n];
    for(ll i=0;i<n;i++)
        cin>>magic[i];
    int dist[m];
    for(ll i=0;i<m;i++)
        cin>>dist[i];
    cout<<optimalPoint(n,magic,m,dist);
}