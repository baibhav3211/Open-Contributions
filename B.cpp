#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        set<int> st;
        int ans=0;
        for(int i=0;i<n;i++){
            if(st.find(s[i])==st.end()){
                ans+=2;
                st.insert(s[i]);
            }
            else{
                ans+=1;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}