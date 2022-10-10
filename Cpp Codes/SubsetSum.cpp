// Given a set of non-negative integers and a value sum, determine if there is a subset of the given set with sum equal to given sum.

// Input: [10,12,15,6,19,20], sum = 16
// Output: Yes

// If yes then how many such subsets exists  


#include <bits/stdc++.h>
using namespace std;

int countSubsets(vector<int> arr, int n, int i, int X){
    //base case
    if(i==n){
        if(X==0){
            return 1;
        }
        return 0;
    }

    // recursive case
    int inc = countSubsets(arr, n, i+1, X-arr[i]);
    int exc = countSubsets(arr, n, i+1, X);
    return inc + exc;
}

int main(){
    vector<int> arr = {1,2,3,4,5};
    int X = 6;
    cout<<countSubsets(arr, arr.size(), 0, X);
    return 0;
}