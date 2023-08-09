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

#define ar array
void solve()
{
    ll n; cin>>n;
    ll m; cin>>m;
    vector<ll>lines(n);
    for(ll i=0;i<n;i++)
        cin>>lines[i];
    sort(lines.begin(), lines.end());
    vector<ar<ll,3>>para(m);
    for(ll i=0;i<m;i++)
    {
        cin>>para[i][0]>>para[i][1]>>para[i][2];
    }

    // Condition --> (b-k)^2 < 4*a*c

    for(ll i=0;i<m;i++)
    {
       auto it = para[i];
       // We will be searching for the value of k which is closest to b, in that way we can get the value of (b-k)^2 to be least. If for that value, the required condition doesn't satisfies, then we are sure it will not satisfy for any case.
       ll idx = lower_bound(lines.begin(), lines.end(), it[1])  - lines.begin();
        if(idx < n and (it[1] - lines[idx]) * (it[1] - lines[idx]) < 4 * it[0] * it[2])
        {
            cout<<"YES"<<endl;
            cout<<lines[idx]<<endl;
        }
        else if(idx > 0 and (it[1] - lines[idx-1]) * (it[1] - lines[idx-1]) < 4 * it[0] * it[2])
        {
            cout<<"YES"<<endl;
            cout<<lines[idx-1]<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    cout<<endl;
}
int main()
{
     ll t; cin>>t;
     while(t--)
        solve();
}