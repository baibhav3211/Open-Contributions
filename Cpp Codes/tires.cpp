#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    int si = s.length();
    if(s[si-1]=='r'){
        cout<<s[si-2]<<s[si-1]<<endl;
    }else{
        cout<<s[si-3]<<s[si-2]<<s[si-1]<<endl;
    }
 
    return 0;
}