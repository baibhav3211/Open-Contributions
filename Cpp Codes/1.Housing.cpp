// Along one side of a road there is a sequence of vacant plots of 
// land. Each plot has a difference area(no-zero). So, the areas 
// form a sequence a[1], a[2]....

// You want to buys K acres of land to build a house. You want to
// find all segments of contiguous plots (i.e, a subsection in 
// the sequence) of whose sum is exaktly k.

// PLOTS = [1 3 2 1 4 1 3 2 1 1 2]
// k=8

// Output
// 2 5
// 4 6
// 5 9

//  O(N) time O(1) space

#include <bits/stdc++.h>
using namespace std;

void housing(vector<int> a, int n, int k){
    int i=0, j=0;
    int cs=0; // current_sum
    while(j<n){

        //expand to right
        cs+=a[j];
        j++;

        //remove elements from left till cs>sum and i<j
        while(cs>k and i<j){
            cs = cs - a[i];
            i++;
        }

        //check if any given point
        if(cs==k){
            cout<<i<<" - "<<j-1<<endl;
        }
    }
}

int main(){
    vector<int> plots = {1,3,2,1,4,1,3,2,1,1};
    int n = plots.size();
    int k = 8;
    housing(plots, n, k);
    return 0;
}