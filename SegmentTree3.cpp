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

class SegTree{

    public:
    vector<ll>seg;
    SegTree(ll n){
        seg.resize(4*n+1);
    }

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
        if(r < low or l > high)
            return INT_MAX;

        // complete overlap  -> l,low,high,r
        if(l <= low and r >= high)
            return seg[idx];

        // partial overlap
        ll mid = low + (high - low)/2;
        ll left = query(2*idx+1, low, mid, l, r);
        ll right = query(2*idx+2, mid+1, high, l, r);
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

    void print()
    {
        for(auto it:seg)
            cout<<it<<" ";
        cout<<endl;
    }

};

void solve()
{
    ll n1; cin>>n1;
    vector<ll>nums1(n1);
    for(ll i=0;i<n1;i++)
        cin>>nums1[i];

    ll n2; cin>>n2;
    vector<ll>nums2(n2);
    for(ll i=0;i<n2;i++)
        cin>>nums2[i];
    
    SegTree seg1(n1);
    seg1.build(0, 0, n1-1, nums1);

    SegTree seg2(n2);
    seg2.build(0, 0, n2-1, nums2);

    // seg1.print();
    // seg2.print();

    ll q;
    cin>>q;
    while(q--)
    {
        ll type; cin>>type;
        if(type == 1)
        {
            ll l1,r1,l2,r2;
            cin>>l1>>r1>>l2>>r2;
            l1--,r1--,l2--,r2--;
            ll val1 = seg1.query(0, 0, n1-1, l1, r1);
            ll val2 = seg2.query(0, 0, n2-1, l2, r2);
            cout<<min(val1, val2)<<endl;
        }
        else
        {
            ll arrNo, i, val;
            cin>>arrNo>>i>>val;
            i--;
            if(arrNo == 1){
                seg1.update(0, 0, n1-1, i, val);
                nums1[i] = val;
            }
            else{
                seg2.update(0, 0, n2-1, i, val);
                nums2[i] = val;
                // seg2.print();
            }
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