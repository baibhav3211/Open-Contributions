#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        unordered_map<string,int> mp;
        for(int i=0;i<n;i++){
            mp[a[i]] = i;
        }
        string ans="";
        for(int i=0;i<n;i++){
           
            string s=a[i];
            bool flag=false;
            
            for(int j=0;j<s.length();j++){
                string s1="";
                string s2="";
                for(int k=0;k<j;k++){
                    s1+=s[k];
                }
                for(int k=j;k<s.length();k++){
                    s2+=s[k];
                }
                if(mp.find(s1)!=mp.end() and mp.find(s2)!=mp.end()){
                    flag=true;
                }
            }
            
            if(flag){
                ans+='1';
            }else{
                ans+='0';
            }
            
        }
        cout<<ans<<endl;
        
    }
    return 0;
}