//find longest substring which contain all distinct characters
//O(n) time
//longest in "abcadbd" is bcad or cadb
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int longdis(string s)
{
    int len=0;
    int i=0;
    vector<int>prev(256,-1);
    for(int j=0;j<s.length();j++)
    {
        i=max(i,prev[s[j]]+1);
        len=max(len,j-i+1);
        prev[s[j]]=j;
    }
    return len;
}
int main()
{
string s="abcadbd";
cout<<longdis(s);
return 0;
}

