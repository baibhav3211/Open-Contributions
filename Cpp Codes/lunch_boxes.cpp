// #include <bits/stdc++.h>
// using namespace std;

// int main(){
//     int t;
//     cin>>t;
//     while(t--){
//         int n,m;
//         cin>>n>>m;
//         vector<int> v;
//         for(int i=0;i<m;i++){
//             int x;
//             cin>>x;
//             v.push_back(x);
//         }
//         sort(v.begin(), v.end());
//         int sum=0, count=0;
//         for(int i=0;i<v.size();i++){
//             sum+=v[i];
//             if(sum>n){
//                 break;
//             }
//             else{
//                 count++;
//             }
//         }
//         cout<<count<<endl;
//     }
//     return 0;
// }

// #include <bits/stdc++.h>
// #include <algorithm>
// using namespace std;
// typedef long long ll;

// string k="IMPOSSIBLE";
// void solve(string s,int x, string &ans){
//     if(x==s.size()){
//         k=ans;
//         return;
//     }
//     for(int i=0;i<s.size();i++){
//         if(ans[i]=='.' && s[x]!=s[i]){
//             ans[i]=s[x];
//             solve(s,x+1,ans);
//             ans[i]='.';
//         }
//     }
// }

// int main(){
//     int t;
//     cin>>t;
//     for(int p=1;p<=t;p++){
//         string ans,s;
//         cin>>s;
//         k="IMPOSSIBLE";
//         ans=s;
//         for(int i=0;i<s.size();i++){
//             ans[i]='.';
//         }
//         solve(s,0,ans);
//         cout << "Case #" + to_string(p) + ": ";
//         cout<<k<<endl;
//     }
//     return 0;
// }