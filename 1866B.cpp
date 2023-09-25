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
#define ar array

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
    cout << fixed << setprecision(0);
*/

/* Template for ordered set */
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using ordered_set =tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update> ;

ll mod =  998244353;
ll power(ll x, ll n)
{
    ll ans = 1;
    long long nn = n;
    if (nn < 0) nn = -1 * nn;
    while (nn) {
        if (nn % 2) {
        ans = (ans%mod * x%mod)%mod;
        nn = nn - 1;
        } else {
        x = (x%mod * x%mod)%mod;
        nn = nn / 2;
        }
    }
    if (n < 0) ans = 1/ans;
    return ans%mod;
}

void solve()
{
    ll n ;cin>>n;
    vector<ll>p1(n), ex1(n);
    for(ll i=0;i<n;i++) cin>>p1[i];
    for(ll i=0;i<n;i++) cin>>ex1[i];

    ll m; cin>>m;
    vector<ll>p2(m), ex2(m);
    for(ll i=0;i<m;i++) cin>>p2[i];
    for(ll i=0;i<m;i++) cin>>ex2[i];

    map<ll,ll>mpp1;
    for(ll i=0;i<n;i++) 
        mpp1[p1[i]] = ex1[i];

    map<ll,ll>mpp2;
    for(ll i=0;i<m;i++)
        mpp2[p2[i]] = ex2[i];
    
    bool f1 = true, f2 = true;
    for(auto it: mpp1)
    {
        if(mpp2.find(it.first) == mpp2.end() or mpp2[it.first] < it.second)
        {
            f1 = false;
            break;
        }
    }

    for(auto it: mpp2)
    {
        if(mpp1.find(it.first) == mpp1.end() or mpp1[it.first] < it.second)
        {
            f2 = false;
            break;
        }
    }

    if(f1 and f2){
        cout<<1<<endl;
        return;
    }
    else if(!f1 and !f2 or f1 and !f2){
        cout<<0<<endl;
        return;
    }
    ll cnt = 0;
    for(auto it:mpp1)
    {
        if(mpp2.find(it.first) == mpp2.end() or mpp2[it.first] < it.second)
            cnt++;
    }
    cout<<(ll)power(2,cnt)<<endl;
}
int main()
{
   // Place the template of  the precision code here...
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
    //  ll t; cin>>t;
    //  while(t--)
        solve();
}   