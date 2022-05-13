#include <bits/stdc++.h>
using namespace std;

int main(){
    unordered_map <int,vector <string>> mp;
    int cnt = 0;
    bool tu = true;
    string a;
    cin >> a;
    int i=0, j=a.length();
    while(i < j){
        if(a[i] == 'a' && a[i+1] == 'b'){
            if(a[i+2] == '*'){
                cout << "Invalid" << endl;
                tu = false;
                break;
            }
            else{
                string tmp = "a";
                mp[cnt].push_back(tmp);
                cnt++;
                tmp = "b";
                mp[cnt].push_back(tmp);
                cnt++;
                i+=2;
            }
        }
        else if(a[i] == '(' && a[i+1] == 'a' && a[i+2] == '+' && a[i+3] == 'b' && a[i+4] == ')'){
            if(a[i+5] == '*'){
                string tmp = "a-self,b-self";
                mp[cnt].push_back(tmp);
                i+=6;
            }
            else{
                string tmp = "a,b";
                mp[cnt].push_back(tmp);
                cnt++;
                i+=5;
            }
        }
        else if(a[i] == 'a'){
            if(a[i+5] == '*'){
                string tmp = "a-self";
                mp[cnt].push_back(tmp);
                i+=2;
            }
            else{
                string tmp = "a";
                mp[cnt].push_back(tmp);
                cnt++;
                i+=1;
            }
        }
        else if(a[i] == 'b'){
            if(a[i+5] == '*'){
                string tmp = "b-self";
                mp[cnt].push_back(tmp);
                i+=2;
            }
            else{
                string tmp = "b";
                mp[cnt].push_back(tmp);
                cnt++;
                i+=1;
            }
        }
        else{
            cout << "Invalid" << endl;
            tu = false;
            break;
        }
    }
    if(tu){
        cout << "Valid" << endl;
        for(auto it:mp){
            cout << it.first << " -> ";
            for(auto jt:it.second){
                cout << jt << " ";
            }
            cout << endl;
        }
    }
    
    return 0;
}