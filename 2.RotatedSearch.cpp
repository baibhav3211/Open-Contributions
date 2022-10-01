// Write a function that takes input an sorted array of distinct
// integers, which is rotated about a pivot point and finds the index
// of any given element.
// Sample input: [7,9,10,1,2,3,4,5,6]
// element = 4

// Sample Output: 6

#include <bits/stdc++.h>
using namespace std;

int rotated_search(vector<int> a, int key){

    int n = a.size();

    // lOgic
    int s = 0;
    int e = n-1;
    while(s<=e){
        int mid = (s+e)/2;
        if(a[mid] == key){
            return mid;
        }

        if(a[s]<=a[mid]){
            if(key>=a[s] and key<=a[mid]){
                e = mid-1;
            }else{
                s =  mid+1;
            }
        }else{
            if(key>=a[mid] and key<=a[e]){
                s = mid+1;
            }else{
                e = mid-1;
            }
        }
    }
    return -1;

}

int main(){

    vector<int> arr = {7,9,10,1,2,3,4,5,6};
    int key;
    cin>>key;
    cout<<rotated_search(arr, key)<<endl;
    return 0;

}