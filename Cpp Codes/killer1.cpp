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
#define pii               pair<int,int>
#define vi                vector<int>
#define vii               vector<pii>
#define mi                map<int,int>
#define mii               map<pii,int>
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define el                '\n' 
#define inputa(arg)       for (auto& e : arg) cin >> e
int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }
int lg(long long x){ return __builtin_clzll(1ll) - __builtin_clzll(x); }
void google() { static int _gtest_ = 1; cout << "Case #" << _gtest_++ << ": "; }
const int mod=1e9+7;
//const int mod2=998244353; 
const int N=2e5+5;

vi v[N];
vi tin(N),tout(N);
vi val(N);
int timer=1;
 vi a;
void dfs(int node , int parent = -1) {
    a.pb(val[node]);
   tin[node] = timer++;
   
    
   for (int i : v[node]) {
      if (i != parent) {
         dfs(i, node);
         
      }
   }
    a.pb(-val[node]);
   tout[node] = timer++;
   
}

 
 int st[8*N];
 
 void build(int l,int r, int val){

      if(l==r){
         st[val]=a[l];
         return;
      }
      int mid=l+(r-l)/2;

      build(l,mid,2*val);
      build(mid+1,r,2*val+1);

      st[val] =st[2*val] +st[2*val+1] ;
 }
 
void update(int l,int r,int ll,int rr,int x,int val){
    
     if(lt[val]>0){
        if(l!=r){
            
            lt[2*val]=1;
            lt[2*val+1]=1;
        }
        lt[val]=0;
        st[val]=0;
     }  


 
     if( r<ll||rr<l)
      return;
 
    if(l>=ll&&r<=rr){
     
        st[val]=0;
        if(l!=r){
            
            lt[2*val]=1;
            lt[2*val+1]=1;
        }
    
        return;
     }
     int mid=l+(r-l)/2;
     update(l,mid,ll,rr,x,2*val);
     update(mid+1,r,ll,rr,x,2*val+1);
     
     st[val]=st[2*val]+st[2*val+1];
 }


int query(int l,int r, int ll, int rr, int val ){
 
  if(lt[val]>0){
        if(l!=r){
            
            lt[2*val]^=1;
            lt[2*val+1]^=1;
        }
        lt[val]=0;
        st[val]=r-l+1-st[val];
     }  

 
    if( l>rr||r<ll)
        return 0; 
 
      if(l>=ll&&r<=rr)
        return  st[val] ;
 
          int mid =l+(r-l)/2;
           int x=query(l, mid, ll, rr, 2*val);
           int y=query(mid+1, r, ll, rr, 2*val+1);
 
          return x+y;
 
 }

void solve(){  
     
     int n,q;
     cin>>n>>q;

     rep(i,1,n+1)  cin>>val[i];

     rep(i,0,n-1){
          int x,y;
          cin>>x>>y;
          v[x].pb(y);
          v[y].pb(x);
     }

      a.pb(-1);
     dfs(1);

      build(1,2*n,1);
    
 
     while(q--){
          int x;
          cin>>x;
          if(x==1){
             int y,z;
             cin>>y>>z;
             update(1,2*n,tin[y],tin[y],z,1);
             update(1,2*n,tout[y],tout[y],-z,1);
          }
          else{
            int y;
            cin>>y;
             cout<<query(1,2*n,1,tin[y],1)<<el;
          }
     }
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