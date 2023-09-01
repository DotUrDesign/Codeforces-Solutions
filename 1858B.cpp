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

ll find(ll high, ll low, ll d)
{
    // excluding both the high and low --> only considering the cookies between the high and low.
    return (high - low - 1)/d;
}

void solve()
{
    ll b,n,d;
    cin>>b>>n>>d;

    vector<ll>nums(n);
    for(ll i=0;i<n;i++)
        cin>>nums[i];
    
    vector<ll>pref(n), suff(n);

    pref[0] = 1 + (nums[0] - 1 + d - 1)/d;
    for(ll i=1;i<n;i++)
        pref[i] = pref[i-1] + find(nums[i],nums[i-1],d) + 1;

    suff[n-1] = 1 + find(b+1, nums[n-1], d);
    for(ll i=n-2;i>=0;i--)
        suff[i] = suff[i+1] + find(nums[i+1], nums[i], d) + 1;

    map<ll,ll>mpp; // to keep track of the second output...
    
    // removing the first cookie shop
    ll ans = suff[1] + (nums[1] + d-2)/d;
    mpp[ans]++;

    // removing the last cookie shop
    ll curr = pref[n-2] + find(b+1, nums[n-2],d);
    mpp[curr]++;
    ans = min(ans, curr);

    // now applying brute force approach i.e., removing each cookie shop one by one and checking whats the minimum in every case
    for(ll i=1;i<n-1;i++)
    {
        ll curr = pref[i-1] + suff[i+1] + find(nums[i+1], nums[i-1] , d);
        mpp[curr]++;
        ans = min(ans, curr);
    }

    cout<<ans<<" "<<mpp[ans]<<endl;
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