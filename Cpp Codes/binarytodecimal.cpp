#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    int ans=0;
    reverse(s.begin(), s.end());
    for(int i=0;i<s.size()-1;i++){
        ans+=pow(2,i);
    }
    cout<<ans<<endl;
    return 0;
}