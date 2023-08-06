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
    vector<ll>nums(n);
    for(ll i=0;i<n;i++)
        cin>>nums[i];
    
    bool flag1 = false, flag2 = false;
    vector<ll>pos, neg;
    for(ll i=0;i<n;i++)
    {
        if(nums[i] > 0){
            flag1 =true;
            pos.push_back(i);
        }
        if(nums[i] < 0){
            flag2 = true;
            neg.push_back(i);
        }
    }
    if(!flag1 and !flag2){
        cout<<0<<endl;
        return;
    }
    else if(flag1 and !flag2){
        cout<<n-1<<endl;
        for(ll i=1;i<n;i++)
            cout<<i<<" "<<i+1<<endl;
        return;
    }
    else if(flag2 and !flag1){
        cout<<n-1<<endl;
        for(ll i=n;i>1;i--)
            cout<<i<<" "<<i-1<<endl;
        return;
    }
    ll maxval = INT_MIN;
    ll maxidx = -1;
    flag1 = false;
    for(ll i=0;i<n;i++)
    {
        if(abs(nums[i]) > maxval){
            maxval = nums[i];
            maxidx = i;
            flag1 = (nums[i] < 0) ? false : true;
        }
    }
    if(flag1){
        cout<<pos.size() + n-1<<endl;
        for(auto it:pos)
            cout<<it+1<<" "<<maxidx+1<<endl;
        for(ll i=1;i<n;i++)
            cout<<i<<" "<<i+1<<endl;
    }
    else {
        cout<<neg.size() + n-1<<endl;
        for(auto it : neg)  
            cout<<it+1<<" "<<maxidx+1<<endl;
        for(ll i=n;i>1;i--)
            cout<<i<<" "<<i-1<<endl;
    }
}
int main()
{
     ll t; cin>>t;
     while(t--)
        solve();
}