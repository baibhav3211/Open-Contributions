#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<int>> a(n, vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>a[i][j];
            }
        }
        
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int sum=0;
                int x=i;
                int y=j;
                while(x<n and y>=0){
                    sum+=a[x][y];
                    x++;
                    y--;
                }
                x=i;
                y=j;
                while(x>=0 and y>=0){
                    sum+=a[x][y];
                    x--;
                    y--;
                }
                x=i;
                y=j;
                while(x<n and y<m){
                    sum+=a[x][y];
                    x++;
                    y++;
                }
                x=i;
                y=j;
                while(x>=0 and y<m){
                    sum+=a[x][y];
                    x--;
                    y++;
                }
                x=i;
                y=j;
                sum-=(3*a[x][y]);
                ans=max(ans,sum);
            }

        }
        cout<<ans<<endl;
    }
    return 0;
}