class Solution {
public:
    
    int getKth(int lo, int hi, int k) {
        vector<pair<int,int>> arr;
        vector<int> dp(3001);
        for(int i=0;i<3001;i++)
        {
            dp[i]=-1;
        }
        for(int i=lo;i<=hi;i++)
        {
            arr.push_back({i,count(i,dp)});
        }
        sort(arr.begin(),arr.end(),myfun);
        for(auto x:arr)
        {
            cout<<x.first<<" "<<x.second<<endl;
        }
        return arr[k-1].first;
    }
    static bool myfun(pair<int,int> p1,pair<int,int>p2)
    {
        if(p1.second<p2.second) return true;
        if(p1.second==p2.second)
            return (p1.first<p2.first);
        return false;
    }
    int count(int x,vector<int> &dp)
    {
        if(dp[x]!=-1) return dp[x];
        int res=0;
        while(x!=1)
        {
            if(x%2) x=3*x+1;
            else x/=2;
            res++;
        }
        dp[x]=res;
        return dp[x];
    }
    
};
