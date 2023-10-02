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

void solve()
{
    ll n; cin>>n;
    string s1, s2; cin>>s1>>s2;
    
    // not possible cases -> equal and not equal at the same time or if "n" is odd, then the number of 1's is also odd.
    bool f1 = false, f2 = false;
    ll num = 0;
    for(ll i=0;i<n;i++)
    {
        if(s1[i] == s2[i])
            f1 = true;
        else 
            f2 = true;
        if(s1[i] == '1')
            num++;
    }
    if(f1 and f2)
    {
        cout<<"NO"<<endl;
        return;
    }

    cout<<"YES"<<endl;
    vector<pair<ll,ll>>ans;
    char ok = '1';
    if(!(n&1))
    {
        if((f1 and num&1) or (f2 and !(num&1))){
            ans.push_back({1, n});
            ok = '0';
        }

        for(ll i=0;i<n;i++)
        {
            if(s1[i] == ok)
                ans.push_back({i+1, i+1});
        }
    }
    else
    {
        for(ll i=0;i<n;i++)
        {
            if(s1[i] == '1')
                ans.push_back({i+1,i+1});
        }

        if((f2 and !(num&1)) or (f1 and num&1))
        {
            ans.push_back({1,n});
            ans.push_back({1,n-1});
            ans.push_back({n,n});
        }
    }

    cout<<ans.size()<<endl;
    for(auto it:ans)
        cout<<it.first<<" "<<it.second<<endl;

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