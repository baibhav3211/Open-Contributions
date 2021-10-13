//WAP to construct a floyd's Triangle with desired height.

#include<iostream>
using namespace std;

int main(){
    int n;
    int count=1;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout<<count<<" ";
            count++;
        }
        cout<<endl;
    }
    return  0;
}