#include<bits/stdc++.h>
using namespace std;

void solve(){
    int r,c;
    cin>>r>>c;
    char a[r][c];
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>a[i][j];
        }
    }
    if(r==1 || c==1){
        bool found=false;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(a[i][j]=='^'){
                    found=true;
                    break;
                }
            }
        }
        if(found){
            cout<<"Impossible"<<endl;
        }else{
            cout<<"Possible"<<endl;
            for(int i=0;i<r;i++){
                for(int j=0;j<c;j++){
                    cout<<".";
                }
                cout<<endl;
            }
        }
    }else{
        cout<<"Possible"<<endl;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                cout<<"^";
            }
            cout<<endl;
        }

    }
}

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        cout<<"Case #"<<i+1<<":";
        solve();
    }
    return 0;
}