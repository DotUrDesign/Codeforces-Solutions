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

ll f(vector<pair<ll,ll>>& vec, ll exp, ll n)
{
    ll nums[n] = {0};
    for(ll i=0;i<vec.size();i++)
    {
        if(exp >= vec[i].first and exp <= vec[i].second)
            continue;
        nums[vec[i].first]++;
        nums[vec[i].second+1]--;
    }

    ll maxn = 0;
    for(ll i=0;i<n;i++)
    {
        nums[i] += (i-1 >= 0) ? nums[i-1] : 0;
        maxn = max(maxn, nums[i]);
    }
    return maxn;
}

void solve()
{
    // here we can see that the length of the array is given in the range of 10^9, and iterating over all the elements will surely exceed dour time constraints. Instead, what we can follow is "Compression technigue".

    ll n,m; cin>>n>>m;
    vector<pair<ll,ll>>vec;
    for(ll i=0;i<n;i++)
    {
        ll x, y; cin>>x>>y;
        vec.push_back({x,y});
    }
    
    // array compression
    set<ll>s;
    s.insert(1);
    s.insert(m);
    for(auto it : vec)
    {
        s.insert(it.first);
        s.insert(it.second);
    }

    map<ll,ll>mpp;
    ll x = 1;
    for(auto it : s)
    {
        mpp[it] = x;
        x++; 
    }
    
    for(ll i=0;i<vec.size();i++)
    {
        vec[i].first = mpp[vec[i].first];
        vec[i].second = mpp[vec[i].second];
    }

    // considering 1 as min...
    ll ans1 = f(vec, 1, x+1);
    // considering x-1 as min...
    ll ans2 = f(vec, x-1, x+1);

    cout<<max(ans1, ans2)<<endl;
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