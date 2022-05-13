#include <bits/stdc++.h>
using namespace std;

int main(){
    vector <string> fans;
    int n;
    cin >> n;
    while(n--){
    string str,tmp="",mn="";
    vector <string> ans;
    cin >> str;
    for(int i=0;i<=str.size();i++){
        if(i == str.size()){
            ans.push_back(tmp);
            bool tu = false;
            int no;
            for(int j=0;j<ans.size();j++){
                string stmp = ans[j];
                if(mn[0] == stmp[0]){
                    tu = true;
                    no = j;
                    break;
                }
            }
            if(tu){
                string h = "";
                h += mn;
                h += "->";
                h += mn;
                h += "'";
                if(no){
                    h += ans[0];
                }
                else{
                    h += ans[1];
                }
                fans.push_back(h);
                h = "";
                h += mn;
                h += "'";
                h += "->";
                h += mn;
                h += "'";
                if(no){
                    string bp = ans[1];
                    h += bp[1];
                    h += "|";
                    h += "e";
                }
                else{
                    string bp = ans[0];
                    h += bp[1];
                    h += "|";
                    h += "e";
                }
                fans.push_back(h);
            }
            else{
                fans.push_back(str);
            }
            tmp = "";
            mn = "";
        }
        else if(str[i] == ' '){
            continue;
        }
        else if(str[i] == '-' && str[i+1] == '>'){
            mn = tmp;
            tmp = "";
            i++;
        }
        else if(str[i] == '|'){
            ans.push_back(tmp);
            tmp = "";
        }
        else{
            tmp += str[i];
        }
    }
    }
    cout << endl ;
    for(auto &it:fans)
        cout << it << endl;
    return 0;
}

// 3
// A->Aa|b
// C->d|Cc
// M->n