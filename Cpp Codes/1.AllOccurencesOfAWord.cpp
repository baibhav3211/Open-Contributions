// Question: Find all occurrences of a word in a string.

#include <bits/stdc++.h>
using namespace std;

vector<int> allOccurencesOfAWord(string str, string word)
{
    vector<int> ans;
    int index = str.find(word);
    while(index!=-1){
        ans.push_back(index);
        index = str.find(word,index+1);
    }
    return ans;
}

int main(){
    string s;
    getline(cin, s);
    string word;
    getline(cin, word);
    auto p = allOccurencesOfAWord(s, word);
    for(auto i:p)
        cout<<i<<" ";
    return 0;
}