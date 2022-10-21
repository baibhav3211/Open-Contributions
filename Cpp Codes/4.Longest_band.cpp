// Question: You are given an array of numbers. You have to find longest subsequence of band of consecutive numbers.
// Return the length of the band.
//Example: arr = {9,8,4,5,6,3,2,10,18,0,1}
//Output: 7     Subsequences are:{0,1,2,3,4,5,6}, {8,9,10}, {18}
// Approach: Put each element in unordered_set then for each element find whether it is the start of the band
// or their is some element which is less than and consecutive to it. If it is start then find next consecutive 
// element , if found increase the count else ignore that.

#include <bits/stdc++.h>
using namespace std;

int longestBand(vector<int> arr){
    int n = arr.size();
    unordered_set<int> s;

    for(int x: arr){
        s.insert(x);
    }

    int ans=1;
    for(auto element: s){
        //find if their is any parent of that element
        int parent = element - 1;

        if(s.find(parent) == s.end()){
            // if no parent find next element and increase the count
            int next = element + 1;
            int count = 1;
            while(s.find(next)!=s.end()){
                next++;
                count++;
            }
            ans = max(ans, count);
        }
    }
    return ans;
}

int main(){
    vector<int> arr = {9,8,4,5,6,3,2,10,18,0,1};
    cout<<longestBand(arr)<<endl;
    return 0;
}