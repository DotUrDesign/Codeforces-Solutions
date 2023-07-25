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

/* Template for ordered set */
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using ordered_set =tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update> ;

void solve()
{
    ll n,m; cin>>n>>m;
    vector<vector<char>>arr(n, vector<char>(m));
    ll sr,sc,dr,dc;
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<m;j++){
            cin>>arr[i][j];
            if(arr[i][j] == 'A')
                sr = i, sc = j;
            if(arr[i][j] == 'B')
                dr = i, dc = j;
        }
    }
    if(sr == dr and sc == dc)
    {
        cout<<"YES"<<endl;
        cout<<0<<endl;
    }
    vector<vector<ll>>vis(n,vector<ll>(m,0));
    vector<vector<pair<ll,ll>>>path(1000,vector<pair<ll,ll>>(1000,{-1,-1}));
    vis[sr][sc] = 1;
    ll drow[] = {-1,0,1,0};
    ll dcol[] = {0,1,0,-1};
    queue<pair<ll,ll>>q;
    q.push({sr,sc});
    while(!q.empty())
    {
        auto it = q.front();
        ll row = it.first;
        ll col = it.second;
        q.pop();
        for(ll i=0;i<4;i++)
        {
            ll nrow = row + drow[i];
            ll ncol = col + dcol[i];
            if(nrow >= 0 and nrow < n and ncol >= 0 and ncol < m and !vis[nrow][ncol] and (arr[nrow][ncol] == '.' or arr[nrow][ncol] == 'B'))
            {
                vis[nrow][ncol] = 1;
                path[nrow][ncol] = {row,col};
                if(nrow == dr and ncol == dc)
                {
                    ll pu = nrow , pv = ncol;
                    auto it = path[pu][pv];
                    ll u = it.first;
                    ll v = it.second;
                    string ans = "";
                    ll cnt = 0;
                    while(u != -1 and v != -1)
                    {
                        if(u - 1 == pu) ans += 'U';
                        else if(u +1 == pu) ans += 'D';
                        else if(v +1 == pv) ans += 'R';
                        else if(v - 1 == pv) ans += 'L';
                        pu = u, pv = v;
                        auto it = path[pu][pv];
                        u = it.first;
                        v = it.second;
                    }
                    reverse(ans.begin(), ans.end());
                    cout<<"YES"<<endl;
                    cout<<ans.size()<<endl;
                    cout<<ans<<endl;
                    return;
                }
                q.push({nrow,ncol});
            }
        }
    }
    cout<<"NO"<<endl;
}
int main()
{
        solve();
}