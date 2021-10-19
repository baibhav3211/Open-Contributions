#include<bits/stdc++.h>
std::mt19937 rnd(time(0));
const int N = 2e5+10;
int n,m,a[N];
std::set<int> g[N];
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;++i){
        int a,b;
        scanf("%d%d",&a,&b);
        g[a].insert(b);
        g[b].insert(a);
    }
    int ok = 0 ;
    for(int i=1;i<=(int)(1e6);++i){
        int a[6];
        for(int j=1;j<=5;++j){
            a[j] = rnd()%n+1;
        }
        int s = g[a[1]].count(a[2]),fl = 1 ;
        for(int j=1;j<=5;++j)
            for(int k=j+1;k<=5;++k){
                if(a[j]==a[k]||s!=g[a[j]].count(a[k])){
                    fl = 0;
                    break;
                }
            }
        if(fl){
            for(int i=1;i<=5;++i)
                printf("%d ",a[i]);
            ok=1;
            break;
        }
    }
    if(!ok) puts("-1");
    return 0;
}