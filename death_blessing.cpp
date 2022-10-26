#include <bits/stdc++.h>
#include <iostream>
typedef long long ll;
using namespace std;

void solve(){
    int n;cin>>n;
    vector<ll>a(n);
    vector<ll>b(n);
    for(int i=0;i<n;i++)
    cin>>a[i];

    for(int i=0;i<n;i++)
    cin>>b[i];

    if(n==1){
        cout<<a[0]<<endl;
    }
    else{
    vector<pair<ll,ll>>v(n);
    for(int i=0;i<n;i++){
        v[i]=make_pair(b[i],a[i]);
    }

    sort(v.begin(),v.end());
    ll k=0,sum=0;
    for(int i=0;i<n;i++){
        sum+= v[i].second + k;
        k=v[i].first;
    }
    cout<<sum<<endl;
    }
}
int main(){
    int t;cin>>t;
    while(t--){
        solve();
    }
    return 0;
}