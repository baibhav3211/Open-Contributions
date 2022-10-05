#include <bits/stdc++.h>

#ifdef  nuclear
   #include  "Nuclear.h"
#else
     using namespace std;
    #define debug(...) 42
#endif 

#define int                long long
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define all(x)            (x).begin(),(x).end()
#define allr(x)           (x).rbegin(),(x).rend()
#define uniq(v)           (v).erase(unique(all(v)),(v).end())
#define sz(x)             (int)((x).size())
#define fr                first
#define sc                second
#define pii                pair<int,int>
#define vi                vector<int>
#define vii               vector<pii>
#define mi                map<int,int>
#define mii               map<pii,int>
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define el                '\n' 
#define inputa(arg)       for (auto& e : arg) cin >> e
int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }
int lg(long long x){ return __builtin_clzll(1ll) - __builtin_clzll(x); }
 const int mod=1e9+7;
 //const int mod=998244353; 
  
const int N=2e5+5; 
 
 
void solve(){
   
    string s1,s2;
    cin>>s1>>s2;
    string s3=s2,s4=s1;
    
    int ans=INT_MAX;
   for(char i='a';i<='z';i++){
       int cnt=0;
      for(auto j:s1){
         if(j<i) cnt++;
      }
      for(auto j:s2){
         if(j>=i) cnt++;
      }
     ans=min(cnt,ans);
     
     
     cnt=0;
     for(auto j:s3){
         if(j<i) cnt++;
      }
      for(auto j:s4){
         if(j>=i) cnt++;
      }
     ans=min(cnt,ans);

   }
   
   int mx=0;
   map<char,int> mp;

   for(auto i :s1){
      mp[i]++;
      mx=max(mx,mp[i]);
   }
   for(auto i :s2){
      mp[i]++;
      mx=max(mx,mp[i]);
   }
    int c=sz(s1)+sz(s2)-mx;
    cout<<min(ans,c);
   

}



signed main(){   
    
     
   
    #ifdef nuclear
      freopen("Error.txt", "w", stderr);
    #endif 

     ios_base::sync_with_stdio(false);
     cin.tie(0); cout.tie(0);
  
    int t=1;
    
  //  cin>>t;

   while(t--)solve();
   return 0;
}