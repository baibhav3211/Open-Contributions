#include <bits/stdc++.h>
#include <iostream>
typedef long long ll;
using namespace std;

void solve(){
    int a,b,c;
    cin>>a>>b>>c;
    if( ((a+b)==c) || ((b+c)==a) || ((a+c)==b)){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
}
int main(){
    int t;cin>>t;
    while(t--){
        solve();
    }
    return 0;
}