
/*
4 5
*  *  *  *  *   
*  *  *  *  *   
*  *  *  *  *   
*  *  *  *  *   
SImple program to print the pattern of filled rectangle.
*/
#include<iostream>
using namespace std;

int main(){
    int row,col;
    cin>>row>>col;
    for(int i=1;i<=row;i++){
        for(int j=1;j<=col;j++){
            cout<<"*  ";

        }
        cout<<" "<<endl;
    }

}