#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    int mat[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>mat[i][j];
        }
    }
    map<int,int> akl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            akl[mat[i][j]]++;
        }
    }
    cout<<akl[k-1]<<endl;

    return 0;
}