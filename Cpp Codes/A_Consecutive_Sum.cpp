#include<bits/stdc++.h>
using namespace std;

int main()
{	
    int t;
    cin>>t;
    while(t--)
    {
        int n,k,index;
        cin>>n>>k;
        long long a[k][n]={0,0},m=0,sum=0;
        int j=0;
        for(int i=0;i<k;i++)
        {
            for(int j=0;j<n;j++)
           a[i][j]=0;
        }
        for(int i=0;i<n;i++)
        {
            
            int x=i%k;
            cin>>a[x][j];
            j++;
        }
        for(int i=0;i<k;i++)
        {
            for(int j=0;j<n;j++) 
            {
                if(a[i][j]>m)
                {
                    m=a[i][j];
                }
                // cout<<a[i][j]<<" ";

            // }
            }
            // cout<<endl;
            sum+=m;
            m=0;
        }    
        cout<<sum<<endl; 
    } 
}
