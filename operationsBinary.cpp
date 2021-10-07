#include <bits/stdc++.h>
using namespace std;
// 0C1A1B1C1C1B0A0
int OperationsBinaryString(string &str){
    int ans = str[0]-'0';
    for(int i=1;i<str[i]!='\0';i+=2){
        int j=i+1;
        if(str[i]=='A'){
            ans = ans & (str[j]-'0');
        }else if(str[i]=='B'){
            ans = ans | (str[j]-'0');
        }else if(str[i]=='C'){
            ans = ans ^ (str[j]-'0');
        }
    }
    return ans;
}

int main(){
    // char str[100];
    string str;
	// scanf("%s",str);
    cin>>str;
	cout<<OperationsBinaryString(str);
    return 0;
}