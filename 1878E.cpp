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

vector<ll>segT;
void build(ll s, ll e, ll i, vector<ll> &nums)
{
     if (s == e)
     {
         segT[i] = nums[s];
         return;
     }
     ll mid = s + (e - s) / 2;
     build(s, mid, 2 * i + 1, nums);
     build(mid + 1, e, 2 * i + 2, nums);
     segT[i] = segT[2 * i + 1] & segT[2 * i + 2];
}

ll check(ll qs, ll qe,ll start, ll end, ll i)
{
     if (qs <= start && qe >= end)
         return segT[i];
     if (qs > end || qe < start)
         return INT_MAX;
     ll mid = start + (end - start) / 2;
     ll left = check(qs, qe,start, mid, 2 * i + 1);
     ll right = check( qs, qe,mid + 1, end, 2 * i + 2);
     return left & right;
}


// bool check(ll mid, ll start , ll k , vector<ll>& nums, ll n)
// {
//     ll ans = nums[start];
//     ll c = start+1;
//     while(true)
//     {
//         if(c > n or (ans&nums[c]) < k)
//             break;
//         ans &= nums[c];
//         c++;
//     }
//     if(c-1 >= mid)
//         return true;
//     return false;
// }

void solve()
{
    ll n; cin>>n;
    vector<ll>nums(n);
    for(ll i=0;i<n;i++)
        cin>>nums[i];
    segT.resize(4 * n);
    build(0, n-1, 0, nums);
    
    ll q; cin>>q;
    ll l,k; 
    while(q--)
    {
        cin>>l>>k;
        l--;
        ll low = l;
        ll high = n-1;
        if(nums[l] < k){
            cout<<-1<<" ";
            continue;
        }
        ll ans = low;
        while(low <= high)
        {
            ll mid = low + (high - low)/2;
            if(check( l, mid,0,n-1,0) < k)
            {
                high = mid-1;
            }
            else{
                ans = mid;
                low = mid+1;
            }
        }
        ans = (ans >= 0) ? ans+1 : ans;
        cout<<ans<<' ';
    }
    cout<<endl;
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