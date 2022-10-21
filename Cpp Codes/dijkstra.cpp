#include<bits/stdc++.h>

using namespace std;

vector<int> dijkstra(int v, vector<vector<pair<int,int>>> &graph, int source){
    //! thing is in pq, distance is at first then is node
    //! in graph, adjacent node is first then is distance
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
    pq.push({0,source});
    vector<int> ans(v+1, INT_MAX);
    ans[source] = 0;
    while(!pq.empty()) {
        int dis = pq.top().first;
        int prev_node = pq.top().second;
        pq.pop();
        for(auto x : graph[prev_node]) {
            int next_node = x.first;
            int next_dis = x.second;
            if(ans[next_node] > dis + next_dis){
                ans[next_node] = dis + next_dis;
                pq.push({ans[next_node], next_node});
            }
        }
    }
    return ans;
}

int main()    
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int v,e;
    cin>>v>>e;
    vector<vector<pair<int,int>>>graph(v+1);   
    rep(i,0,e) {
        int u,V,w;
        cin>>u>>V>>w;
        graph[u].push_back({V,w});
        graph[V].push_back({u,w});
    }

    int source;
    cin>>source;
    for(auto x : dijkstra(v, graph, source)) cout << x << " ";
    return 0;
}