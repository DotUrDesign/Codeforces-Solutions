#include <bits/stdc++.h>
using namespace std;

unordered_map<string , string> validNum , validOp;

void process(){
    vector<string> vs = {"zero" , "one" , "two" , "three" , "four", "five" , "six" , "seven" , "eight" , "nine"};
    for(long long i = 0 ; i<10 ; i++){
        string dig;
        dig += '0'+i ;
        validNum[vs[i]] = dig;
    }
    validOp["add"] = "+";
    validOp["sub"] = "-";
    validOp["mul"] = "*";
    validOp["rem"] = "%";
    validOp["pow"] = "^";
    
}

long long toNum(string & s){
    long long ans = 0;
    for(char c: s){
        ans = ans*10 + (c-'0');
    }
    return ans;
}

string solveExpression(vector<string> & vs){
    long long n = vs.size();
    stack<long long>st;
    for(long long i = n-1;  i>= 0 ;i--){
        string c = vs[i];
        if(validOp.find(c) != validOp.end()){
            
            if(st.size() < 2){
                return "expression is not complete or invalid\n";
            }
            long long v1 = st.top();st.pop();
            long long v2 = st.top();st.pop();
            long long ans ;
            if(c == "add") ans = v1+v2;
            if(c == "sub") ans = v1-v2;
            if(c == "mul") ans = v1*v2;
            if(c == "rem") ans = v1%v2;
            if(c == "pow") ans = v1^v2;
            st.push(ans);
        }
        else st.push(toNum(c));
    }
    if(st.size() == 1)return to_string(st.top());
    return "expression is not complete or invalid\n";
}

void solve(string & s){
   vector<string> pf ;
    string cur;
    long long n = s.length();
    for(long long i = 0 ; i<=n ; i++){
        if(i==n || s[i]==' '){
            if(validOp.find(cur) != validOp.end()){
                pf.push_back(cur);
                cur = "";
            }
            else{
                string tmp , num;
                long long cl = cur.length();
                for(long long i = 0 ; i<=cl ; i++){
                    if((i==cl) || (cur[i] == 'c')){
                        if(validNum.find(tmp) == validNum.end()){
                            cout<<"expression evaluation stopped invalid words present\n";
                            return;
                        }
                        num += validNum[tmp];
                        tmp = "";
                    }
                    else tmp += cur[i];
                }
                pf.push_back(num);
                cur="";
            }
            
        }
        else cur+=s[i];
    }
    cout<< solveExpression(pf) <<"\n";
}

int main(){
    process();
    string s;
    getline(cin ,s);
    solve(s);
}