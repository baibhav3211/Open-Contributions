#include<bits/stdc++.h>
using namespace std;
const int INF = 1000000000;
vector<vector<pair<int, int>>> adj;

void dijkstra(int s, vector<int> & d, vector<int> & p) {
    int n = adj.size();
    d.assign(n, 100);
    p.assign(n, -1);
    vector<bool> u(n, false);

    d[s] = 0;
    for (int i = 0; i < n; i++) {
        int v = -1;
        for (int j = 0; j < n; j++) {
            if (!u[j] && (v == -1 || d[j] < d[v]))
                v = j;
        }

        if (d[v] == 100)
            break;

        u[v] = true;
        for (auto edge : adj[v]) {
            int to = edge.first;
            int len = edge.second;

            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                p[to] = v;
            }
        }
    }
}


int main(){
    int n;
    cin>>n;
    int m;
    cin>>m;
    vector<int> from(m+1);
    vector<int> to(m+1);
    vector<int> weight(m+1);
    
    for(int i=0;i<m;i++)
    {
        cin>>from[i];
    }
    for(int i=0;i<m;i++)
    {
        cin>>to[i];
    }
    for(int i=0;i<m;i++)
    {
        cin>>weight[i];
    }
    int a,b,c;
    cin>>a>>b>>c;
    for(int i=0;i<m;i++)
    {
        adj[to[i]].push_back({from[i],weight[i]});
        adj[from[i]].push_back({to[i],weight[i]});
    }
    vector<int> dis1;
    vector<int> p1;
    vector<int> p2;
    vector<int> p3;
    vector<int> dis2;
    vector<int> dis3;
    dijkstra(a,dis1,p1);
    dijkstra(b,dis2,p2);
    dijkstra(c,dis3,p3);
    int res=INT_MAX;
    int idx=-1;
    for(int i=0;i<n;i++)
    {
        if(res>dis1[i]+dis2[i]+dis3[i]);
        {
            res=dis1[i]+dis2[i]+dis3[i];
            idx=i;
        }
    }
    cout<<idx<<endl;
    
}