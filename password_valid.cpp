#include <bits/stdc++.h>
using namespace std;

// a987 abC012 
int CheckPassword(string str, int n){
    if(n<4) return 0;
    if(str[0]-'0'>=0 && str[0]-'0'<=9) return 0;
    // bool isd = false, isc = false;
    int a=0,num=0,cap=0;
    while(a<n){
        if(str[a]==' ' || str[a] == '/'){
            return 0;
        }
        if(str[a]>=65 && str[a]<=90){
            cap++;
        }
        else if(str[a]-'0'>=0 && str[a]-'0'<=9){
            num++;
        }
        a++;
    }
    return num>0 && cap>0;
}

int main(){
    string str;
    cin>>str;
    cout<<CheckPassword(str,str.length());
    return 0;
}