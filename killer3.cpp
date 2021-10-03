#include <bits/stdc++.h>

#ifdef  nuclear
   #include  "Nuclear.h"
#else
     using namespace std;
     #define debug(...) 42
#endif     

 #include <ext/pb_ds/assoc_container.hpp>
 #include <ext/pb_ds/tree_policy.hpp>
 using namespace __gnu_pbds;
 using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
 

#define int               long long
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
#define pii               pair<int,int>
#define vi                vector<int>
#define vii               vector<pii>
#define mi                map<int,int>
#define mii               map<pii,int>
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define el                '\n' 
#define inputa(arg)       for (auto& e : arg) cin >> e
int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }
int lg(long long x){ return __builtin_clzll(1ll) - __builtin_clzll(x) +1ll; }
void google() { static int _gtest_ = 1; cout << "Case #" << _gtest_++ << ": "; }
const int mod=1e9+7;
//const int mod2=998244353; 
 
    int power(int a,int n){
  int res=1;

     while(n){
        if(n%2){
           res*=a;
           n--;
        }
        else{
          a*=a;
          n/=2;
        }

     }
     return res;
}


void solve(){  
   
    string s;
    cin>>s;
   sort(allr(s));
   int ans=0;
    rep(i,1,(1<<sz(s))){
           string s1,s2;

         rep(j,0,sz(s)){
              if(i&(1<<j)){
               s1.pb(s[j]);
              }
              else
               s2.pb(s[j]);
         }

          if(sz(s1)&&sz(s2)&&s1[0]!='0'&&s2[0]!='0'){
           
             int x=stoll(s1);
             int y=stoll(s2);
              ans=max(ans,x*y);
          }
    }
    cout<<ans<<el;
}
    

signed main(){   

 
    
    #ifdef nuclear
      freopen("Error.txt", "w", stderr);
    #endif 

     ios_base::sync_with_stdio(false);
     cin.tie(0); cout.tie(0);
  
   int t=1;

   // cin>>t;

   while(t--)solve();
   return 0;
}