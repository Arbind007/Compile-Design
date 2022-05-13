#include <bits/stdc++.h>
using namespace std;

int prec(char c){
    if(c == '^'){
        return 3;
    }
    else if(c == '/' || c == '*'){
        return 2;
    }
    else if(c == '+' || c== '-'){
        return 1;
    }
    else
        return -1;
}

int main(){
    stack <char> s;
    string str,ans;
    cin >> str;
    reverse(str.begin(),str.end());
    for(int i=0;i<str.length();i++){
        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i]  >= 'A' && str[i]  <= 'Z') || (str[i]  >= '0' && str[i]  <= '9')){
            ans += str[i];
        }
        else if(str[i] == '('){
           s.push('('); 
        }
        else if(str[i] == ')'){
            while(s.top() != '('){
                ans += s.top();
                s.pop();
            }
            s.pop();
        }
        else{
            while(!s.empty() && prec(str[i]) <= prec(s.top())){
                ans += s.top();
                s.pop();
            }
            s.push(str[i]);
        }
    }
    while (!s.empty()) {
        ans += s.top();
        s.pop();
    }
    reverse(ans.begin(),ans.end());
    cout << ans << endl;
    return 0;
 }
 
//  a+b*(c^d-e)^(f+g*h)-i
