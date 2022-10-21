// Given a sorted array of strings that is interspersed with an 
// empty strings, write a method to find the location of a 
// given string.

// Input: 
// ["ai","","","bat","", "", "car", "cat", "", "", "dog", ""]
// bat

// Output: 4

// We will use modified version of binary search. We find mid element.
// if it is empty string, we get stuck . we dont know what to do.
// so we set mid to nearest non-empty string by traversing
// in both direction.

#include <bits/stdc++.h>
using namespace std;

int sparse_search(string a[], int n, string key){
    int s=0;
    int e=n-1;
    while(s<=e){
        int mid = (s+e)/2;
        int mid_left=mid-1;
        int mid_right=mid+1;
        if(a[mid]==""){
            // update our mid to point to a nearest non  empty string
            while(1){
                if(mid_left<s and mid_right>e){
                    return -1;
                }
                else if(mid_right <=e and a[mid_right]!=""){
                    mid = mid_right;
                    break;
                }else if(mid_left >=s and a[mid_left]!=""){
                    mid = mid_left;
                    break;
                }
                mid_left--;
                mid_right++;
                
            }


        }
        if(a[mid]==key){
            return mid;
        }else if(a[mid]>key){
            e=mid-1;
        }else{
            s=mid+1;
        }
    }
    return -1;
}

int main(){
    string arr[] = {"ai","","","bat","", "", "car", "cat", "", "", "dog", ""};
    int n =12;
    string f;
    cin>>f;
    cout<<sparse_search(arr,n,f)<<endl;
    return 0;
}