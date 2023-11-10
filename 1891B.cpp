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

ll LSB(ll n)
{
    for(ll i=0;i<31;i++)
    {
        if((1<<i)&n)
            return i;
    }
    return -1;
}

void solve()
{
    ll n, q;
    cin>>n>>q;
    vector<ll>nums(n);
    for(auto &it:nums)
        cin>>it;
    vector<ll>x(q);
    for(auto &it:x)
        cin>>it;
    
    set<ll>s;
    vector<ll>query;
    for(auto it : x)
    {
        if(s.find(it) == s.end())
        {
            s.insert(it);
            query.push_back(it);
        }
    }

    // for(auto it : query)
    //     cout<<it<<" ";
    // cout<<endl;

    for(ll i=0;i<n;i++)
    {
        ll lsb = LSB(nums[i]);
        for(ll j=0;j<query.size();j++)
        {
            if(lsb >= query[j])
            {
                nums[i] += (1<<(query[j]-1));
                lsb = query[j]-1;
            }
        }
    }   

    for(auto it : nums)
        cout<<it<<" ";
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