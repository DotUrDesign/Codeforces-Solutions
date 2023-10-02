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

ll mod = 998244353;
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

// Function to calculate nCr (n choose r)
ll nCr(ll n, ll r) {
    if (r > n) 
        return 0;
    if (r == 0 || n == r) 
        return 1;

    double res = 0;
    for (ll i = 0; i < r; i++) {
        res += log(n-i) - log(i+1);
    }
    return (ll)round(exp(res));
}

/* 
Template for floating precision...
    cout << fixed << setprecision(0);
*/

/* Template for ordered set */
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using ordered_set =tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update> ;

// Type-1 => Query and Type-2 => Update
vector<ll>seg;

void build(ll idx, ll low, ll high, vector<ll>& nums)
{
    if(low == high)
    {
        seg[idx] = nums[low];
        return;
    }

    ll mid = low + (high - low)/2;
    build(2*idx+1, low, mid, nums);
    build(2*idx+2, mid+1, high, nums);
    seg[idx] = min(seg[2*idx+1] , seg[2*idx+2]);
}

ll query(ll idx, ll low, ll high, ll l, ll r)
{
    // no overlap
    // l,r,low,high or low,high,l,r
    if(r <  low or l > high)
        return INT_MAX;

    // complete overlap
    // l,low,high,r
    if(l <= low and high <= r)
        return seg[idx];

    // partial overlap
    ll mid = low + (high - low)/2;
    ll left = query(2*idx+1, low, mid, l, r);
    ll right = query(2*idx+2, mid+1, high, l ,r);
    return min(left, right);
}

void update(ll idx, ll low, ll high, ll i, ll val)
{
    if(low == high)
    {
        seg[idx] = val;
        return;
    }

    ll mid = low + (high - low)/2;
    if(i <= mid)
        update(2*idx+1, low, mid, i, val);
    else    
        update(2*idx+2, mid+1, high, i, val);
    seg[idx] = min(seg[2*idx+1], seg[2*idx+2]);
}

void solve()
{
    ll n; cin>>n;
    vector<ll>nums(n);
    for(ll i=0;i<n;i++)
        cin>>nums[i];
    
    seg.resize(4*n);
    build(0, 0, n-1, nums); 

    ll q; cin>>q;
    while(q--)
    {
        ll type;cin>>type;
        if(type == 1)
        {
            ll l,r;
            cin>>l>>r;
            l--,r--;
            cout<<query(0, 0, n-1, l, r)<<endl;
        }
        else
        {
            ll i, val;
            cin>>i>>val;
            i--;
            update(0, 0, n-1, i, val);
            nums[i] = val;
        }
    }
}
int main()
{
   // Place the template of  the precision code here...
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
     ll t; cin>>t;
     while(t--)
        solve();
}