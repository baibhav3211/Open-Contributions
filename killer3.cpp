#include<bits/stdc++.h>
#define N 42
using namespace std;
int T,n,a,b,ans;
int cur[N],res[N];
char s[N];
bool vis[N][N][N][N];
void dfs(int x,int moda,int modb,int cnta){
    if(vis[x][moda][modb][cnta]) return;
    vis[x][moda][modb][cnta]=1;
    if(x>n){
        if(!moda&&!modb&&cnta&&cnta<n&&abs(n-2*cnta)<ans){
            ans=abs(n-2*cnta);
            for(int i=1;i<=n;i++) res[i]=cur[i];
        }
        return;
    }
    cur[x]=0;
    dfs(x+1,(moda*10+s[x]-'0')%a,modb,cnta+1);
    cur[x]=1;
    dfs(x+1,moda,(modb*10+s[x]-'0')%b,cnta);
}
void solve(){
    cin>>n>>a>>b>>s+1;
    memset(vis,0,sizeof(vis));
    ans=1e9;
    dfs(1,0,0,0);
    if(ans==1e9) cout<<-1<<endl;
    else{
        for(int i=1;i<=n;i++) cout<<(res[i]?'B':'R');
        cout<<endl;
    }
} 
signed main(){
    cin>>T;
    while(T--) solve();
    return 0;
}