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

void solve()
{
    ll n,m; cin>>n>>m;
    vector<vector<ll>>nums(n,vector<ll>(m));
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<m;j++)
            cin>>nums[i][j];
    }
    ll row[] = {0,n-1,n-1,0};
    ll col[] = {0,0,m-1,m-1};
    for(ll i=0;i<4;i++)
    {
        if(nums[row[i]][col[i]] > 2)
        {
            cout<<"NO"<<endl;
            return;
        }  
        nums[row[i]][col[i]] = 2;
    }
    for(ll i=1;i<n-1;i++)
    {
        if(nums[i][0] > 3 or nums[i][m-1] > 3)
        {
            cout<<"NO"<<endl;
            return;
        }
        nums[i][0] = nums[i][m-1] = 3;
    }
    for(ll i=1;i<m-1;i++)
    {
        if(nums[0][i] > 3 or nums[n-1][i] > 3)
        {
            cout<<"NO"<<endl;
            return;
        }
        nums[0][i] = nums[n-1][i] = 3;
    }
    for(ll i=1;i<n-1;i++)
    {
        for(ll j=1;j<m-1;j++)
        {
            if(nums[i][j] > 4)
            {
                cout<<"NO"<<endl;
                return;
            }
            nums[i][j] = 4;
        }
    }
    cout<<"YES"<<endl;
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<m;j++)
            cout<<nums[i][j]<<" ";
        cout<<endl;
    }
}
int main()
{
     ll t; cin>>t;
     while(t--)
        solve();
}