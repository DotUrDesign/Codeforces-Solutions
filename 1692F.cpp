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
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;

void solve()
{
    ll n; cin>>n;
    vector<ll>nums(n);
    for(ll i=0;i<n;i++)
        cin>>nums[i];
    
    vector<ll>arr(10,0);
    for(ll i=0;i<n;i++)
    {
        ll d = nums[i]%10;
        arr[d]++;
        if(d&1) arr[d] = min(arr[d], 3 + 0ll);
        else    arr[d] = min(arr[d], 2 + 0ll);
    }
    vector<ll>b;
    for(ll i=0;i<10;i++)
    {
        while(arr[i]--)
            b.push_back(i);
    }
    sort(b.begin(),b.end());
    ll sizee = b.size();
    for(ll i=0;i<sizee-2;i++)
    {
        for(ll j=i+1;j<sizee-1;j++)
        {
            for(ll k=j+1;k<sizee;k++)
            {
                ll s = b[i] + b[j] + b[k];
                if(s == 3 or s == 13 or s == 23)
                {yes return;}
            }
        }
    }
    no
}
int main()
{
     ll t; cin>>t;
     while(t--)
        solve();
}