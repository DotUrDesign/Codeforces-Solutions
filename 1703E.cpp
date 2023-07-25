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
    ll n; cin >> n;
    vector<vector<ll>>nums(n,vector<ll>(n));
    for(ll i=0;i<n;i++)
    {
        string s; cin>>s;
        for(ll j=0;j<n;j++)
        {
            nums[i][j] = s[j] - '0';
        } 
    }
    
    ll start = 0;
    ll end = n-1;
    ll ans = 0;
    for(ll i=n-1;i>=(n/2-1);i--)
    {
        for(ll j=start; j <= end-1;j++)
        {
            ll drow[] = {0 , (j - i) , -1*(j-start) , (i - j)};
            ll dcol[] = {0 , -1*(j-start) ,  (i - j) , (j-start)};
            ll cnt1 = 0, cnt0 = 0;
            ll prev_row = i, prev_col = j;
            for(ll k=0; k<4;k++)
            {
                ll nrow = prev_row + drow[k];
                ll ncol = prev_col + dcol[k];
                if(nrow >= 0 and nrow < n and ncol >= 0 and ncol < n)
                {
                    if(nums[nrow][ncol] == 1)
                        cnt1++;
                    else    
                        cnt0++;
                }
                // cout<<drow[k]<< " "<< dcol[k]<< " "<<nrow <<" "<<ncol<<endl;
                prev_row = nrow;
                prev_col = ncol;
            }
            ans += (cnt1 > cnt0) ? cnt0 : cnt1;
            // cout<<cnt1<<" "<<cnt0<<endl;
            // cout<<ans<<endl;
        }
        start++;
        end--;
    }
    cout<<ans<<endl;
}
int main()
{
     ll t; cin>>t;
     while(t--)
        solve();
}