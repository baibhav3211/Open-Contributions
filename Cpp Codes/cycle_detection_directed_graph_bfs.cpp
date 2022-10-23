#include<bits/stdc++.h>

using namespace std;

bool f(vector<int>&indegree,vector<vector<int>>&graph,int v){
    queue<int>q;
    int cnt = 0;
    for(int i=1;i<indegree.size();i++){
        if(indegree[i] == 0){
            q.push(i);
        } 
    }
    while(!q.empty()){
        int top = q.front();
        q.pop();
        cnt++;
        for(auto x:graph[top]){
            indegree[x]--;
            if(indegree[x] == 0) q.push(x);
        }
    }
    return cnt == v;
}
int main()    
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int v,e;
    cin>>v>>e;
    vector<vector<int>>graph(v+1,vector<int>());  
    rep(i,0,e){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
    }
    queue<int>q;
    vector<int>indegree(v+1,0);

    for(int i=0;i<=v;i++){
        for(auto y:graph[i])
        indegree[y]++;
    }
    //for(auto x:f(indegree,graph)) cout<<x<<" ";
    (f(indegree,graph,v) == true) ? cout<<"Cycle doesn' t exists" : cout<<"Cycle exists"; 
    return 0;
}