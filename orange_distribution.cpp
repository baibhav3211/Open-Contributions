#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> a(n), b(n);
    for(auto &i: a){
        cin>>i;
    }
    for(auto &j: b){
        cin>>j;
    }
    vector<pair<int, int>> vp;
    for(int i=0;i<n;i++){
        vp.push_back({a[i], b[i]});
    }
    sort(vp.begin(),vp.end());
    for(int i=vp.size();i>=0;i--){
        if((vp[i].first+vp[i-1].first)%m == 0){
            cout<<vp[i].second+vp[i-1].second<<endl;
            break;
        }
    }
    return 0;
}