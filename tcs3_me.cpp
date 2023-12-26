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

ll mod = 998244353;
ll power(ll x, ll n)
{
    ll ans = 1;
    long long nn = n;
    if (nn < 0) nn = -1 * nn;
    while (nn) {
        if (nn % 2) {
        ans = (ans%mod * x%mod)%mod;
        nn = nn - 1;
        } else {
        x = (x%mod * x%mod)%mod;
        nn = nn / 2;
        }
    }
    if (n < 0) ans = 1/ans;
    return ans%mod;
}

vector<int> lg(vector<int>& nums){
    int n = nums.size();
    vector<int> l(n);
    stack<int> st;
    for(int i = 0;i<n;i++){
        while(!st.empty() && st.top() < nums[i]) st.pop();
        if(st.empty()) st.push(nums[i]); 
        l[i] = st.top();
    }
    return l;
}

vector<int> rg(vector<int>& nums){
    int n = nums.size();
    vector<int> r(n);
    stack<int> st;
    for(int i = n-1;i>=0;i--){
        while(!st.empty() && st.top()<nums[i]) st.pop();
        if(st.empty()) st.push(nums[i]);
        r[i] = st.top();
    }
    return r;
}

// Function to calculate nCr (n choose r)
ll nCr(ll n, ll r) {
    if (r > n) 
        return 0;
    if (r == 0 || n == r) 
        return 1;

    double res = 0;
    for (ll i = 0; i < r; i++) {
        res += log(n-i) - log(i+1);
    }
    return (ll)round(exp(res));
}

/* 
Template for floating precision...
    cout << fixed << setprecision(0);
*/

/* Template for ordered set */
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using ordered_set =tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update> ;

unordered_map<string, int>mpp;
unordered_map<int, string>mppr;
void createMap()
{
    mpp["one"] = 1;
    mpp["two"] = 2;
    mpp["three"] = 3;
    mpp["four"] = 4;
    mpp["five"] = 5;
    mpp["six"] = 6;
    mpp["seven"] = 7;
    mpp["eight"] = 8;
    mpp["nine"] = 9;
    mpp["zero"] = 0;

    mppr[1] = "one";
    mppr[2] = "two";
    mppr[3] = "three";
    mppr[4] = "four";
    mppr[5] = "five";
    mppr[6] = "six";
    mppr[7] = "seven";
    mppr[8] = "eight";
    mppr[9] = "nine";
    mppr[0] = "zero";

}

bool checkOperator(string s)
{
    if(s == "add" or s == "mul" or s == "sub" or s == "rem" or s == "pow")
        return true;
    return false;
}

bool checkOperand(string s)
{
    string res = "";
    ll n = s.length();
    for(ll i=0;i<n;i++)
    {
        if(s[i] == 'c')
        {
            if(mpp.find(res) == mpp.end())
                return false;
            res = "";
        }
        else 
            res += s[i];
    }
    if(mpp.find(res) == mpp.end())
        return false;
    return true;
}

ll evaluate(string s)
{
    string res = "";
    ll num = 0;
    ll n = s.length();
    for(ll i=0;i<n;i++)
    {
        if(s[i] == 'c')
        {
            num = num*10 + mpp[res];
            res = "";
        }
        else 
            res += s[i];
    }
    num = num*10 + mpp[res];
    return num;
}

string solve2(ll a, ll b, string oper)
{
    ll ans = 0;
    if(oper == "add")
        ans = a + b;
    else if(oper == "sub")
        ans = b-a;
    else if(oper == "mul")
        ans = a*b;
    else if(oper == "div")
        ans = b/a;
    else if(oper == "pow")
        ans = pow(b,a);
    

    string res = "";
    while(ans != 0)
    {
        ll d = ans%10;
        res += mppr[d];
        res += "c";
        ans /= 10;
    }
    res.pop_back();
    return res;
}

void solve()
{
    createMap();
    string s;
    getline(cin, s);
    vector<string>nums;
    ll n = s.length();
    string res = "";
    for(ll i=0;i<n;i++)
    {
        if(s[i] == ' ')
        {
            nums.push_back(res);
            res = "";
        }
        else 
            res += s[i];
    }
    nums.push_back(res);

    n = nums.size();
    for(ll i=0;i<n;i++)
    {
        if(!checkOperand(nums[i]) and !checkOperator(nums[i]))
        {
            cout<<"expression evaluation stopped invalid words present"<<endl;
            return;
        }
    }

    stack<string>st;
    for(ll i=0;i<n;i++)
    {
        if(checkOperator(nums[i]))
        {
            st.push(nums[i]);
        }
        else if(checkOperand(nums[i]))
        {
            if(st.empty()){
                cout<<"expression is not complete or invalid"<<endl;
                return;
            }
            if(checkOperand(st.top()) == true)
            {
                ll a = evaluate(nums[i]);
                ll b = evaluate(st.top());
                // cout<<a<<" "<<b<<" ";
                st.pop();
                if(st.empty() or checkOperator(st.top()) == false){
                    cout<<"expression is not complete or invalid"<<endl;
                    return;
                }
                string oper = st.top();
                st.pop();
                // cout<<oper<<" ";
                string ans = solve2(a,b,oper);
                // cout<<ans<<endl;
                st.push(ans);
            }
            else{
                st.push(nums[i]);
            }
        }
    }
    cout<<evaluate(st.top())<<endl;
}
int main()
{
   // Place the template of  the precision code here...
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
        solve();
}