#include <bits/stdc++.h>
using namespace std;
int id=1;

int main(){
    int t;
    cin >> t;
    while(t--){
        string x,y;
        cin>>x>>y;
        int n = x.size();
        int m = y.size();
        int idx=0;
        for(int i=0;i<m;i++){
            if(y[i]==x[idx]){
                idx++;
            }
        }
        if(idx<n){
            cout<<"CASE #"<<id<<": IMPOSSIBLE"<<endl;
        }
        else{
            cout<<"CASE #"<<id<<": "<<m-n<<endl;
        }
        id++;

    }
    return 0;
}