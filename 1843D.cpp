 /* 
iiiiiiiiiiii  iiiiiiiiiiii  iiiiiiiiiiii  ttttttttttt
     i             i             i             t
     i             i             i             t
     i             i             i             t
     i             i             i             t
     i             i             i             t
iiiiiiiiiiii  iiiiiiiiiiii  iiiiiiiiiiii       t
*/

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int fcuk = 1000000;
bool sieve[1000001];
void createSieve()
{
    sieve[1] = sieve[0] = false;
    for(ll i=2;i<=fcuk;i++)
        sieve[i] = true;
    for(ll i=2;(i*i)<=fcuk;i++)
    {
        if(sieve[i] == true)
        {
            for(ll j=i*i;j<=fcuk;j+=i)
                sieve[j] = false;
        }
    }
}

int gcd_equation(int a,int b,int& x,int& y)
{
    if(b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    int x1,y1;
    int d = gcd_equation(b,a%b,x1,y1);
    x = y1;
    y = x1 - (y1 * (a/b));
    return d;
}

ll count_bits_kernighan_algo(ll n)
{
    ll counter =0;
    while(n!=0)
    {
        ll rsbm = n&(-n);
        n -= rsbm;
        counter++;
    }
    return counter;
}

bool comparator(const pair<int,int> &a, const pair<int,int> &b)
{
    if(a.first == b.first)
       return a.second>b.second;
    return a.first < b.first;
}

/* BIT MANIPULATION */
/*
#define isOn(S, j) (S & (1 << j))
#define setBit(S, j) (S |= (1 << j))
#define clearBit(S, j) (S &= ~(1 << j))
#define toggleBit(S, j) (S ^= (1 << j))
#define LSB(S) (S & (-S))
#define setAll(S, n) (S = (1 << n) - 1)
#define modulo(S, N) ((S) & (N - 1))   // returns S % N, where N is a power of 2
#define isPowerOfTwo(S) (!(S & (S - 1)))
#define nearestPowerOfTwo(S) ((int)pow(2.0, (int)((log((double)S) / log(2.0)) + 0.5)))
#define turnOffLastBit(S) ((S) & (S - 1))
#define turnOnLastZero(S) ((S) | (S + 1))
#define turnOffLastConsecutiveBits(S) ((S) & (S + 1))
#define turnOnLastConsecutiveZeroes(S) ((S) | (S - 1))
*/

/* 
Template for floating precision...
double pi = 3.14159, npi = -3.14159;
    cout << fixed << setprecision(0) << pi << 
 << npi << endl;
*/

void solve()
{
    ll n; cin>>n;
    vector<ll>adj[n+1];
    for(ll i=0;i<n-1;i++)
    {
        ll u,v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<ll>level(n+1,0);
    map<ll,ll>leaf;
    queue<pair<ll,ll>>q;
    vector<ll>vis(n+1,0);
    q.push({1,0});
    vis[1] = vis[0] = 1;
    while(!q.empty())
    {
        ll node = q.front().first;
        ll lev = q.front().second;
        q.pop();
        level[node] = lev;
        bool flag = true;
        for(auto it:adj[node])
        {
            if(!vis[it])
            {
                vis[it]= 1;
                q.push({it,lev+1});
                flag = false;
            }
        }
        if(flag)
            leaf[node] = 1;
    }
    // ll maxlevel = *max_element(level.begin(),level.end());
    ll que; cin>>que;
    while(que--)
    {
        ll x,y; cin>>x>>y;
        if(leaf.find(x) != leaf.end() and leaf.find(y) != leaf.end())
            cout<<1<<endl;
        else if(leaf.find(x) != leaf.end() or leaf.find(y) != leaf.end())
        {
            if(level[x] == level[y])
                cout<<1<<endl;
            else
                cout<<2<<endl;
        }
        else
            cout<<4<<endl;
    }
}
int main()
{
     ll t; cin>>t;
     while(t--)
        solve();
}