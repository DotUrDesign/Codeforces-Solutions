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

void solve()
{
    ll n; cin>>n;
    vector<ll>nums(n);
    for(ll i=0;i<n;i++)
        cin>>nums[i];

    /* Intuition --> We have to consider 2 same prime numbers or 3 different prime numbers to form a composite number.

    Lets undertand it step by step -->
    
    1st case --> 2 same prime number -- p  ==> the number formed by this prime number = p^2 aand its divisors are 1,p,p^2 and the prime divisors are "p" and the composite numbers are "p^2".
    Total composite divisors = 1, total prime divisors = 1
    Hence, strongly composite number

    2nd case --> 3 different prime numbers -- p,q,r  ==>  the number formed by these prime numbers = pqr and its divisors are --> 1,p,q,r,pq,qr,pr,pqr and the prime divisors are p,q,r and the composite divisors are pq,qr,pr,pqr . 
    Total composite divisors = 4, total prime divisors = 3;
    hence, strongly composite number
    */


   map<ll,ll>mpp;
   for(ll i=0;i<n;i++)
   {
        ll x = nums[i];
        for(ll j=2;(j*j)<=x;j++)
        {
            while((x%j) == 0)
            {
                x /= j;
                mpp[j]++;
            }
            if(x == 1)
                break;
        }
        if(x != 1)
            mpp[x]++;
   }

//    for(auto it:mpp)
//     cout<<it.first << ' '<<it.second<<endl;

    ll ans = 0, rem = 0;
    for(auto it:mpp)
    {
        ans += (it.second/2);
        rem += (it.second%2);
    }
    ans += rem/3;
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