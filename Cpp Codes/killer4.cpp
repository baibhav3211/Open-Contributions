#include <bits/stdc++.h>

#ifdef  nuclear
   #include  "Nuclear.h"
#else
     using namespace std;
    #define debug(...) 42
#endif     

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
int log(long long x){ return __builtin_clzll(1ll) - __builtin_clzll(x); }
void google() { static int _gtest_ = 1; cout << "Case #" << _gtest_++ << ": "; }
const int mod1=1e9+7;
const int mod2=998244353; 
 
  

  
void solve(){  
   
   int n;
   cin>>n;

 set<int> v;
   mi mp1;
   mi mp2;
   rep(i,0,n){
      int x,y;
      cin>>x>>y;
      v.insert(x);
      v.insert(x+y);
      mp1[x]++;
      mp2[x+y]--;

   }
  
  int cnt=0;
vi ans(n+5);
int pre=1;
    for(auto i:v){
       
          ans[cnt]+=i-pre;
           
           cnt+=mp2[i];
           cnt+=mp1[i];
           pre=i;
           debug(ans);
           debug(i,cnt,pre);
    }
    rep(i,1,n+1){
        cout<<ans[i]<<' ';
    }
    cout<<el;

}
    

signed main(){   

     
    #ifdef nuclear
      freopen("Error.txt", "w", stderr);
    #endif 

     ios_base::sync_with_stdio(false);
     cin.tie(0); cout.tie(0);
  
   int t=1;

    //cin>>t;

   while(t--)solve();
   return 0;
}