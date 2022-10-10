// Write a function that takes input an array of distinct
// integers and returns kth smallest in the array.

// Sample Input: 
// [10,5,2,0,7,6,4]
// k=4

// Output: 5

#include<bits/stdc++.h>
using namespace std;

int partition(vector<int> &a, int s, int e){
    int i=s-1;
    int pivot=a[e];
    for(int j=s;j<e;j++){
        if(a[j]<pivot){
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[e]);
    return i+1;
}

int quicksort(vector<int> a, int s, int e, int k){
    int p = partition(a,s,e);
    if(p==k){
        return a[p];
    }else if(k<p){
        return quicksort(a,s,p-1,k);
    }else{
        return quicksort(a,p+1,e,k);
    }
}

int main(){
    vector<int> a = {10,5,2,0,7,6,4};
    int n= a.size();
    int k=4;
    cout<<quicksort(a, 0, n-1, k);
    return 0;
}