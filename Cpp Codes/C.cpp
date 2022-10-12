#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            int x;
            string s;
            cin>>x>>s;
            for(int j=0;j<x;j++){
                if(s[j]=='U'){
                    a[i]--;
                    if(a[i]<0){
                        a[i]+=10;
                    }
                }
                else if(s[j]=='D'){
                    a[i] = (a[i]+1)%10;
                }
            }
        }
        for(int i=0;i<n;i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
        
    }
    return 0;
}