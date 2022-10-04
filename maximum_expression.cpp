#include <bits/stdc++.h> 
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        string s;cin>>s;
        int cntp=0,cntn=0;
        int arr[10]={0};
        for(int i=0;i<n;i++){
            if(s[i] == '+')
            cntp++;
            else if(s[i]=='-')
            cntn++;
            else
            arr[s[i]-48]++;

        }
        string str="";
        // int spaces= (cntn+cntp+1);
        // int num = (n-cntn-cntp);
        for(int i=9;i>=0;i--){
            if(arr[i]>0){
            while(arr[i]--){
                //char ch=char(i);
                int m=i+48;
                char ch=m;
                str+=m;
            }
            }
        }
     //   cout<<str<<endl;
        string st="";
        for(int i=str.length()-1;i>=0;i--){
            st+=str[i];
            if(cntn>0){
            st+='-';
            cntn--;
            }
            else if(cntp>0){
            st+='+';
            cntp--;
            }
        }
     //   cout<<st<<endl;
        string k="";
        for(int i=st.length()-1;i>=0;i--){
            k+=st[i];
        }

        cout<<k<<endl;
    }
    return 0;
}