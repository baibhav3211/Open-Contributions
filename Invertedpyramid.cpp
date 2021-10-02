//A simple program to make a inverted pyramid of n height.

#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the value."<<endl;
    cin>>n;
    for(int i=n;i>=1;i--){
        for(int j=1;j<=i;j++){
            cout<<"*";
        }
    cout<<endl;
    }

}