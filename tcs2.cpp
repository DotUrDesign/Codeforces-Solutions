#include <bits/stdc++.h> 
 
using namespace std; 
 
typedef long long ll; 
#define placementlelo vector<int> 
#define all(a) (a).begin() , (a).end() 
#define sz(a) ((int)((a).size())) 
 
const ll INF = 4e18; 
 
vector<placementlelo> dp(1e4+1 , placementlelo(1e4+1 , -1)); 
 
int f(int i , int j , int s , int r , string &x , string &y , string &y1) 
{ 
    if(i>j)return 0; 
    if(dp[i][j] != -1)return dp[i][j]; 
 
    int mini = 1e9; 
    for(int k=i; k<=j; k++) 
    { 
         
        if(y1.find(x.substr(i , k-i+1)) != string::npos)mini = min(mini , r+f(k+1 , j , s , r , x , y , y1)); 
        if(y.find(x.substr(i , k-i+1)) != string::npos)mini = min(mini , s+f(k+1 , j , s , r , x , y , y1)); 
    } 
 
    return mini; 
} 
int solve(int s , int r , string x, string y) 
{ 
    string y1 = y; 
    reverse(all(y1)); 
    return f(0 , sz(x)-1 , s, r , x , y , y1); 
} 
 
int32_t main(){ 
 
    ios_base::sync_with_stdio(false);   
    cin.tie(NULL); 
 
    string x , y; 
    cin >> x >> y; 
    int s, r; 
    cin >> s >> r; 
    int ans = solve(s , r, x , y); 
    if(ans==1e9){ 
        cout<<"Impossible"; 
        return 0; 
    } 
    cout << ans; 
 
    return 0; 
 
}