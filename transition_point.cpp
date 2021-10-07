#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[] = {0,0,0,1,1};
    // for(int i=0;i<4;i++){
    //     if(arr[i]!=arr[i+1]){
    //         cout<<i+1<<endl;
    //     }
    // }
    int l=0,r=n-1;
    while(l<=r){
        int mid=(l+r)/2;
        if(arr[mid]==0){
            l=mid+1;
        }else if(arr[mid]==1){
            if(mid==0 || mid>0 && arr[mid-1]==0){
                return mid;
            }
            r=mid-1;
        }
    }
    return 0;
}