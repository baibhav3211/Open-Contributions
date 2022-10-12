#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    int n = s.length();
    map<string,int> m;
    for(int i=0;i<n;i++){
        m[s[i]]++;
    }

    return 0;
}
