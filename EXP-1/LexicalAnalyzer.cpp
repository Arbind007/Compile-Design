#include <bits/stdc++.h>
#include <fstream>
using namespace std;

bool isNumber(string a){
    for(int i=0;i<a.length();i++){
        if(!isdigit(a[i]) && a[i] != ','){
            return false;
        }
    }
    return true;
}

int main(){
    vector <string> keyword = {"void","main","int","float","if","else","while"};
    vector <string> opera = {"+","-","/","*","=","==","-=","+=","*=","/=","||","&&"};
    vector <string> punc = {"{","}","(",")","[","]",";",",","'"};
    vector <string> keywordlist, operatorlist, punctuationlist, numberlist, indentifierlist;
    fstream f;
    f.open("test.txt");
    string str;
    while(f){
        std::getline(f,str);
        string tmp = "";
        for(int i=0;i<=str.size();i++){
            if(tmp == " "){
                tmp = "";
            }
            if(str[i] == ' ' || i == str.size()){
               bool tu = false;
               if(tmp == ""){
                   continue;
               }
               if(!tu){
                    for(int i=0;i<keyword.size();i++){
                        if(keyword[i] == tmp){
                            keywordlist.push_back(tmp);
                            tu = true;
                        }
                    }
               }
               if(!tu){
                    for(int i=0;i<opera.size();i++){
                        if(opera[i] == tmp){
                            operatorlist.push_back(tmp);
                            tu = true;
                        }
                    }
               }
               if(!tu){
                    for(int i=0;i<punc.size();i++){
                        if(punc[i] == tmp){
                            punctuationlist.push_back(tmp);
                            tu = true;
                        }
                    }
               }
                if(!tu){
                    if(isNumber(tmp)){
                        numberlist.push_back(tmp);
                        tu = true;
                    }
                }
               if(!tu){
                    indentifierlist.push_back(tmp);
               }
                tmp = ""; 
            }
            else{
                tmp += str[i];
            }
        }
    }

    // OutPut
    cout << "keywordlist" << endl;
    for(auto &it: keywordlist){
        cout << it << " ";
    }
    cout << endl;
    cout << keywordlist.size() << endl;
    
    cout << "operatorlist" << endl;
    for(auto &it: operatorlist){
        cout << it << " ";
    }
    cout << endl;
    cout << operatorlist.size() << endl;
    
    cout << "punctuationlist" << endl;
    for(auto &it: punctuationlist){
        cout << it << " ";
    }
    cout << endl;
    cout << punctuationlist.size() << endl;
    
    cout << "numberlist" << endl;
    for(auto &it: numberlist){
        cout << it << " ";
    }
    cout << endl;
    cout << numberlist.size() << endl;
    
    cout << "indentifierlist" << endl;
    for(auto &it: indentifierlist){
        cout << it << " ";
    }
    cout << endl;
    cout << indentifierlist.size() << endl;
    return 0;
}