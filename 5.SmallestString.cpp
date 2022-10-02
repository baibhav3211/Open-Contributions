// You are given a list of n strings a1,a2,......an.You would
// like to concatenate them together in some order such that
// the resulting string would be lexicographically smallest.
// Given the list of strings, output the lexicographically
// smallest concatenation.

// Input:
// 3
// c
// cb
// cba

// Output: cbacbc

// Input: 
// 3 
// a
// ab
// aba

// Output: aabaab

#include<bits/stdc++.h>
using namespace std;

bool comp(string a, string b){
    return a+b < b+a;
}

int main(){
    string arr[] = {"a", "ab", "aba"};
    int n = 3;

    sort(arr, arr+n, comp);

    for(auto s: arr){
        cout<<s;
    }

    return 0;
}