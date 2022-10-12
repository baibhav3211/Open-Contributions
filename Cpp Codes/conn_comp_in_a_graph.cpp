// #include <bits/stdc++.h>
// using namespace std;

// const int N = 1e5+10;
// vector<int> g[N];
// bool vis[N];

// void dfs(int vertex){

//     vis[vertex] = true;
//     for(int child: g[vertex]){
//         if(vis[child]) continue;
//         dfs(child);
//     }
// }

// int main(){
//     int n,e;
//     cin>>n>>e;
//     for(int i=0;i<e;i++){
//         int x,y;
//         cin>>x>>y;
//         g[x].push_back(y);
//         g[y].push_back(x);
//     }
//     int count = 0;
//     for(int i=1;i<=n;i++){
//         if(vis[i]) continue;
//         dfs(i);
//         count++;
//     }
//     cout<<count<<endl;

//     return 0;
// }

//Connected components to store karne ke liye


#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
vector<int> g[N];
bool vis[N];

vector<vector<int>> cc;
vector<int> c_cc;

void dfs(int vertex){

    vis[vertex] = true;
    c_cc.push_back(vertex);
    for(int child: g[vertex]){
        if(vis[child]) continue;
        dfs(child);
    }
}

int main(){
    int n,e;
    cin>>n>>e;
    for(int i=0;i<e;i++){
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int count = 0;
    for(int i=1;i<=n;i++){
        if(vis[i]) continue;
        c_cc.clear();
        dfs(i);
        cc.push_back(c_cc);
        count++;
    }
    // cout<<count<<endl; 
    cout<<cc.size()<<endl;
    for(auto i: cc){
        for(int vertex: i){
            cout<<vertex<<" ";
        }
        cout<<endl;
    }

    return 0;
}