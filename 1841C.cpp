 /* 
iiiiiiiiiiii  iiiiiiiiiiii  iiiiiiiiiiii  ttttttttttt
     i             i             i             t
     i             i             i             t
     i             i             i             t
     i             i             i             t
     i             i             i             t
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

void solve()
{
    string s; cin>>s;
    ll n = s.length();
    vector<ll>nums;
    for(ll i=0;i<n;i++)
    {
        char ch  = s[i];
        ch = ch - 'A';
        s[i] = ch + '0';
        nums.push_back(s[i] - '0');
    }

    vector<ll>maxele(n,0);
    maxele[n-1] = nums[n-1];
    for(ll i=n-2;i>=0;i--)
        maxele[i] = max(maxele[i+1], nums[i]);

    vector<ll>pref(n,0);
    pref[0] = (maxele[0] > nums[0]) ? -1*(ll)pow(10, nums[0]) : (ll)pow(10,  nums[0]);
    for(ll i=1;i<n;i++)
    {
        if(maxele[i] > nums[i])
            pref[i] = pref[i-1] - (ll)pow(10, nums[i]);
        else
            pref[i] = pref[i-1] + (ll)pow(10, nums[i]);
    }

    ll maxsum = INT_MIN;
    for(ll i=1;i<n-1;i++)
    {
        ll sum = 0;
        sum += suff[i+1];
        sum -= pref[i-1];
        sum += ((maxcnt[i-1]+1) * pow(10, 4));
        cout<<sum<<' ';
        maxsum = max(maxsum , sum);
    }
    cout<<endl;
    cout<<maxsum<<endl;
}
int main()
{
     ll t; cin>>t;
     while(t--)
        solve();
}