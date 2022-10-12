#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(auto &i:a)cin>>i;
        vector<int> days = {6,13,20,27,7,14,21,28};
        int ans = 8;
        int j=0;
        for(int i=0;i<days.size();i++){
            if(a[j]!=days[i]){
                ans++;
                j++;
            }else{
                continue;
                j++;
            }
        }
        cout<<ans<<endl;

    }
    return 0;
}