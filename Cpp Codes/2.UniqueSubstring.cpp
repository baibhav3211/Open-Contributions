// Given a string, write a function to find the largest substring
// with unqiue characters(no duplicates).

// Sample input: 
// prateekbhaiya
// aabcb

// Output:
// ekbhaiy
// abc

#include <bits/stdc++.h>
using namespace std;

string unqiueSubstring(string s){
    int i=0,j=0;
    unordered_map<char, int> m;
    int window_len=0, max_length=0;
    int start = -1;
    while(j<s.length()){
        char ch = s[j];

        // if it is inside hashmap & its index>=start of the current window
        if(m.count(ch)!=0 and m[ch]>=i){
            i = m[ch]+1;  //starting new window
            window_len = j-i; //updated rem. window len excluding curr char
        }
        //update the last occ.
        m[ch] = j;
        window_len++;
        j++;

        // update max window_len at every step
        if(window_len > max_length){
            max_length = window_len;
            start = i;
        }
    }
    return s.substr(start, max_length);
}

int main(){

    string s;
    cin>>s; 
    cout<<unqiueSubstring(s)<<endl;

    return 0;
}