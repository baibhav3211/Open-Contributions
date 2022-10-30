#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        char a[8][8];
        // vector<vector<char>> a;
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                cin>>a[i][j];
            }
        }
        // for(int i=0;i<8;i++){
        //     for(int j=0;j<8;j++){
        //         cout<<a[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        for(int i=1;i<7;i++){
            for(int j=1;j<7;j++){
                if(a[i][j]=='#'){
                    if(a[i-1][j-1]=='#' and a[i-1][j+1]=='#' and a[i+1][j-1]=='#' and a[i+1][j+1]=='#'){
                        cout<<i+1<<" "<<j+1<<endl;
                        break;
                    }
                }else{
                    continue;
                }
            }
        }
    }
    return 0;
}