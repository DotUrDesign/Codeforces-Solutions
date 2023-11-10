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

vector<int> lg(vector<int>& nums){
    int n = nums.size();
    vector<int> l(n);
    stack<int> st;
    for(int i = 0;i<n;i++){
        while(!st.empty() && st.top() < nums[i]) st.pop();
        if(st.empty()) st.push(nums[i]); 
        l[i] = st.top();
    }
    return l;
}

vector<int> rg(vector<int>& nums){
    int n = nums.size();
    vector<int> r(n);
    stack<int> st;
    for(int i = n-1;i>=0;i--){
        while(!st.empty() && st.top()<nums[i]) st.pop();
        if(st.empty()) st.push(nums[i]);
        r[i] = st.top();
    }
    return r;
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

void solve()
{
    ll n; cin>>n;
    vector<ll>nums(n);
    for(auto &it : nums)
        cin>>it;
    if(n&1)
    {
        ll ans = 0;
        for(ll i=1;i<n;i+=2)
        {
            if(nums[i] > nums[i-1] and nums[i] > nums[i+1])
                continue;
            ans += max(nums[i-1],nums[i+1]) + 1 - nums[i];
        }
        cout<<ans<<endl;
        return;
    }

    vector<ll>pref(n);
    pref[0] = 0;
    for(ll i=1;i<n-1;i++)
    {
        if(i&1)
        {
            ll val = max(0ll, max(nums[i-1], nums[i+1]) +1 - nums[i]);
            pref[i] = val + pref[i-1];
        }
        else
        {
            pref[i] = pref[i-1];
        }
    }
    pref[n-1] = pref[n-2];

    vector<ll>suff(n);
    suff[n-1] = 0;
    for(ll i=n-2;i>0;i--)
    {
        if(!(i&1))
        {
            ll val = max(0ll, max(nums[i-1], nums[i+1]) + 1 - nums[i]);
            suff[i] = val + suff[i+1];
        }
        else
        {
            suff[i] = suff[i+1];
        }
    }
    suff[0] = suff[1];

    // for(auto it : pref)
    //     cout<<it<<" ";
    // cout<<endl;

    // for(auto it : suff)
    //     cout<<it<<" ";
    // cout<<endl;

    ll ans = min(pref[n-1], suff[0]);
    for(ll i=n-2;i>=0;i-=2)
    {
        ans = min(ans,
                        (max(0ll, max(nums[i-1], nums[i+1]) + 1 - nums[i])) + ((i-2 >= 0) ? pref[i-2] : 0) + suff[i+1]
                );
    }
    cout<<ans<<endl;
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