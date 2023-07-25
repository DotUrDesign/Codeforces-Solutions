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

bool comparator(const vector<ll> &a, const vector<ll> &b)
{
    return a[1] - a[0] > b[1] - b[0];
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

ll check( vector<vector<ll>>& vec)
{
    ll count = 0;
    ll sum1 = 0, sum2 = 0;
    ll start = 0, end = vec.size()-1;
    while(start < end)
    {
        sum1 = vec[start][0] + vec[end][0];
        sum2 = vec[start][1] + vec[end][1];
        if(sum1 <= sum2)
        {
            count++ , start++;
        }
        sum1 = 0, sum2=0;
        end--;
    }
    return count;
}

void solve()
{
    ll n; cin>>n;   
    vector<ll>spend(n);
    for(ll i=0;i<n;i++)
        cin>>spend[i];
    vector<ll>have(n);
    for(ll i=0;i<n;i++)
        cin>>have[i];
    vector<vector<ll>>vec(n,vector<ll>(2));
    for(ll i=0;i<n;i++)
    {
        vec[i][0] = spend[i];
        vec[i][1] = have[i];
    }
    sort(vec.begin(),vec.end(),comparator);
    // for(auto it:vec)
    //     cout<<it[0]<<' '<<it[1]<<endl;

    ll ans = check(vec);
    cout<<ans<<endl;
}
int main()
{
     ll t; cin>>t;
     while(t--)
        solve();
}