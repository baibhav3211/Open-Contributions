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

 
  int n; // The number of nodes in the graph
vector<int> graph[100000];
int timer = 0, tin[100000], euler_tour[200000];
int segtree[800000]; // Segment tree for RMQ

void dfs(int node = 0, int parent = -1) {
   tin[node] = timer; // The time when we first visit a node
   euler_tour[timer++] = node;
   for (int i : graph[node]) {
      if (i != parent) {
         dfs(i, node);
         euler_tour[timer++] = node;
      }
   }
}

int mn_tin(int x, int y) {
   if (x == -1) return y;
   if (y == -1) return x;
   return (tin[x] < tin[y] ? x : y);
}

// Build the segment tree: run `build()` after running dfs`
void build(int node = 1, int l = 0, int r = timer - 1) {
   if (l == r) segtree[node] = euler_tour[l];
   else {
      int mid = (l + r) / 2;
      build(node * 2, l, mid);
      build(node * 2 + 1, mid + 1, r);
      segtree[node] = mn_tin(segtree[node * 2], segtree[node * 2 + 1]);
   }
}

int query(int a, int b, int node = 1, int l = 0, int r = timer - 1) {
   if (l > b || r < a) return -1;
   if (l >= a && r <= b) return segtree[node];
   int mid = (l + r) / 2;
   return mn_tin(query(a, b, node * 2, l, mid), query(a, b, node * 2 + 1, mid + 1, r));
}

// Make sure you run $dfs` and `build()` before you run this
int lca(int a, int b) {
   if (tin[a] > tin[b]) swap(a, b);
   return query(tin[a], tin[b]);
}




void solve(){  
     
   
   
   




    
     
}
    

signed main(){   

       
  
    #ifdef nuclear
      freopen("Error.txt", "w", stderr);
    #endif 

     ios_base::sync_with_stdio(false);
     cin.tie(0); cout.tie(0);
  
    int t=1;

     cin>>t;

   while(t--)solve();
   return 0;
}