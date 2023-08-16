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
double pi = 3.14159, npi = -3.14159;
    cout << fixed << setprecision(0) << pi << 
 << npi << endl;
*/

/* Template for ordered set */
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using ordered_set =tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update> ;


ll fromBack(vector<ll>& nums, ll n,ll k)
{
    ll ans = 0;
    for(ll i=n-1;i>=0;)
    {
        ans += nums[i]*2;
        i = i-k;
    }
    return ans;
}

void solve()
{
    ll n, k; cin>>n>>k;
    vector<ll>nums(n);
    vector<ll>pos, neg;
    for(ll i=0;i<n;i++){
        cin>>nums[i];
        if(nums[i] > 0)
            pos.push_back(nums[i]);
        else if(nums[i] < 0)
            neg.push_back(abs(nums[i]));
    }
    if(pos.empty() and neg.empty()){
        cout<<0<<endl;
        return;
    }
    ll ans1 = 0, ans2 = 0;
    ll t1 = 0, t2 = 0;
    if(!pos.empty()){
        sort(pos.begin(), pos.end());
        ans1 = fromBack(pos, pos.size(), k);
        t1 = ans1;
        ans1 -= pos[pos.size() - 1];
    }
    if(!neg.empty()){
        sort(neg.begin(), neg.end());
        ans2 = fromBack(neg, neg.size(), k);
        t2 = ans2;
        ans2 -= neg[neg.size()-1];
    }

    cout<<min(t1+ans2, t2 + ans1)<<endl;
    

    // cout<<"hello"<<endl;
}
int main()
{
     ll t; cin>>t;
     while(t--)
        solve();
}   