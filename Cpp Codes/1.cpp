#include<bits/stdc++.h>
using namespace std;

void func(){
    int n,k;
        cin>>n>>k;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        if(2*k<n){
            cout<<"NO"<<endl;
        }else{
            bool flag=false;
            map<int,int> mp;
            for(auto it: a){
                mp[it]++;
            }
            for(auto it: mp){
                if(it.second>2){
                    flag=true;
                    break;
                }
            }
            if(flag){
                cout<<"NO"<<endl;
            }
            else{
                cout<<"YES"<<endl;
            }
        }
}

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        cout<<"Case #"<<i+1<<": ";
        func();
    }
    return 0;
}