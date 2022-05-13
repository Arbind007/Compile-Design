#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector <string> rules;
    string str;
    unordered_map <char,vector <char>> leading,trailing; 
    for(int i=0;i<n;i++){
        cin >> str;
        rules.push_back(str);
    }
    for(int i=0;i<rules.size();i++){
        str = rules[i];
        if(str.size() == 4){
            leading[str[0]].push_back(str[3]);
            trailing[str[0]].push_back(str[3]);
        }
        else{
            leading[str[0]].push_back(str[3]);
            if(islower(str[4]) && isupper(str[3])){
                leading[str[0]].push_back(str[4]);
            }
            trailing[str[0]].push_back(str[str.length() - 1]);
            if(islower(str[4]) && isupper(str[5])){
                trailing[str[0]].push_back(str[4]);
            }
        }
    }
    cout << endl;
    cout << "Leading:"<< endl;
    for(auto it:leading){
        cout << it.first << " -> "; 
        for(auto jt:it.second){
            if(isupper(jt)){
                for(auto mt:leading[jt]){
                    cout << mt << " ";
                }
            }
            else{
                cout << jt << " ";
            }
        }
        cout << endl;
    }
    cout << "Trailing:" <<endl;
    for(auto it:trailing){
        cout << it.first << " -> "; 
        for(auto jt:it.second){
            if(isupper(jt)){
                for(auto mt:leading[jt]){
                    cout << mt << " ";
                }
            }
            else{
                cout << jt << " ";
            }
        }
        cout << endl;
    }
    return 0;
}

// 3
// A->BaC
// B->b
// C->c