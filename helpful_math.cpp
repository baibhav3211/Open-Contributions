#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;cin>>s;
    map<char,int>m;
    for(int i=0;i<s.length();i++){
        if(s[i] != '+'){
            m[s[i]]++;
        }
    }

    for(auto i:m){
        while(i.second >0){
            cout<<i.first<<'+';
        }
    }

    return 0;
}
