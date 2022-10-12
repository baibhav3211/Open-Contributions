// Given a ladder of n steps,you can take a jump of 1,2 or 3 at each step. Find the number of ways to climb the stair.
// N=4 
// Output = 7

#include <bits/stdc++.h>
using namespace std;

int countWays(int n){
    //base
    if(n<0){
        return 0;
    }
    if(n==0)
        return 1;
    //recursive

    return countWays(n-1) + countWays(n-2) + countWays(n-3);
}

int main(){
    int n;
    cin>>n;
    cout<<countWays(n);
    return 0;
}