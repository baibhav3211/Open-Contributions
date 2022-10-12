class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& p) {
        vector<vector<int>> adj(n);
        for(int i=0;i<p.size();i++)
        {
            adj[p[i][1]].push_back(p[i][0]);
        }
        vector<int> vis(n,0);
        vector<int> self(n,0);
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            if(cycle(adj,vis,self,i)) return false;
        }
        return true;
    }
    bool cycle(vector<vector<int>> &adj,vector<int> &vis,vector<int> &self,int s)
    {
        vis[s]=1;
        self[s]=1;
        for(auto x:adj[s])
        {
            if(!vis[x])
            {
                if(cycle(adj,vis,self,x)) return true;
            }
            else
            {
                if(self[x]) return true;
            }
        }
        self[s]=0;
        return false;
    }
};
