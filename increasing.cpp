#include <bits/stdc++.h>
#include <iostream>
typedef long long ll;
using namespace std;

void solve(){
    int n;cin>>n;
    vector<ll> v(n);
    map<ll,int> m;
    for(int i =0;i<n;i++){
        cin>>v[i];
        m[v[i]]++;
    }
    int k=0;
    for(auto i:m){
        if(i.second != 1){
            cout<<"NO"<<endl;
            k=-1;
            break;
        }
    }
    if(k==0)
    cout<<"YES"<<endl;

}
int main(){
    int t;cin>>t;
    while(t--){
        solve();
    }
    return 0;
}