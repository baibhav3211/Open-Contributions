#include <bits/stdc++.h>
using namespace std;
vector<vector<int> >rv;
int n,edges,mini;
bool recur(int strt,int src,int sz,vector<bool>&vis,vector<int>adj[]){
if(sz==0){
    for(int i=0;i<n;i++){
         for(int j=0;j<adj[i].size();j++){
                int des=adj[i][j];
                vis[i]=true;
                vis[des]=true;
                bool flg=recur(i,des,sz+2,vis,adj);
                if(flg)return true;
                vis[i]=false;
                vis[des]=false;
        }
    }
}
else{
    if(sz==n){
      return true;
    }
    else if(sz>n){
        return false;
    }
    int ssz=adj[src].size();
        for(int i=0;i<ssz;i++){
            int des=adj[src][i];
            if(!vis[des]){
                vis[des]=true;
                bool flg=recur(strt,des,sz+1,vis,adj);
                if(flg)return true;
                vis[des]=false;
            }
        }
    }
    return false;
}
int main() {
    int t;
    cin>>t;
    while(t--){
         cin>>n>>edges;
        vector<int>adj[n];
        for(int i=0;i<edges;i++){
            int from=0,to=0;
            cin>>from>>to;
            from--;
            to--;
           adj[from].push_back(to);
           adj[to].push_back(from);
        }
        vector<int>tmp;
        vector<bool>vis(n,false);
        bool flg=recur(-1,-1,0,vis,adj);
        if(flg)cout<<1<<endl;
        else cout<<0<<endl;
    }
    return 0;
}
