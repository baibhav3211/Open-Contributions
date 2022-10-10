// Given an array containing integers, you need to count the 
// total number of inversions.

// Inversion: Two elements a[i] and a[j] form an inversion if
// a[i]>a[j] and i<j.

// Sample Input: 
// [0,5,2,3,1]  

// Sample Output: 5

#include <bits/stdc++.h>
using namespace std;

int crossInversion(vector<int> &array, int s, int e){
    int i=s;
    int m=(s+e)/2;
    int j=m+1;
    vector<int> temp;
    int count=0;
    while(i<=m and j<=e){
        if(array[i]<array[j]){
            temp.push_back(array[i]);
            i++;
        }else{
            count+=m-i+1;
            temp.push_back(array[j]);
            j++;
        }
    }
    while(i<=m){
        temp.push_back(array[i]);
        i++;
    }
    while(j<=e){
        temp.push_back(array[j]);
        j++;
    }

    int k=0;
    for(int idx=s;idx<=e;idx++){
        array[idx] = temp[k];
        k++;
    }
    return count;
}

int inversionCount(vector<int> &array, int s, int e){
    int c1,c2,ci;
    if(s < e){
        int mid = (s+e)/2;
        c1 = inversionCount(array, s, mid);
        c2 = inversionCount(array, mid+1, e);
        ci = crossInversion(array, s, e);
    } 
    return c1+c2+ci;
}

int main(){
    vector<int> arr = {10,5,};
    int s=0;
    int e = arr.size()-1;
    cout<<inversionCount(arr,s,e)<<endl;

    return 0;
}