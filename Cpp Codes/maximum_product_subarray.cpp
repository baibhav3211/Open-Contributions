// Question ->
// Given an integer array nums, find a contiguous non-empty subarray within the array that has the largest product, and return the product.
// Example -> {2, 3, -2, 4}
// Ouput -> 6

#include<bits/stdc++.h>
using namespace std;

int maxProduct(vector<int>& nums) {
        int maxi1 = INT_MIN,maxi2 = INT_MIN,p=1;
        for(int i=0;i<nums.size();i++){
            p *= nums[i];           
            maxi1 = max(maxi1,p);
            if(p == 0) p = 1;
        }
        p = 1;
        for(int i=nums.size()-1;i>=0;i--){
            p *= nums[i];
            maxi2 = max(maxi2,p);
            if(p == 0) p = 1;
        }
        return max(maxi1,maxi2);
}

int main() {
    vector<int> v = {2,3,-2,4};
    cout << maxProduct(v);
    return 0;
}