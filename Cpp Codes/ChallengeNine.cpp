#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s = to_string(n);
        for(int i=0;i<=9;i++){
            s.push_back(i);
            if(stoi(s)%9==0){
                cout<<s<<endl;
                break;
            }else{
                s.pop_back();
            }
        }
    }
    
    return 0;
}