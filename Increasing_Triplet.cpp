#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int left = INT_MAX, right = INT_MAX;
        for(auto ele: nums){
            if(ele<=left){
                left = ele;
            }
            else if(ele > left and ele <= right){
                right = ele;
            }
            else{
                return true;
            }
        }
        return false;
    }
};
int main() {
	vector<int> nums = {4,1,2,5,6};
	Solution obj;
	if(obj.increasingTriplet(nums)){
	    cout<<"Found Increasing Triplet"<<endl;
	}
	else{
	    cout<<"Not Found Increasing Triplet"<<endl;
	}
	return 0;
}
