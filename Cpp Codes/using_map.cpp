#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,c;
        cin>>n>>c;
        int a[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        map<int,int> m;
        for(int i=0;i<n;i++)
        {
            m[a[i]]++;
        }
        int sum=0;
        for(auto it : m)
        {
            if(it.second<c)
            sum+=it.second;
            else
            sum+=c;
           // cout<<it.second<<" ";
        }
        cout<<sum<<endl;
    }
}