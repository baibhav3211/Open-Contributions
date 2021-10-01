#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int m = s.size();
        if(m<=10){
            cout<<s<<endl;
        }else{
            cout<<s[0] + to_string(m-2) + s[m-1]<<endl;
        }
    }
    return 0;
}