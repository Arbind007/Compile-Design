#include <bits/stdc++.h>
using namespace std;

int main(){
    unordered_map <string,string> ump;
    string str,inp;
    int n;
    cin >> n;
    while(n--){
        cin >> str;
        ump[str.substr(3,str.length())] = str.substr(0,1);
    }
    cin >> inp;
    string ans="", tmp;
    cout << endl;
    for(int i=0;i<inp.length();i++){
        tmp = inp[i];
        if(islower(tmp[0])){
            cout << ans << " ";
            cout << "Shifted" << endl;
            cout << ans+tmp << " ";
            cout << "Reduce  " << ump[tmp] << " -> " << tmp << endl;
            ans += ump[tmp];
        }
        else if(ump[ans] != ""){
            cout << ans << " ";
            cout << "Reduce  " << ump[ans] << " -> " << ans << endl; 
            ans = ump[ans];
            i--;
        }
        else{
            cout << ans << " ";
            cout << "Shifted" << endl;
            ans += tmp;
        }
    }
    if(ump[ans] != ""){
        cout << ans << " ";
        cout << "Reduce  " << ump[ans] << " -> " << ans << endl;
        ans = ump[ans];
    }
    if(ans.length() == 1){
        cout << ans << " String Accepted" << endl;
        return 0;
    }
    cout << ans << " String Not Accepted" << endl;
    return 0;
}

// 3
// E->E+E
// E->E*E
// E->a
// a+a*a