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

bool comparator(const vector<ll> &a, const vector<ll>&b)
{
    if(a[0] == b[0])
    {
        if(a[1] == b[1])
            return a[2] < b[2];
        return a[1] < b[1];
    }
    return a[0] > b[0];
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
    ll part, prob, dur;
    cin>>part>>prob>>dur;

    ll tim[part][prob];
    for(ll i=0;i<part;i++)
    {
        for(ll j=0;j<prob;j++)
            cin>>tim[i][j];
    }

    vector<vector<ll>>ans(part, vector<ll>(3));
    for(ll i=0;i<part;i++)
    {
        sort(tim[i], tim[i] + prob);
        ll sum = 0, pen = 0, cnt = 0;
        for(ll j=0;j<prob;j++)
        {
            if((sum + tim[i][j]) <= dur)
            {
                sum += tim[i][j];
                cnt++;
                pen += sum;
            }
            else
                break;
        }
        ans[i][0] = cnt;
        ans[i][1] = pen;
        ans[i][2] = i;
    }
    
    sort(ans.begin(), ans.end(), comparator);

    // for(auto it:ans)
    //     cout<<it[0]<<" "<<it[1]<<" "<<it[2]<<endl;
    
    for(ll i=0;i<part;i++)
    {
        if(ans[i][2] == 0){
            cout<<i+1<<endl;
            break;
        }
    }
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