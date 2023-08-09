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

void solve()
{
    ll n,m;
    cin>>n>>m;

    vector<ll>nums(n);
    for(ll i=0;i<n;i++)
        cin>>nums[i];
    
    ll ones=0, twos = 0, res = 0;
    vector<int>vis(m+1,0);
    for(ll i=0;i<n;i++)
    {
        if(nums[i] == -1)
            ones++;
        else if(nums[i] == -2)
            twos++;
        else {
            if(vis[nums[i]] == 0)
            {
                res++;
            }
            vis[nums[i]] = 1;
        }
    }

    // first case - when the first move is placing the -1 and then the other people => -2 are all wasted.
    // second case - when the first move is placing the -2 and then the other people => -1 are all wasted.
    ll ans = max(
        min(m, ones + res),
        min(m, twos + res)
    );

    // third case - when a reserved person is placed in the first move and then the other people. So, all the -1 people will be placed to the left of the first reserved person and all the -2 people will be placed to the right of the first reserved person.

    vector<ll>pref(m+1), suff(m+1);
    pref[1] = vis[1];
    for(ll i=2;i<=m;i++){
        pref[i] = pref[i-1] + vis[i];
    }

    suff[m] = vis[m];
    for(ll i=m-1;i>=1;i--){
        suff[i] = suff[i+1] + vis[i];
    }

    for(ll i=1;i<=m;i++)
    {
        // trying all the possibilities of placing every reserved person in the first move.
        if(vis[i] == 1){
            ll o = min(i-1, ones + pref[i-1]);
            ll t = min(m-i, twos + suff[i+1]);
            ans = max(ans, 1 + o + t);
        }
    }

    cout<<ans<<endl;
}
int main()
{
     ll t; cin>>t;
     while(t--)
        solve();
}