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
        bool flag=1;
        string s2;
        for(int i=0;i<n;i++){
            if(s[i]=='W'){
                if(s2.size()){
                    
                        int n2=count(s2.begin(),s2.end(),'B');
                        int n3=count(s2.begin(),s2.end(),'R');
                         
                         if(n2==0||n3==0) flag =0;
                    }
                
             s2="";    
            }
            else{
                s2+=s[i];
            }
        }

        if(s2.size()){
                   if(s2.size()){
                    
                        int n2=count(s2.begin(),s2.end(),'B');
                        int n3=count(s2.begin(),s2.end(),'R');
                         
                         if(n2==0||n3==0) flag =0;
                    
                }
        }
        cout<<(flag?"YES":"NO")<<endl; 
    }
    return 0;
}