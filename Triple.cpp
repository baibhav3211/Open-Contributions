#include<bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            a.push_back(x);
        }
        unordered_map<int,int> m;
        for(int i=0;i<n;i++){
            m[a[i]]++;
        }
        int cnt=0;
        bool flag=false;
        for(auto it=m.begin();it!=m.end();it++){
            if(it->second>=3){
                cout<<it->first<<endl;
                flag=true;
                break;
            }
        }
        if(!flag){
            cout<<"-1"<<endl;
        }
    }
    return 0;
}